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

private:
    Ui::MainWidget *ui;
    void paintEvent(QPaintEvent *event) override;

    //UI组件额外的一些处理
    void init_UI();

    //当前播放器
    QMediaPlayer *player;
    //当前播放列表
    QMediaPlaylist *playlist;
    //初始化一些成员变量以及connect连接
    void init_play();
    //更新播放信息相关（进度、信息等）
    void updatePosition(qint64 position);
    void updateDuration(qint64 duration);
    void setPosition(int position);
    void updateInfo();
    void updatePlayBtn();

    //系统托盘
    QSystemTrayIcon *mySystemTray;
    QAction *action_systemTray_play;
    QAction *action_systemTray_playmode;
    //响应系统托盘的动作（双击等）
    void systemTrayIcon_activated(QSystemTrayIcon::ActivationReason reason);
    //退出应用
    void quitMusicPlayer();
    //系统托盘初始化
    void init_systemTrayIcon();

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

    /*右键菜单*/
    //菜单项的初始化
    void init_actions();
    //“当前播放”列表的右键菜单
    QMenu *menu_playlist;
    //“本地音乐”列表的右键菜单
    QMenu *menu_locallist;
    //“我喜欢”列表的右键菜单
    QMenu *menu_favorlist;
    //“歌单名列表”的右键菜单
    QMenu *menu_namelist;
    //“歌单展示列表”的右键菜单
    QMenu *menu_musiclist;
    //更换皮肤的菜单
    QMenu *menu_changeSkin;

protected:
    //窗口拖动时记录的起始点
    QPoint offset;
    /*重写Widget的一些方法*/
    //实现窗口可拖动
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    //关闭时不退出，而是到系统托盘
    void closeEvent(QCloseEvent *event) override;
    //拖拽文件进入
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;

private slots:
    /*部分右键菜单项对应的操作（即对应QAction连接的槽函数）*/
    void background_to_default();//换到默认背景
    void background_setting();//自定义背景

    /*一些点击事件的响应（使用.ui中的部件“转到槽”自动生成）*/
    void on_btnCurMusic_clicked();

    void on_btnLocalMusic_clicked();

    void on_btnFavorMusic_clicked();

    void on_btnPre_clicked();
    void on_btnPlay_clicked();
    void on_btnNext_clicked();
    void on_btnAdd_clicked();
    void on_localMusicWidget_doubleClicked(const QModelIndex &index);
    void on_btnLyric_clicked();
    void on_btnQuit_clicked();
    void on_btnMin_clicked();
    void on_btnVolume_clicked();
    void on_btnSkin_clicked();
private slots:
    void on_volumeSlider_valueChanged(int value);
    void on_localMusicWidget_customContextMenuRequested(const QPoint &pos);
};

#endif // MAINWIDGET_H
