#include <QCoreApplication>
#include <client.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Client cliente;
    QString port;
    QString address;
    QTextStream in(stdin, QIODevice::ReadOnly);
    QTextStream out(stdout, QIODevice::WriteOnly);
    QString askAddress = "Address: ";
    out << askAddress;
    out.flush();
    in >> address;
    QString askPort = "Port: ";
    out << askPort;
    out.flush();
    in >> port;
    cliente.connectToServer(address,port.toInt());
    return a.exec();


}
