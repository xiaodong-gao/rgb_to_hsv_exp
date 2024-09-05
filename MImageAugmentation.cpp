#include "MImageAugmentation.h"

MImageAugmentation::MImageAugmentation(QObject* parent) :
    QObject(parent)
{

}

MImageAugmentation::~MImageAugmentation()
{

}


void MImageAugmentation::process_image(const QString &process_image_path, std::vector<float> vec_exp,std::vector<QString> vec_sub_folder_path, int min_threshold_value, int max_threshold_value)
{
    // 检查路径是否存在
    QDir dir(process_image_path);
    if (!dir.exists()) {
        //qDebug() << "The specified folder does not exist.";
        //return -1;
    }
    // 2. 设置过滤器，获取所有图像文件
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp" << "*.gif";
    // 获取符合过滤器的文件列表
    QStringList imageFiles = dir.entryList(filters, QDir::Files);

    // 3. 输出文件路径
    if (imageFiles.isEmpty()) {
        //qDebug() << "No image files found in the specified folder.";
    }
    else {
        for (const QString& fileName : imageFiles) {
            QString filePath = dir.absoluteFilePath(fileName);
            cv::Mat src_img = cv::imread(filePath.toStdString().c_str(), cv::IMREAD_UNCHANGED);

            for (int j = 0; j < vec_exp.size(); j++) {
                //int brightness = 10; // 可以调整为正值增加亮度，负值降低亮度

                // 创建一个空白矩阵，与原始图像尺寸相同
                //cv::Mat brightenedImage;
                // 修改亮度，image + brightness
                //src_img.convertTo(brightenedImage, -1, 1, vec_exp[j]);
                modify_bright(src_img, min_threshold_value, max_threshold_value, vec_exp[j]);
                QFileInfo fileInfo(filePath);
                QString fileName = fileInfo.fileName();
                QStringList list = fileName.split('.');
                QString save_result_image_path = vec_sub_folder_path[j] + "/" + list[0] + "." + list[1];
                cv::imwrite(save_result_image_path.toStdString().c_str(), src_img);
                QString str = "process Brightness value is " + QString::number(vec_exp[j]) + " save result is " + save_result_image_path;
                emit send_msg_mainwindow(str);
            }
        }
    }
}

void MImageAugmentation::modify_bright(cv::Mat& src_img, int min_threshold_value, int max_threshold_value, int bright_value) {
    cv::Mat gray;
    if (src_img.channels() == 3) {
        cv::cvtColor(src_img, gray, cv::COLOR_BGR2GRAY);
    }
    else {
        gray = src_img;
    }

    cv::Mat binary;
    cv::threshold(gray, binary, min_threshold_value, max_threshold_value, cv::THRESH_BINARY);
    // 3. 分割连通区域 提取连通区域 增加前景区域的亮度
    cv::Mat labels;
    int num_labels = cv::connectedComponents(binary, labels, 8, CV_32S);
    for (int label = 1; label < num_labels; label++) {
        for (int row = 0; row < labels.rows; ++row) {
            for (int col = 0; col < labels.cols; ++col) {
                if (labels.at<int>(row, col) == label) {
                    cv::Vec3b pixel = src_img.at<cv::Vec3b>(row, col);
                    // 分别处理 BGR 通道，增加亮度
                    for (int c = 0; c < src_img.channels(); c++) {
                        int new_value = pixel[c] + bright_value;
                        // 限制新值在 0-255 之间
                        new_value = std::min(std::max(new_value, 0), 255);
                        src_img.at<cv::Vec3b>(row, col)[c] = new_value;
                    }
                }
            }
        }
    }


}


