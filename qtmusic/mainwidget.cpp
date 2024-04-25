#include "mainwidget.h"

#include <QFont>
#include <QPalette>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(tr("一个空的QT项目"));

    label = new QLabel(this);
    label->setText(tr("Hello world!"));
    label->setGeometry(200, 120, 300, 100);

    /* set text size */
    QFont ft;
    ft.setPointSize(20);
    label->setFont(ft);

    /* set text color */
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    label->setPalette(pa);
}
