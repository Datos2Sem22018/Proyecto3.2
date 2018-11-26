#include "nodecotroller.h"
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

    ui->pb_disk1->setMaximum(60);
    ui->pb_disk1_2->setMaximum(60);
    ui->pb_Disk3->setMaximum(60);
    ui->pb_Disk4->setMaximum(60);

    ui->pb_disk1->setValue(15);
    ui->pb_disk1_2->setValue(15);
    ui->pb_Disk3->setValue(15);
    ui->pb_Disk4->setValue(15);

}
