#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // ��ȡ��Ļ�ֱ���
    QDesktopWidget desktop;
    QRect screenGeometry = desktop.screenGeometry();
    int width = screenGeometry.width() / 2;
    int height = screenGeometry.height() / 2;
    w.resize(width, height);
    int x = (screenGeometry.width() - w.width()) / 2;
    int y = (screenGeometry.height() - w.height()) / 2;
    // �ƶ����ڵ���Ļ����
    w.move(x, y);
    w.show();
    return a.exec();
}
