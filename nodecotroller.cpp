#include "nodecotroller.h"
#include "mainwindow.h"
#include "ui_nodecotroller.h"
#include <QWidget>
#include <iostream>

NodeCotroller::NodeCotroller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NodeCotroller)
{
    ui->setupUi(this);
    this->raid = new Raid5();
    this->manager = new FileManagement();
    this->fillPBars();
}

NodeCotroller::~NodeCotroller()
{
    delete ui;
}

FileManagement* NodeCotroller::getManager() {
    return this->manager;
}

void NodeCotroller::fillPBars(){


    ui->cb_disk1->setChecked(true);
    ui->cb_Disk2->setChecked(true);
    ui->cb_Disk3->setChecked(true);
    ui->cb_Disk4->setChecked(true);

    ui->pb_disk1->setMaximum(60);
    ui->pb_disk1_2->setMaximum(60);
    ui->pb_Disk3->setMaximum(60);
    ui->pb_Disk4->setMaximum(60);


    if (MainWindow::getCount()==1){
        ui->pb_disk1->setValue(15);
        ui->pb_disk1_2->setValue(15);
        ui->pb_Disk3->setValue(15);
        ui->pb_Disk4->setValue(15);
    }else if(MainWindow::getCount()==2){
        ui->pb_disk1->setValue(30);
        ui->pb_disk1_2->setValue(30);
        ui->pb_Disk3->setValue(30);
        ui->pb_Disk4->setValue(30);
    }else if(MainWindow::getCount()==3){
        ui->pb_disk1->setValue(45);
        ui->pb_disk1_2->setValue(45);
        ui->pb_Disk3->setValue(45);
        ui->pb_Disk4->setValue(45);
    }

}
