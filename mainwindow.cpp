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
    //this->hide();
}

void MainWindow::on_upload_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a File", "", "Video File (*.*)");
    std::string path = filename.toStdString();
    std::ifstream ifs(path);
    float chunkSize = this->controller->getManager()->GetFileSize(path) / 4000000;
    std::vector<std::string> vecFilenames;
    this->controller->getManager()->split(path, ifs, chunkSize, vecFilenames);
    if (count == 0) {
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk1.bin", "/home/zuckerberg/Escritorio/Disk 1/A/chunk1.bin");
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk2.bin", "/home/zuckerberg/Escritorio/Disk 2/A/chunk2.bin");
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk3.bin", "/home/zuckerberg/Escritorio/Disk 3/A/chunk3.bin");
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk4.bin", "/home/zuckerberg/Escritorio/Disk 4/A/chunk4.bin");
        count++;
    }
    else if (count == 1) {
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk1.bin", "/home/zuckerberg/Escritorio/Disk 1/B/chunk1.bin");
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk2.bin", "/home/zuckerberg/Escritorio/Disk 2/B/chunk2.bin");
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk3.bin", "/home/zuckerberg/Escritorio/Disk 3/B/chunk3.bin");
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk4.bin", "/home/zuckerberg/Escritorio/Disk 4/B/chunk4.bin");
        count++;
    } else if (count == 2) {
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk1.bin", "/home/zuckerberg/Escritorio/Disk 1/C/chunk1.bin");
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk2.bin", "/home/zuckerberg/Escritorio/Disk 2/C/chunk2.bin");
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk3.bin", "/home/zuckerberg/Escritorio/Disk 3/C/chunk3.bin");
        this->controller->getManager()->copy_file("/home/zuckerberg/build-OdysseyMediaPlayer-Desktop_Qt_5_9_1_GCC_64bit-Debug/chunk4.bin", "/home/zuckerberg/Escritorio/Disk 4/C/chunk4.bin");
        count++;
    }
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
    if (count == 1) {
        std::string filenameAfter = "Test1.mp4";
        std::ofstream ofs(filenameAfter, std::ios::binary);
        std::vector<std::string> vecFilenames2;
        std::string paths[4] = {"/home/zuckerberg/Escritorio/Disk 1/A/chunk1.bin", "/home/zuckerberg/Escritorio/Disk 2/A/chunk2.bin", "/home/zuckerberg/Escritorio/Disk 3/A/chunk3.bin", "/home/zuckerberg/Escritorio/Disk 4/A/chunk4.bin"};
        for (int i = 0; i < 4; ++i) {
            vecFilenames2.push_back(paths[i]);
        }
        this->controller->getManager()->join(vecFilenames2, ofs);
        std::cout << "Archivos combinados en el original" << std::endl;
    }
    else if (count == 2) {
        std::string filenameAfter = "Test2.mp4";
        std::ofstream ofs(filenameAfter, std::ios::binary);
        std::vector<std::string> vecFilenames2;
        std::string paths[4] = {"/home/zuckerberg/Escritorio/Disk 1/B/chunk1.bin", "/home/zuckerberg/Escritorio/Disk 2/B/chunk2.bin", "/home/zuckerberg/Escritorio/Disk 3/B/chunk3.bin", "/home/zuckerberg/Escritorio/Disk 4/B/chunk4.bin"};
        for (int i = 0; i < 4; ++i) {
            vecFilenames2.push_back(paths[i]);
        }
        this->controller->getManager()->join(vecFilenames2, ofs);
        std::cout << "Archivos combinados en el original" << std::endl;
    }
    else if (count == 3) {
        std::string filenameAfter = "Test3.mp4";
        std::ofstream ofs(filenameAfter, std::ios::binary);
        std::vector<std::string> vecFilenames2;
        std::string paths[4] = {"/home/zuckerberg/Escritorio/Disk 1/C/chunk1.bin", "/home/zuckerberg/Escritorio/Disk 2/C/chunk2.bin", "/home/zuckerberg/Escritorio/Disk 3/C/chunk3.bin", "/home/zuckerberg/Escritorio/Disk 4/C/chunk4.bin"};
        for (int i = 0; i < 4; ++i) {
            vecFilenames2.push_back(paths[i]);
        }
        this->controller->getManager()->join(vecFilenames2, ofs);
        std::cout << "Archivos combinados en el original" << std::endl;
    }
}

void MainWindow::on_btn_NodeContrller_clicked()
{
        nodeCotroller.show();

}
