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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnCurMusic;
    QPushButton *btnLocalMusic;
    QPushButton *btnFavorMusic;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(573, 474);
        stackedWidget = new QStackedWidget(MainWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(309, 90, 161, 131));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        widget = new QWidget(MainWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 120, 93, 99));
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


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Form", nullptr));
        btnCurMusic->setText(QCoreApplication::translate("MainWidget", "\345\275\223\345\211\215\346\222\255\346\224\276", nullptr));
        btnLocalMusic->setText(QCoreApplication::translate("MainWidget", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        btnFavorMusic->setText(QCoreApplication::translate("MainWidget", "\346\210\221\345\226\234\346\254\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
