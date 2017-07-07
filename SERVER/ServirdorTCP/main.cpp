#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server myserver;
    QString port;
    QString name;
    QTextStream in(stdin, QIODevice::ReadOnly);
    QTextStream out(stdout, QIODevice::WriteOnly);
    QString askName = "Server Name: ";
    out << askName;
    out.flush();
    in >> name;
    myserver.setServerName(name);
    QString askPort = "Port: ";
    out << askPort;
    out.flush();
    in >> port;
    myserver.run(name,QHostAddress::Any,port.toInt());
    return a.exec();
}
