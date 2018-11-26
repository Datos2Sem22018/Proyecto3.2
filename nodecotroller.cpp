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
}

NodeCotroller::~NodeCotroller()
{
    delete ui;
}

FileManagement* NodeCotroller::getManager() {
    return this->manager;
}
