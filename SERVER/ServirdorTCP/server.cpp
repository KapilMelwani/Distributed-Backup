#include "server.h"

Server::Server(QObject *parent):
    QObject(parent)
{
    qDebug()<<"PRÁCTICA 3: SISTEMAS OPERATIVOS AVANZADOS \nAUTOR: KAPIL ASHOK MELWANI\nINGENIERIA INFORMÁTICA"
              "\n\nSERVIDOR TCP:\n"
              "\nINSTRUCCIONES: \n"
              "\t1) Server Name: [Select a Server Name]\n"
              "\t2) Port: [Select a TCP Port > 1024]\n";
    myServer = new QTcpServer(this);
    connect(myServer,SIGNAL(newConnection()),this,SLOT(incommingConnection()));
}

Server::~Server()
{
    myServer->close();
}

void Server::run(QString name, QHostAddress address,int port)
{
    if(myServer->listen(address,port))
    {
        QString dir = address.toString();
        qDebug()<< QString("Server %1 is running in %2:%3").arg(name).arg(dir).arg(port);
    }
    else{
        qDebug()<< "Error " << myServer->errorString();

    }
}

void Server::addName(ConnectionSC* newClient)
{
    numberofConnections++;
    QString number = QString::number(numberofConnections);
    QString name = serverName + "-" + number;
    newClient->setClientName(name);
}


void Server::connectionRefused()
{
    qDebug()<< "Client:" << sender() << "disconnected";
    lista.remove((QTcpSocket*)sender());
    sender()->deleteLater();
    numberofConnections--;
    if(numberofConnections==0){
        qDebug() << "Thanks for using this program";
    }
}


void Server::incommingConnection()
{
    while(myServer->hasPendingConnections()){
        connection = new ConnectionSC(myServer->nextPendingConnection());
        connect(connection->getSocketDescriptor(),SIGNAL(disconnected()),this,SLOT(connectionRefused()));
        addName(connection);
        qDebug() << QString("Client Connected: Socket Descriptor: "
                            "%1 Client Name: %2").arg(connection->getSocketDescriptor()->socketDescriptor()).
                    arg(connection->getClientName());
        lista.insert(connection->getSocketDescriptor(),connection);
        connect(connection->getSocketDescriptor(),SIGNAL(readyRead()),this,SLOT(sendBroadcast()));
    }
}

void Server::setServerName(QString name)
{
    serverName = name;
}


void Server::sendBroadcast()
{
    QTcpSocket* send = ((QTcpSocket*)sender());
    //QString line = QString::fromUtf8(send->readLine());
    QByteArray line = send->readAll();
    qDebug()<<line;
    for(i=lista.begin();i!=lista.end();i++)
    {
        if(i.key() != ((QTcpSocket*)sender())){
            i.value()->getSocketDescriptor()->write(line);
        }
    }
}

