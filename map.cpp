#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QMainWindow(parent),
    mui(new Ui::Map)
{
    mui->setupUi(this);
}

Map::~Map()
{
    delete mui;
}

QPoint Map::getWinPos(){
    return mapToGlobal(mui -> centralwidget -> pos());
}
