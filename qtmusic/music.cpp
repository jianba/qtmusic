#include "music.h"
#include <QMediaPlayer>
#include <QCoreApplication>
#include <QMessageBox>
#include <QtSql>

Music::Music(QUrl iurl)
{
    url=iurl;
    refreshInfo();
}

void Music::refreshInfo()
{
    QMediaPlayer tempPlayer;
    tempPlayer.setMedia(url);
    //元数据的解析需要时间，所以这里需要循环等待（但同时需要保持Qt事件处理机制在运行）
    while(!tempPlayer.isMetaDataAvailable()){
        QCoreApplication::processEvents();
    }
    QStringList list=tempPlayer.availableMetaData();//调试时查看有哪些元数据可用
    if(tempPlayer.isMetaDataAvailable()){
        //歌曲信息
        author = tempPlayer.metaData(QStringLiteral("Author")).toStringList().join(",");
        //author = tempPlayer.metaData(QStringLiteral("Author")).toString(); //查手册发现，这里返回的是StringList
        //author=tempPlayer.metaData(QStringLiteral("ContributingArtist")).toStringList().join(","); //另一种元数据
        title = tempPlayer.metaData(QStringLiteral("Title")).toString();
        albumTitle = tempPlayer.metaData(QStringLiteral("AlbumTitle")).toString();
        audioBitRate = tempPlayer.metaData(QStringLiteral("AudioBitRate")).toInt();
        duration=tempPlayer.duration();
    }
}

void Music::insertSQL(const QString &name)
{
    QSqlQuery sql_query;
    QString insert_sql = "insert into MusicInfo values (?, ?, ?, ?, ?, ?, ?)";
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(name);
    sql_query.addBindValue(url.toString());
    sql_query.addBindValue(author);
    sql_query.addBindValue(title);
    sql_query.addBindValue(duration);
    sql_query.addBindValue(albumTitle);
    sql_query.addBindValue(audioBitRate);
    sql_query.exec();
}

QString Music::getInfo() const
{
//    return author+" - "+title+" ["+formatTime(duration)+"]";
    return author+" - "+title;
}
