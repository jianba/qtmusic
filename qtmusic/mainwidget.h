#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

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

    //当前播放器
    QMediaPlayer *player;
    //当前播放列表
    QMediaPlaylist *playlist;
    //初始化一些成员变量以及connect连接
    void init_play();

private slots:
    void on_btnCurMusic_clicked();

    void on_btnLocalMusic_clicked();

    void on_btnFavorMusic_clicked();

    void on_btnPre_clicked();
    void on_btnPlay_clicked();
    void on_btnNext_clicked();
    void on_btnAdd_clicked();
};

#endif // MAINWIDGET_H
