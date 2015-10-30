/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Fri Oct 30 23:02:55 2015
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *getTextEdit;
    QLabel *label;
    QPushButton *udpSendButton;
    QPushButton *tcpSendButton;
    QLabel *label_2;
    QTextEdit *sendTextEdit;
    QPushButton *clearButton;
    QPushButton *exitButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *ipEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QLineEdit *portEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *configButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(600, 400);
        getTextEdit = new QTextEdit(Widget);
        getTextEdit->setObjectName(QString::fromUtf8("getTextEdit"));
        getTextEdit->setEnabled(true);
        getTextEdit->setGeometry(QRect(40, 75, 521, 141));
        getTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        getTextEdit->setReadOnly(true);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 55, 71, 17));
        udpSendButton = new QPushButton(Widget);
        udpSendButton->setObjectName(QString::fromUtf8("udpSendButton"));
        udpSendButton->setGeometry(QRect(476, 313, 85, 27));
        tcpSendButton = new QPushButton(Widget);
        tcpSendButton->setObjectName(QString::fromUtf8("tcpSendButton"));
        tcpSendButton->setGeometry(QRect(476, 343, 85, 27));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 290, 59, 17));
        sendTextEdit = new QTextEdit(Widget);
        sendTextEdit->setObjectName(QString::fromUtf8("sendTextEdit"));
        sendTextEdit->setGeometry(QRect(40, 310, 421, 61));
        clearButton = new QPushButton(Widget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(374, 221, 85, 27));
        exitButton = new QPushButton(Widget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(480, 222, 85, 27));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 20, 521, 29));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        ipEdit = new QLineEdit(widget);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));

        horizontalLayout->addWidget(ipEdit);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        portEdit = new QLineEdit(widget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));

        horizontalLayout->addWidget(portEdit);

        horizontalSpacer_2 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        configButton = new QPushButton(widget);
        configButton->setObjectName(QString::fromUtf8("configButton"));

        horizontalLayout->addWidget(configButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\344\277\241\346\201\257\344\272\244\344\272\222\346\240\217", 0, QApplication::UnicodeUTF8));
        udpSendButton->setText(QApplication::translate("Widget", "UDP\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        tcpSendButton->setText(QApplication::translate("Widget", "TCP\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "\350\277\234\347\250\213\347\253\257IP\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        configButton->setText(QApplication::translate("Widget", "\347\241\256\345\256\232/\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
