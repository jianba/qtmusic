#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QFileDialog>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::init_play()
{
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist;
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
}

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
    QStringList list;list<<"application/octet-stream";
    fileDialog.setMimeTypeFilters(list);
//    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));
//    if (fileDialog.exec() == QDialog::Accepted){
//       QList<QUrl> urls=fileDialog.selectedUrls();
//       ui->localMusicWidget->musicList.addMusic(urls);
//       ui->localMusicWidget->refresh();
//       ui->stackedWidget->setCurrentIndex(1);//切换到本地音乐
//    }
}
