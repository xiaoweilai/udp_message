#include "widget.h"
#include "ui_widget.h"
#include <qdatetime.h>
#include <QTextCodec>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    configFlag = false;        //初始化连接参数 为未连接
    ui->getTextEdit->ensureCursorVisible();
    ui->sendTextEdit->setFocus();      //程序启动时，焦点停在发送对话框
    ui->ipEdit->setText("192.168.1.103");   //设置默认的远程端Ip
    ui->portEdit->setText("6665");           //设置默认端口号

    //关联快捷键
    ui->udpSendButton->setShortcut(tr("Alt+F"));
//    QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
//    hostaddr1 = info.addresses().takeFirst();

    //  hostaddr1 = new QHostAddress("192.168.2.214"); //本地的Ip地址
    //    hostaddrStr = hostaddr1.toString();
    //   hostaddrStr = QNetworkInterface::allAddresses().first().toString();
    localIpStr = getIp();
    localHostAddr = new QHostAddress(localIpStr);
    udpSocket1 = new QUdpSocket(this);


    bool bindFlag = udpSocket1->bind(*localHostAddr, 6665, QUdpSocket::ShareAddress);
    if(!bindFlag)
    {
        QMessageBox box;
        box.setText(tr("初始化绑定socket错误！"));
        box.exec();
    }
    else
    {
        connect(udpSocket1, SIGNAL(readyRead()), this, SLOT(receive()));
        connect(ui->udpSendButton, SIGNAL(clicked()), this, SLOT(send()));
    }
    this->setWindowTitle(tr("基于Qt的UDP聊天界面-------南无准提佛母"));


    timerSendPkt = new QTimer(this);
    connect(timerSendPkt,SIGNAL(timeout()),this,SLOT(WriteData()));
    timerSendPkt->start(10);
}

void Widget::WriteData()
{
    if(!configFlag)
    {
        qDebug() << "no config";
        return;
    }
    sendStr = ui->sendTextEdit->toPlainText();
    if(sendStr.length()==0)
    {
        qDebug() << "str len zero";
        return;
    }
    send();
}

void Widget::send()
{
    autoScroll();
    sendStr = ui->sendTextEdit->toPlainText();
    QByteArray sendByteArray = sendStr.toAscii();
    QMessageBox box;
    if(sendStr.length()==0)
    {
        box.setText(tr("请输入发送内容"));
        box.exec();
    }
    else if(configFlag)
    {
        qDebug() << "send length:" << sendByteArray.length();
        udpSocket1->writeDatagram(sendByteArray, sendByteArray.length(), *remoteHostAddr, 6665);

//        //本地发送信息再信息交互窗口的显示
//        QDateTime time;
//        QString timeStr = time.currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
//        ui->getTextEdit->setTextColor(QColor("red"));
//        ui->getTextEdit->insertPlainText("本机" + localIpStr + ": " + timeStr + "\n");
//        ui->getTextEdit->setTextColor(QColor("black"));
//        ui->getTextEdit->insertPlainText( sendStr +"\n");
//        ui->sendTextEdit->clear();          //点击发送后，发送编辑框内清零
//        ui->sendTextEdit->setFocus();      //焦点停留在发送编辑框
    }
    else if(!configFlag)
    {
        box.setText("请您先点击确认按钮!");
        box.exec();
    }
}
void Widget::receive()
{
    while(udpSocket1->hasPendingDatagrams())
    {
        QTextCodec *tc=QTextCodec::codecForName("UTF-8");  //UTF-8
        QDateTime time;
        QString timeStr = time.currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");

        QByteArray data;
        data.resize(udpSocket1->pendingDatagramSize());
        udpSocket1->readDatagram(data.data(), data.size());
//        QString dataStr =  QString::fromUtf8(data.data());   //这样写也是正确的
        QString dataStr = tc->toUnicode(data);
        ui->getTextEdit->setTextColor(QColor("red"));
        ui->getTextEdit->insertPlainText("远程"  + remoteIpStr+": "+ timeStr +"\n" );
        ui->getTextEdit->setTextColor(QColor("black"));
        ui->getTextEdit->insertPlainText(dataStr  + "\n" );
        autoScroll();

    }

}
QString Widget::getIp()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list)
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)   //我们使用IPv4地址
        {
            if(address.toString().contains("127.0."))
                continue;
            if(address.toString().contains("192.168.1."))
            {
                qDebug()<<"本机Ip："<<address.toString();
                return address.toString();
            }
            else
            {
                continue;
            }

        }
    }
    return 0;

}
void Widget::autoScroll()
{
    QTextCursor cursor = ui->getTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->getTextEdit->setTextCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_clearButton_clicked()
{
    ui->getTextEdit->clear();
}


void Widget::on_configButton_clicked()
{
     remoteIpStr = ui->ipEdit->text();
    QString port = ui->portEdit->text();
    qDebug()<<"远程端Ip："<<remoteIpStr<<"端口号："<<port;
    remoteHostAddr = new QHostAddress(remoteIpStr);

    QMessageBox box;
    if(remoteIpStr.length()==0 || port.length()==0 || port.toInt()<1024)
    {
        configFlag = false;
        box.setText("请正确设置远程端Ip地址和端口号！");
        box.exec();
    }
    else
    {
        configFlag = true;
        box.setText("您设置的远程端Ip：" + remoteIpStr+"端口号："+port);
        box.exec();
    }

}

void Widget::on_exitButton_clicked()
{
    this->close();
}
