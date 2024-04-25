#include <QApplication>
#include "mainwidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWidget widget;
//    widget.resize(640, 360);
    widget.show();

    return app.exec();
}
