#ifndef NODECOTROLLER_H
#define NODECOTROLLER_H
#include <QMainWindow>
#include "raid5.h"
#include "linkedlist.h"
#include "filemanagement.h"
#include "video.h"

namespace Ui {
class NodeCotroller;
}

class NodeCotroller : public QMainWindow
{
    Q_OBJECT

public:
    explicit NodeCotroller(QWidget *parent = nullptr);
    ~NodeCotroller();
    static int startNodeController(int argc, char** argv);
    FileManagement* getManager();

private:
    Ui::NodeCotroller *ui;
    Raid5* raid;
    FileManagement* manager;
};

#endif // NODECOTROLLER_H
