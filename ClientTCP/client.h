#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkConfigurationManager>
#include <QHostAddress>
#include <QThread>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include "clientthread.h"
#include <chat.pb.h>
using namespace std;



class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    ~Client();
    void sendMessage(QString message);
    void receiveMessage();
    void fileTransfer(QString route);
    QString getClientName(void)
    {
        return name;
    }
signals:
    void connect();
public slots:
    void letsread();
    void connectToServer(QString address,quint32 port);
    void letswrite(QString line);
private:
    QTcpSocket* clientSocket;
    ClientThread thread;
    QString name;
    ChattingMessages pmessage;
    qint32 output_size;
    int times;
    int contador;
    quint64 sizeFile;
    QByteArray data;
    QFile *file;
    QString saveRoute;
    quint64 read;

};

#endif // CLIENT_H
