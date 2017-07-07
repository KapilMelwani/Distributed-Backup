#include <QObject>
#include <QTcpServer>
#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QMap>
#include <connectionsc.h>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();
    void run(QString name, QHostAddress address,int port);
    void addName(ConnectionSC* newClient);
    void setServerName(QString name);
public slots:
    void incommingConnection();
    void connectionRefused();
    //void welcome();
    void sendBroadcast();
private:
    ConnectionSC* connection;
    QTcpServer* myServer;
    QString serverName;
    QMap<QTcpSocket*,ConnectionSC*> lista;
    QMap<QTcpSocket*,ConnectionSC*>::iterator i;

    int numberofConnections = 0;
};

