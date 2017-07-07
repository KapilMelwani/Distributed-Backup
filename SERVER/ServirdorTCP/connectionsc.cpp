#include "connectionsc.h"

ConnectionSC::ConnectionSC(QTcpSocket* client):
    socket(client),
    clientConnected(1),
    clientName(),
    portNumber(0)
    {}

/*-------------------------SET PRIVATE VARIABLES-----------------------*/

void ConnectionSC::setClientName(QString _clientName)
{
    clientName = _clientName;
}

void ConnectionSC::setClientStatus()
{
    clientConnected = false;
}

void ConnectionSC::setPortNumber(quint16 port)
{
    portNumber = port;
}

/*-------------------------GET PRIVATE VARIABLES-----------------------*/

quint16 ConnectionSC::getPortNumber()
{
    return portNumber;
}

bool ConnectionSC::getClientStatus()
{
    return clientConnected;
}

QTcpSocket* ConnectionSC::getSocketDescriptor()
{
    return socket;
}

QString ConnectionSC::getClientName()
{
    return clientName;
}

void ConnectionSC::sendMessage(QString message)
{
    socket->write(message.toUtf8().constData());
    socket->flush();

}

QString ConnectionSC::receiveMessage()
{
    QString auxMessage;
    while(socket->bytesAvailable()){
        auxMessage = socket->readAll();
    }
    //clientSocket->write(auxMessage);
    return auxMessage;
}

