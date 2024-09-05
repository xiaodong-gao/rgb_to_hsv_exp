#ifndef THRESHOLDDLG_H
#define THRESHOLDDLG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <opencv2/opencv.hpp>

namespace Ui {
class ThresholdDlg;
}

class ThresholdDlg : public QDialog{
    Q_OBJECT
public:
    explicit ThresholdDlg(QWidget *parent = nullptr);
    ~ThresholdDlg();
    void update_image();
private slots:
    void on_horizontalSliderMinThreshold_valueChanged(int value);
    void on_horizontalSliderMaxThreshold_valueChanged(int value);
    void on_spinBoxMinThreshold_valueChanged(int value);
    void on_spinBoxMaxThreshold_valueChanged(int value);
    void on_btnSelect_clicked();
private:
    Ui::ThresholdDlg *ui;
};

#endif // THRESHOLDDLG_H
