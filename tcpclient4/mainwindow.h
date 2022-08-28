#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include<QListWidgetItem>
#include<QTcpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QString connectport;
protected:
    void processPendinDatagrames(); //实时处理监听信号的函数
    bool connectTofriend(QString peerID);         //点击好友item时会与对方建立连接，对方不在线会作出提示
    void sendMessage();     //发送信息
    void showMessage(QString userName, QString message, QString time);
    void startChat(QString peerID);

    QString getMessage();

private slots:

    void on_delFriButton_clicked(bool checked);     //删除好友控件

    void on_addFriButton_clicked(bool checked);     //添加好友控件

    void on_sendButton_clicked();

    void on_friendList_itemDoubleClicked(QListWidgetItem *item);    //选择聊天好友逻辑函数

    void on_refreshButton_clicked();        //更新好友列表

    void on_sendFileButton_clicked();       //文件传输控件

    void on_setButton_clicked();            //信息发送按钮
    void recvData();
    void on_freeTalkButton_clicked();       //临时聊天室控件

    void on_clearButton_clicked();          //清空输入框

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket;
    QUdpSocket *msgUdpSocket;
    QTcpSocket *tcpSocket;
    QTcpSocket *tcpSocket2;
    QString localHost = "127.0.0.1";
    QString peerID;
};

#endif // MAINWINDOW_H
