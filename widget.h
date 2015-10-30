#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork/QUdpSocket>
#include<QtNetwork/QHostAddress>
#include <QMessageBox>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QTimer>



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QHostAddress *localHostAddr;
     QHostAddress *remoteHostAddr;
    QString localIpStr;
    QString remoteIpStr;

    QString getIp();
    void autoScroll();

private slots:
    void send();
    void receive();
    void WriteData();
    
    void on_clearButton_clicked();


    void on_configButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket1;   
    bool configFlag;


    QTimer *timerSendPkt;
    QString sendStr;

};

#endif // WIDGET_H
