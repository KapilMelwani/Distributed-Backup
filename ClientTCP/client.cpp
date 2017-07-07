#include "client.h"
#include <QCoreApplication>
ChattingMessages pmessage;

Client::Client(QObject *parent) :
    QObject(parent)
{
    qDebug()<<"PRÁCTICA 3: SISTEMAS OPERATIVOS AVANZADOS \nAUTOR: KAPIL ASHOK MELWANI\nINGENIERIA INFORMÁTICA"
              "\n\nCLIENTE TCP:\n"
              "\nINSTRUCCIONES: \n"
              "\t1) Address: 127.0.0.1 (localhost) - 0.0.0.0\n"
              "\t2) Port: [Selected in Server]\n"
              "\t3) Username: [your name]\n"
              "\t4) Save Route: Route in which you want to save the files.\n\n"
              "DETAILS: TO SEND A FILE --> send [route]\n\n";
    QObject::connect(&thread,SIGNAL(written(QString)),this,SLOT(letswrite(QString)));
    times = 0;
    read = 0;
    sizeFile = 0;
}

Client::~Client(){}

void Client::sendMessage(QString message)
{
    qint32 sizeFile;
    QString fileRoute;
    std::string output; //output que tendra el protobuff
    output_size = 0;
    if(message.contains("send")){
        fileRoute = message.remove("send ");
        fileRoute = message.remove("\r\n");
        sizeFile = QFileInfo(fileRoute).fileName().size();
        pmessage.set_type(ChattingMessages_typeMessage_FILE);
        pmessage.set_sourceroute(fileRoute.toStdString()); //Ruta del fichero
        pmessage.set_clientname(name.toStdString());
        pmessage.set_sizefile(sizeFile); //Tamaño del fichero
        pmessage.SerializeToString(&output); //serializamos todo el proto, a std::string
        output_size = output.size(); //Tamaño de la cabecera protobuff qint32
        clientSocket->write(reinterpret_cast<char*>(&output_size),sizeof(output_size));
        clientSocket->write(output.c_str(),output_size);
        clientSocket->flush();
        fileTransfer(fileRoute); //llamamos a filetransfer para leer todo el fichero
    }
}

void Client::fileTransfer(QString route)
{
    QFile file(route); //creamos el qfile a traves de la ruta
    if(file.open(QIODevice::ReadOnly)){ //abirmos el fichero que queremos enviar
        while(!file.atEnd()){ //hasta el final
            QByteArray fileDataBlock = file.read(1024*1024); //metemos en qbytearray lo que leemos del fichero
            clientSocket->write(fileDataBlock); //metemos en el socket el qbytearray
        }
    }
}

void Client::receiveMessage()
{
    quint32 size;
    std::string buffer;
    while(times>=0){
        if(times == 0){
            if(clientSocket->bytesAvailable() >= sizeof(size)){
                clientSocket->read(reinterpret_cast<char*>(&size),sizeof(size));
                times = 1; //si lee size, entra por if(times == 1)
            }
            else
                return; //si sale, vuelve a times==0 cuando vengan + bytes
        }
        if(times == 1){ //(*)
            if(clientSocket->bytesAvailable() >= size){
                QByteArray output = clientSocket->read(size);
                buffer = output.toStdString();
                pmessage.ParseFromString(buffer);
                times = 2;
            }
            if(!clientSocket->bytesAvailable() >= size){ //times vale 1, si sale, entra por aqui (*)
                return;
            }
        }
        if(times == 2){
            if(pmessage.type() == ChattingMessages_typeMessage_FILE){
                QString file_ = QString::fromStdString(pmessage.sourceroute());
                QFile *file_source = new QFile(file_);
                QFileInfo file_route(file_);
                QString filename = file_route.fileName();
                QString dst_path = saveRoute + filename;
                QDir dst_directory(saveRoute);
                if(!dst_directory.exists())
                    QDir().mkdir(saveRoute);
                file = new QFile(dst_path);
                sizeFile = file_source->size();
                times = 3;
            }
        }
        if(times == 3){
            if(file->open(QIODevice::Append)){
                while(read < sizeFile)
                {
                    data = clientSocket->read(1024*1024);
                    if(!data.isEmpty()){
                        file->write(data);
                        read += data.size();
                    }
                    else{
                        file->close();
                        return;
                    }
                }
                file->close();
                times = 0;
            }
        }
        if(file->size() == sizeFile)
            qDebug()<<"File received: " << file->fileName() << "\nSize File: " << sizeFile << "\nSender:" << QString::fromStdString(pmessage.clientname()) << "\n\n";
    }
}

void Client::connectToServer(QString address,quint32 port)
{
    QTextStream in(stdin, QIODevice::ReadOnly);
    QTextStream out(stdout, QIODevice::WriteOnly);
    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost(QHostAddress(address),port);
    QObject::connect(clientSocket,SIGNAL(readyRead()),this,SLOT(letsread()));
    QString askName = "What name are you going to use?: ";
    out << askName;
    out.flush();
    in >> name;
    QString askroute = "Save Route: ";
    out << askroute;
    out.flush();
    in >> saveRoute;
    thread.start();
    qDebug()<<"Welcome to the Chat\n";
}

void Client::letsread()
{
    receiveMessage();
}

void Client::letswrite(QString line)
{
    sendMessage(line);
}
