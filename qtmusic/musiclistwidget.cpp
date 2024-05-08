#include "musiclistwidget.h"
#include <QDebug>
//#include "ui_MusicListDialog.h"

MusicListWidget::MusicListWidget(QWidget *parent)
    :QListWidget (parent)
{

}

void MusicListWidget::refresh()
{
    clear();//先清空
    musicList.addToListWidget(this);

    qDebug() << "MusicListWidget::refresh()";
}
