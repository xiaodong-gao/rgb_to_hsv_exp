#include "MImageAugmentation.h"

MImageAugmentation::MImageAugmentation(QObject* parent) :
    QObject(parent)
{

}

MImageAugmentation::~MImageAugmentation()
{

}


void MImageAugmentation::process_image(const QString &process_image_path, std::vector<float> vec_exp,std::vector<QString> vec_sub_folder_path)
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
                cv::Mat brightenedImage;
                // 修改亮度，image + brightness
                src_img.convertTo(brightenedImage, -1, 1, vec_exp[j]);
                QFileInfo fileInfo(filePath);
                QString fileName = fileInfo.fileName();
                QStringList list = fileName.split('.');
                QString save_result_image_path = vec_sub_folder_path[j] + "/" + list[0] + "." + list[1];
                cv::imwrite(save_result_image_path.toStdString().c_str(), brightenedImage);
                QString str = "process Brightness value is " + QString::number(vec_exp[j]) + " save result is " + save_result_image_path;
                emit send_msg_mainwindow(str);
            }
        }
    }
}

void MImageAugmentation::extrct_blob(const cv::Mat &img){
    //cv::Mat img = cv::imread("image.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat binaryImg;
    cv::threshold(img, binaryImg, 128, 255, cv::THRESH_BINARY);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binaryImg, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (size_t i = 0; i < contours.size(); i++) {
        double area = cv::contourArea(contours[i]);
        if (area > 100) {
            cv::drawContours(img, contours, static_cast<int>(i), cv::Scalar(0, 255, 0), 2);
        }
    }

    cv::imshow("Blob Detection", img);
    cv::waitKey(0);
}

