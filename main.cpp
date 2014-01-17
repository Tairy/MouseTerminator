#include "camera.h"
#include "map.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Camera w;
    w.show();
    return a.exec();
}
