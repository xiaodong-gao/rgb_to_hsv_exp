#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Corrected Brightness");
    setWindowIcon(QIcon("./Icon/Brightness.png"));
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    image_augmentation_ = std::make_unique<MImageAugmentation>();
    QObject::connect(image_augmentation_.get(), &MImageAugmentation::send_msg_mainwindow, this, &MainWindow::recv_msg_from_MImageAugmentation);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSelectFolderPath_clicked()
{
    // 打开选择文件夹对话框
    root_folder_path_ = QFileDialog::getExistingDirectory(this,
                               "Select Folder",   // 对话框标题
                               "",                // 默认路径
                               QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!root_folder_path_.isEmpty()) {
       //qDebug() << "Selected Folder:" << root_folder_path_;
        ui->lineEditFolderPath->setText(root_folder_path_);
    }
    else {
        //qDebug() << "No folder selected.";
        ui->lineEditFolderPath->setText((""));
        root_folder_path_ = "";
    }
    QString str = "select process image floder is :" + root_folder_path_;
    ui->listWidget->addItem(str);
    ui->listWidget->update();
}

void MainWindow::on_btnSelectResultFolderPath_clicked()
{
    result_folder_path_ = QFileDialog::getExistingDirectory(this,
                               "Select Folder",   // 对话框标题
                               "",                // 默认路径
                               QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!result_folder_path_.isEmpty()) {
       //qDebug() << "Selected Folder:" << root_folder_path_;
        ui->lineEditResultFolderPath->setText(result_folder_path_);
    }
    else {
        //qDebug() << "No folder selected.";
        ui->lineEditResultFolderPath->setText((""));
        result_folder_path_ = "";
    }
    QString str = "select result save image floder is :" + result_folder_path_;
    ui->listWidget->addItem(str);
    ui->listWidget->update();
}


QString MainWindow::new_root_folder_path() {
    QString current_save_images_path;
    if(result_folder_path_.isEmpty()){
        current_save_images_path = QDir::currentPath() + "/result_images";
        QDir dir;
        //检查路径是否存在
        if (!dir.exists(current_save_images_path)) {
            //创建新文件夹
            if (dir.mkpath(current_save_images_path)) {
                //qDebug() << "Folder created successfully:" << newFolderPath;
            }
            else {
                //qDebug() << "Failed to create folder:" << newFolderPath;
            }
        }
        else {
            //qDebug() << "Folder already exists:" << newFolderPath;
        }
    }
    else{
        current_save_images_path = result_folder_path_;
    }

    return current_save_images_path;
}

QString MainWindow::new_sub_folder_path(QString root_folder_path, QString sub_floder_name){
    QString current_save_images_path = root_folder_path + "/" + sub_floder_name;
    QDir dir;
    //检查路径是否存在
    if (!dir.exists(current_save_images_path)) {
        //创建新文件夹
        if (dir.mkpath(current_save_images_path)) {
            //qDebug() << "Folder created successfully:" << newFolderPath;
        }
        else {
            //qDebug() << "Failed to create folder:" << newFolderPath;
        }
    }
    else {
        //qDebug() << "Folder already exists:" << newFolderPath;
    }
    return current_save_images_path;
}

void MainWindow::on_btnRun_clicked()
{

    ui->listWidget->addItem(tr("run process"));
    //parse distributing Data
    QString text = ui->lineEditExposureValue->text();
    vec_exp_value_.clear();
    vec_sub_folder_path_.clear();
    std::stringstream ss(text.toStdString());
    std::string item;
    // 使用 std::getline 分割字符串
    while (std::getline(ss, item, ',')) {
        vec_exp_value_.push_back(std::stof(item));
    }
    QString root_path = new_root_folder_path();
    for (int i = 0; i < vec_exp_value_.size(); i++) {
        vec_sub_folder_path_.push_back(new_sub_folder_path(root_path, QString::number(vec_exp_value_[i])));
    }
    image_augmentation_->process_image(root_folder_path_,vec_exp_value_, vec_sub_folder_path_);
   
}

void MainWindow::recv_msg_from_MImageAugmentation(const QString& str) {
    ui->listWidget->addItem(str);
    ui->listWidget->update();
}




void MainWindow::on_lineEditResultFolderPath_textEdited(const QString &arg1)
{

}
