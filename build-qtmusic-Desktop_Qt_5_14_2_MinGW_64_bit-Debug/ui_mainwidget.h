/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "musiclistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QWidget *page_2;
    MusicListWidget *localMusicWidget;
    QPushButton *pushButton;
    QWidget *page_3;
    QPushButton *pushButton_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnCurMusic;
    QPushButton *btnLocalMusic;
    QPushButton *btnFavorMusic;
    QSlider *positionSlider;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPre;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPlay;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnNext;
    QPushButton *btnAdd;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(690, 483);
        stackedWidget = new QStackedWidget(MainWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(150, 30, 371, 251));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        localMusicWidget = new MusicListWidget(page_2);
        localMusicWidget->setObjectName(QString::fromUtf8("localMusicWidget"));
        localMusicWidget->setGeometry(QRect(30, 70, 241, 151));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 75, 23));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 70, 75, 23));
        stackedWidget->addWidget(page_3);
        widget = new QWidget(MainWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 50, 93, 99));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnCurMusic = new QPushButton(widget);
        btnCurMusic->setObjectName(QString::fromUtf8("btnCurMusic"));

        verticalLayout->addWidget(btnCurMusic);

        btnLocalMusic = new QPushButton(widget);
        btnLocalMusic->setObjectName(QString::fromUtf8("btnLocalMusic"));

        verticalLayout->addWidget(btnLocalMusic);

        btnFavorMusic = new QPushButton(widget);
        btnFavorMusic->setObjectName(QString::fromUtf8("btnFavorMusic"));

        verticalLayout->addWidget(btnFavorMusic);

        positionSlider = new QSlider(MainWidget);
        positionSlider->setObjectName(QString::fromUtf8("positionSlider"));
        positionSlider->setGeometry(QRect(130, 340, 271, 31));
        positionSlider->setOrientation(Qt::Horizontal);
        horizontalLayoutWidget = new QWidget(MainWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(130, 400, 271, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnPre = new QPushButton(horizontalLayoutWidget);
        btnPre->setObjectName(QString::fromUtf8("btnPre"));

        horizontalLayout->addWidget(btnPre);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPlay = new QPushButton(horizontalLayoutWidget);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));

        horizontalLayout->addWidget(btnPlay);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnNext = new QPushButton(horizontalLayoutWidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));

        horizontalLayout->addWidget(btnNext);

        btnAdd = new QPushButton(MainWidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(460, 420, 75, 23));

        retranslateUi(MainWidget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWidget", "xxxx", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWidget", "test3", nullptr));
        btnCurMusic->setText(QCoreApplication::translate("MainWidget", "\345\275\223\345\211\215\346\222\255\346\224\276", nullptr));
        btnLocalMusic->setText(QCoreApplication::translate("MainWidget", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        btnFavorMusic->setText(QCoreApplication::translate("MainWidget", "\346\210\221\345\226\234\346\254\242", nullptr));
        btnPre->setText(QCoreApplication::translate("MainWidget", "1", nullptr));
        btnPlay->setText(QCoreApplication::translate("MainWidget", "2", nullptr));
        btnNext->setText(QCoreApplication::translate("MainWidget", "3", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
