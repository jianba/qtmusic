#include "musiclist.h"
#include "musiclistwidget.h"

#include <QCoreApplication>
#include <QProgressDialog>
#include <QDesktopServices>
#include <QtSql>
#include <algorithm>
#include <QtDebug>


MusicList::MusicList(const QList<QUrl> &urls, QString iname)
{

    addMusic(urls);
    iname;
}


void MusicList::addMusic(const QList<QUrl> &urls)
{
    //实测这里耗时较长，所以添加一个进度显示对话框
    QProgressDialog proDialog(u8"添加进度",u8"取消",0,urls.size());
    proDialog.setMinimumSize(350,150);
    proDialog.setWindowModality(Qt::WindowModal);
    proDialog.setWindowTitle("添加中...请稍后");
    proDialog.show();
    int x=0;
    foreach (QUrl i, urls) {
        x++;
        proDialog.setValue(x);
        //过滤Url的类型
        QMimeDatabase db;
        QMimeType mime = db.mimeTypeForFile(i.toLocalFile());
        if(mime.name()!="audio/mpeg"&&mime.name()!="audio/flac"){
            continue;
        }
        //剩下的符合类型
        music.push_back(Music(i));
        if(sql_flag){
            music[music.size()-1].insertSQL(name);
             qDebug() << "music[music.size()-1].insertSQL(name) ";
        }
        if(proDialog.wasCanceled()) break;

    }

    qDebug() << "222 ";
}

void MusicList::addMusic(const Music &iMusic)
{
    music.push_back(iMusic);
    if(sql_flag){
        music[music.size()-1].insertSQL(name);
    }
}

Music MusicList::getMusic(int pos)
{
    return music[pos];
}

void MusicList::addToPlayList(QMediaPlaylist *playlist)
{
    for(auto i=music.begin();i!=music.end();i++){
        playlist->addMedia(i->getUrl());
    }
}

void MusicList::addToListWidget(MusicListWidget *listWidget)
{
    foreach(const Music &i,music){
        QListWidgetItem *item = new QListWidgetItem;
        item->setIcon(listWidget->getIcon());
        item->setText(i.getInfo());
        listWidget->addItem(item);
    }

    qDebug() << "----- addToListWidget ";
}

void MusicList::removeMusic(int pos)
{
    pos;
//    if(sql_flag){
//        remove_SQL_all();
//        int i=0;
//        for(auto it=music.begin();it!=music.end();){
//            if(i==pos){
//                it= music.erase(it);
//                break;
//            }
//            else{
//                it++;
//            }
//            i++;

//        }
//        insert_SQL_all();
//    }else{
//        int i=0;
//        for(auto it=music.begin();it!=music.end();){
//            if(i==pos){
//                it= music.erase(it);
//                break;
//            }
//            else{
//                it++;
//            }
//            i++;

//        }
//    }
}

void MusicList::read_fromSQL()
{
    QSqlQuery sql_query;
    QString select_sql = "select url, author, title, duration, albumTitle, audioBitRate from MusicInfo where name = ?";
    sql_query.prepare(select_sql);
    sql_query.addBindValue(name);
    if(sql_query.exec())
    {
        while(sql_query.next())
        {
            Music tempMusic;
            tempMusic.url=QUrl(sql_query.value(0).toString());
            tempMusic.author=sql_query.value(1).toString();
            tempMusic.title=sql_query.value(2).toString();
            tempMusic.duration=sql_query.value(3).toLongLong();
            tempMusic.albumTitle=sql_query.value(4).toString();
            tempMusic.audioBitRate=sql_query.value(5).toInt();
            music.push_back(tempMusic);
        }
    }

    qDebug() << "read_fromSQL";
}
