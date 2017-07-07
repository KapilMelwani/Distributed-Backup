#ifndef CLIENTTHREADRECEIVE_H
#define CLIENTTHREADRECEIVE_H
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTextStream>

class ClientThreadReceive : public QThread
{
        Q_OBJECT
signals:
        void read();
public slots:
        void run()
        {
            QString line;
            QTextStream out(stdout, QIODevice::ReadWrite);
            while(1){
                out << line; //escribo yo
                out.flush();
                if(!line.isEmpty())
                    qDebug()<<"written";
                    emit read();
            }
        }
};
#endif // CLIENTTHREADRECEIVE_H
