#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <memory>
#include <filesystem>
#include "MImageAugmentation.h"
#include "ThresholdDlg.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private slots:
    void on_btnSelectFolderPath_clicked();
    void on_btnRun_clicked();
    QString new_root_folder_path();
    QString new_sub_folder_path(QString root_folder_path, QString sub_floder_name);
    void on_btnSelectResultFolderPath_clicked();
    void on_action_settings_threshold_triggered();
    void on_lineEditMinThreshold_textChanged(const QString &text);
    void on_lineEditMaxThreshold_textEdited(const QString &text);
public slots:
    void recv_msg_from_MImageAugmentation(const QString& str);
private:
    Ui::MainWindow *ui;
    QString root_folder_path_;
    QString result_folder_path_;
    std::vector<float> vec_exp_value_;
    std::vector<QString> vec_sub_folder_path_;
    int min_threshold_value,max_threshold_value;
    std::unique_ptr<MImageAugmentation> image_augmentation_;
};
#endif // MAINWINDOW_H
