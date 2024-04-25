#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QLabel>
#include <QWidget>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

private:
    QLabel *label;

signals:

public slots:

};

#endif // MAINWIDGET_H
