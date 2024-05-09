#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMenu>
#include <QSystemTrayIcon>

#include "musiclist.h"
#include "music.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

//     vector<MusicList> musiclist;
private:
    Ui::MainWidget *ui;

    //当前播放器
    QMediaPlayer *player;
    //当前播放列表
    QMediaPlaylist *playlist;
    //初始化一些成员变量以及connect连接
    void init_play();

    //数据库初始化
    void init_sqlite();
    //配置初始化（配置文件读取）
    void init_settings();
    //“本地音乐”、“我喜欢”等歌单的初始化
    void init_musicList();

    //歌单
    vector<MusicList> musiclist;
    //用于标识现在展示的是哪个歌单
    int musiclist_index=-1;
    //更新展示歌单名字的listwidget
    void namelist_refresh();
    //用于更新展示歌单内容的listwidget
    void musicListWidget_refresh();

private slots:
    void on_btnCurMusic_clicked();

    void on_btnLocalMusic_clicked();

    void on_btnFavorMusic_clicked();

    void on_btnPre_clicked();
    void on_btnPlay_clicked();
    void on_btnNext_clicked();
    void on_btnAdd_clicked();
//    void on_localMusicWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_localMusicWidget_doubleClicked(const QModelIndex &index);
};

#endif // MAINWIDGET_H
