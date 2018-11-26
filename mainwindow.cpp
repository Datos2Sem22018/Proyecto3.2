#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <csignal>
#include <iostream>
using namespace std;
#include <QApplication>
#include <QFileDialog>
#include <QVideoWidget>

static QString videoName;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    videoPlayer.show();
    this->hide();
}

void MainWindow::on_upload_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a File", "", "Video File (*.*)");
    std::string path = filename.toStdString();
    std::ifstream ifs(path);
    float chunkSize = this->controller->getManager()->GetFileSize(path) / 3000000;
    std::vector<std::string> vecFilenames;
    this->controller->getManager()->split(path, ifs, chunkSize, vecFilenames);
    this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk1.bin", "/home/zuckerberg/Escritorio/Disk 1/A/chunk1.bin");
    this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk2.bin", "/home/zuckerberg/Escritorio/Disk 2/A/chunk2.bin");
    this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk3.bin", "/home/zuckerberg/Escritorio/Disk 3/A/chunk3.bin");
}

void MainWindow::on_pushButton_4_clicked()
{
    QString text = ui->listWidget->currentItem()->text();
    ui->title->setText(text);
}

void MainWindow::on_btn_Search_clicked()
{
    QString str = ui->text_Search->text();
    ui->listWidget->clear();
    if(str!=""){
        ui->text_Search->setText("");

        for(int i = 0; i< 30; i++){
            ui->listWidget->addItem(str);
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    std::string filenameAfter = "Test.mp4";
    std::ofstream ofs(filenameAfter, std::ios::binary);
    std::vector<std::string> vecFilenames2;
    std::string paths[3] = {"/home/zuckerberg/Escritorio/Disk 1/A/chunk1.bin", "/home/zuckerberg/Escritorio/Disk 2/A/chunk2.bin", "/home/zuckerberg/Escritorio/Disk 3/A/chunk3.bin"};
    for (int i = 0; i < 3; ++i) {
        vecFilenames2.push_back(paths[i]);
    }
    this->controller->getManager()->join(vecFilenames2, ofs);
    std::cout << "Archivos combinados en el original" << std::endl;
}
