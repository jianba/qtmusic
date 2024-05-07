#include "musiclist.h"
#include "musiclistwidget.h"

#include <QCoreApplication>
#include <QProgressDialog>
#include <QDesktopServices>
#include <QtSql>
#include <algorithm>


MusicList::MusicList(const QList<QUrl> &urls, QString iname)
{

    urls;
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
        }
        if(proDialog.wasCanceled()) break;
    }
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
    listWidget;
//    foreach(const Music &i,music){
//        QListWidgetItem *item = new QListWidgetItem;
//        item->setIcon(listWidget->getIcon());
//        item->setText(i.getInfo());
//        listWidget->addItem(item);
//    }
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


