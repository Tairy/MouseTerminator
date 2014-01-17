#ifndef MAP_H
#define MAP_H

#include <QMainWindow>

namespace Ui {
class Map;
}

class Map : public QMainWindow
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = 0);
    ~Map();
    QPoint getWinPos();

private:
    Ui::Map *mui;
};

#endif // MAP_H
