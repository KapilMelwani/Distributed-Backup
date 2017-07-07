#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QHostAddress>

class ConnectionSC
{
public:
    ConnectionSC(QTcpSocket* client);

    void setClientName(QString _clientName);
    void setPortNumber(quint16 port);
    void setClientStatus();

    QTcpSocket* getSocketDescriptor(void);
    QString getClientName(void);
    quint16 getPortNumber(void);
    bool getClientStatus();

    void sendMessage(QString message);
    QString receiveMessage();

private:
    QTcpSocket* socket;
    QString clientName;
    quint16 portNumber;
    bool clientConnected = true;
};

