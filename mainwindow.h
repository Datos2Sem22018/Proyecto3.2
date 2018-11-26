#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMediaPlayer>
#include <QProgressBar>
#include <QSlider>
#include <QMessageBox>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <fstream>
#include "videoplayer.h"
#include "nodecotroller.h"
#include "vector"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void startClient();
    static int count;
    static int getCount();

private slots:
    void on_pushButton_3_clicked();
    void on_upload_clicked();
    void on_pushButton_4_clicked();
    void on_btn_Search_clicked();
    void on_pushButton_clicked();

    void on_btn_NodeContrller_clicked();

private:
    static QString video_Name;
    NodeCotroller* controller = new NodeCotroller();
    Ui::MainWindow *ui;
    VideoPlayer videoPlayer;
    NodeCotroller nodeCotroller;



};

#endif // MAINWINDOW_H
