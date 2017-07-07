#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTextStream>
class ClientThread : public QThread
{
        Q_OBJECT
public:

signals:
        void written(QString line);
public slots:
        void run()
        {
            QTextStream in(stdin, QIODevice::ReadWrite);
            while(1){
                QString line;
                //in.readLine() >> line; //escribo yo
                line = in.readLine();
                if(!line.isEmpty())
                    emit written(line);
            }
        }
};
#endif // CLIENTTHREAD_H
