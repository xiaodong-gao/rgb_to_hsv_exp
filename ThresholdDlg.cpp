#include "ThresholdDlg.h"
#include "ui_thresholddlg.h"

ThresholdDlg::ThresholdDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThresholdDlg)
{
    ui->setupUi(this);

    ui->horizontalSliderMinThreshold->setRange(0, 255);
    ui->horizontalSliderMaxThreshold->setRange(0, 255);
    ui->spinBoxMinThreshold->setRange(0, 255);
    ui->spinBoxMaxThreshold->setRange(0, 255);

    ui->horizontalSliderMinThreshold->setValue(100);
    ui->horizontalSliderMaxThreshold->setValue(255);

}

ThresholdDlg::~ThresholdDlg()
{
    delete ui;
}

void ThresholdDlg::on_btnSelect_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "打开图像",
                                                    "",

                                                    "Images (*.png *.xpm *.jpg *.jpeg *.bmp)");
    ui->lineEditImagePath->setText(tr(""));
    if (!fileName.isEmpty()) {
        // 加载并显示图像
        QImage image(fileName);
        if (!image.isNull()) {
            ui->lineEditImagePath->setText(fileName);
            ui->labelImage->setPixmap(QPixmap::fromImage(image).scaled(ui->labelImage->size(), Qt::KeepAspectRatio));
            ui->labelImage->update();
        }
        else{
            QMessageBox msgBox;
            msgBox.setText("load image is empty.");
            msgBox.exec();
        }
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("load image is empty.");
        msgBox.exec();
        ui->lineEditImagePath->setText(tr(""));
    }
}

void ThresholdDlg::on_horizontalSliderMinThreshold_valueChanged(int value)
{
    ui->spinBoxMinThreshold->setValue(value);
}

void ThresholdDlg::on_horizontalSliderMaxThreshold_valueChanged(int value)
{
    ui->spinBoxMaxThreshold->setValue(value);
}

void ThresholdDlg::on_spinBoxMinThreshold_valueChanged(int value)
{
    ui->horizontalSliderMinThreshold->setValue(value);
    update_image();
}

void ThresholdDlg::on_spinBoxMaxThreshold_valueChanged(int value)
{
    ui->horizontalSliderMaxThreshold->setValue(value);
    update_image();
}

void ThresholdDlg::update_image(){
     QString image_path = ui->lineEditImagePath->text();
     cv::Mat srcImage = cv::imread(image_path.toStdString().c_str(), cv::IMREAD_GRAYSCALE);
     if (srcImage.empty()) {
         // 图像尺寸和类型
         int width = 640;
         int height = 480;
         int type = CV_8UC1; // 8位无符号整数，1个通道（灰度图像）
         // 创建黑色灰度图像
         cv::Mat blackImage(height, width, type, cv::Scalar(0));
         QImage img(blackImage.data, blackImage.cols, blackImage.rows, blackImage.step, QImage::Format_Grayscale8);
         ui->labelImage->setPixmap(QPixmap::fromImage(img).scaled(ui->labelImage->size(), Qt::KeepAspectRatio));
         ui->labelImage->update();
         return;
     }

     // 应用阈值操作
     int min_threshold_value = ui->horizontalSliderMinThreshold->value();
     int max_threshold_value = ui->horizontalSliderMaxThreshold->value();
     cv::Mat binaryImage;
     cv::threshold(srcImage, binaryImage, min_threshold_value, max_threshold_value, cv::THRESH_BINARY);
     QImage img(binaryImage.data, binaryImage.cols, binaryImage.rows, binaryImage.step, QImage::Format_Grayscale8);
     ui->labelImage->setPixmap(QPixmap::fromImage(img).scaled(ui->labelImage->size(), Qt::KeepAspectRatio));
     ui->labelImage->update();
}


