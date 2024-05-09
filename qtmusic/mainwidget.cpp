#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "musiclistdialog.h"
#include "musiclist.h"
#include "music.h"

#include <QFileDialog>
#include <QStandardPaths>
#include <QtSql>
#include <QMessageBox>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    init_play();

    //数据库初始化
    init_sqlite();
    init_musicList();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::init_play()
{
    //播放器初始化
    player= new QMediaPlayer(this);
    playlist=new QMediaPlaylist;
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
    //连接槽与信号
//    connect(ui->positionSlider, &QAbstractSlider::valueChanged, this, &MainWidget::setPosition);
//    connect(player, &QMediaPlayer::positionChanged, this, &MainWidget::updatePosition);
//    connect(player, &QMediaPlayer::durationChanged, this, &MainWidget::updateDuration);
//    connect(player, &QMediaPlayer::metaDataAvailableChanged, this, &MainWidget::updateInfo);
//    connect(player, &QMediaPlayer::stateChanged, this, &MainWidget::updatePlayBtn);
}

void MainWidget::init_sqlite()
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("Music.db");
        database.setUserName("chaosfish");
        database.setPassword("123456");
        if (!database.open())
        {
            QMessageBox::critical(this,"无法打开数据库文件：Music.db",database.lastError().databaseText());
            exit(-1);
        }
    }
    //检查两个表是否存在，不存在则创建不存在的表
    QSqlQuery query;
    query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("MusicInfo"));
    if(query.next()){
        if(query.value(0).toInt()==0){
            QSqlQuery sql_query;
            //QString create_sql = "create table MusicInfo (id int primary key, name varchar(30), url varchar(200), author varchar(50), title varchar(50), duration bigint, albumTitle varchar(50), audioBitRate int)";
            QString create_sql = "create table MusicInfo (name varchar(30), url varchar(200), author varchar(50), title varchar(50), duration bigint, albumTitle varchar(50), audioBitRate int)";
            sql_query.prepare(create_sql);
            sql_query.exec();
        }
    }
    QSqlQuery query2;
    query2.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("MusicLists"));
    if(query2.next()){
        if(query2.value(0).toInt()==0){
            QSqlQuery sql_query;
            QString create_sql = "create table MusicLists (name varchar(30))";
            sql_query.prepare(create_sql);
            sql_query.exec();
        }
    }
}

void MainWidget::init_musicList()
{
    //本地音乐 初始化
    ui->localMusicWidget->musicList.setName("LocalMusic");
    ui->localMusicWidget->musicList.read_fromSQL();
    ui->localMusicWidget->refresh();
    //我喜欢 初始化
//    ui->favorMusicWidget->musicList.setName("FavorMusic");
//    ui->favorMusicWidget->musicList.read_fromSQL();
//    ui->favorMusicWidget->refresh();

    //从数据库中恢复歌单
    QSqlQuery sql_query;
    QString select_sql = "select name from MusicLists";
    sql_query.prepare(select_sql);
    if(sql_query.exec())
    {
        while(sql_query.next())
        {
            QString musicListName=sql_query.value(0).toString();
            MusicList tempList;
            tempList.setName(musicListName);
            tempList.read_fromSQL();
            musiclist.push_back(tempList);

            qDebug() << "sql_query.next()";
        }
    }
//    namelist_refresh();
}


QString formatTime(qint64 timeMilliSeconds)
{
    qint64 seconds = timeMilliSeconds / 1000;
    const qint64 minutes = seconds / 60;
    seconds -= minutes * 60;
    return QStringLiteral("%1:%2")
        .arg(minutes, 2, 10, QLatin1Char('0'))
        .arg(seconds, 2, 10, QLatin1Char('0'));
}


//void MainWidget::namelist_refresh()
//{
//    //先清空
//    QSqlQuery sql_query;
//    QString delete_sql = "delete from MusicLists";
//    sql_query.prepare(delete_sql);
//    sql_query.exec();
//    for(size_t i=0;i<musiclist.size();i++){
//        QSqlQuery sql_query2;
//        QString insert_sql = "insert into MusicLists values (?)";
//        sql_query2.prepare(insert_sql);
//        sql_query2.addBindValue(musiclist[i].getName());
//        sql_query2.exec();
//    }
//    //展示列表刷新 -- 歌单
////    ui->nameListWidget->clear();
////    for(size_t i=0;i<musiclist.size();i++){
////        QListWidgetItem *item = new QListWidgetItem;
////        item->setIcon(QIcon(":/image/image/image/music_list.png"));
////        item->setText(musiclist[i].getName());
////        ui->nameListWidget->addItem(item);
////    }
//}


/*一些点击事件的响应（使用.ui中的部件“转到槽”自动生成）*/
void MainWidget::on_btnCurMusic_clicked()
{
    //切换到“当前播放”界面
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWidget::on_btnLocalMusic_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWidget::on_btnFavorMusic_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWidget::on_btnPre_clicked()
{
    playlist->previous();
}

void MainWidget::on_btnPlay_clicked()
{
    if(player->state()==QMediaPlayer::PlayingState)
     {
        player->pause();
     }
    else if(player->state()==QMediaPlayer::PausedState){

        player->play();
    }
    else if(!playlist->isEmpty() && (player->state()==QMediaPlayer::StoppedState))
    {
        playlist->setCurrentIndex(0);
        player->play();
    }
}

void MainWidget::on_btnNext_clicked()
{
    playlist->next();
}

// 目前无响应
void MainWidget::on_btnAdd_clicked()
{
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    fileDialog.setWindowTitle(tr("添加本地音乐（注：自动过滤，按下\"Ctrl+A\"全选添加即可；不支持添加文件夹）"));

    QStringList list;
    list<<"application/octet-stream";
    fileDialog.setMimeTypeFilters(list);
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));
    if (fileDialog.exec() == QDialog::Accepted){
       QList<QUrl> urls=fileDialog.selectedUrls();
       ui->localMusicWidget->musicList.addMusic(urls);
       ui->localMusicWidget->refresh();
        qDebug() << "ui->localMusicWidget->refresh() ";
       ui->stackedWidget->setCurrentIndex(1);//切换到本地音乐
    }


    qDebug() << "111111 ";
}


//void MainWidget::on_localMusicWidget_itemDoubleClicked(QListWidgetItem *item)
//{

//}

void MainWidget::on_localMusicWidget_doubleClicked(const QModelIndex &index)
{
    qDebug() << "00-on_localMusicWidget_doubleClicked";
    playlist->clear();

    qDebug() << "11-on_localMusicWidget_doubleClicked";
    ui->localMusicWidget->musicList.addToPlayList(playlist);
//    ui->playListWidget->setMusicList_playing(ui->localMusicWidget->musicList);
//    musicList = ui->localMusicWidget->musicList;

    int i=index.row();
    qDebug() << "22-on_localMusicWidget_doubleClicked";
    playlist->setCurrentIndex(i);
    player->play();
    ui->stackedWidget->setCurrentIndex(0);//跳转到当前播放列表
}
