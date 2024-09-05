#ifndef MIMAGEAUGMENTATION_H
#define MIMAGEAUGMENTATION_H

#include <QString>
#include <vector>
#include <QDir>
#include <QDebug>
#include <QObject>
#include <QString>
#include <iostream>
#include "opencv2/opencv.hpp"

class MImageAugmentation : public QObject{
    Q_OBJECT
public:
    explicit MImageAugmentation(QObject* parent = nullptr);
    ~MImageAugmentation();
    void process_image(const QString &process_image_path,std::vector<float> vec_exp,std::vector<QString> vec_sub_folder_path, int min_threshold_value, int max_threshold_value );
    void modify_bright(cv::Mat& src_img, int min_threshold_value, int max_threshold_value, int bright_value);
signals:
    void send_msg_mainwindow(const QString& str);
};

#endif // MIMAGEAUGMENTATION_H
