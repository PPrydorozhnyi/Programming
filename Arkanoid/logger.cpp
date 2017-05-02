#include "logger.h"
#include <QDebug>

Logger::Logger(QObject *parent, QString fileName) :
    QObject(parent)
{
    m_date = true;

    if (!fileName.isEmpty()) {

        file = new QFile();
        file->setFileName(fileName);
        if (!file->open(QIODevice::Append | QIODevice::Text))
            qDebug()<< "can't open file for write log";

    }

    /*if (!fileName.isEmpty()) {

        fileForRead = new QFile();
        fileForRead->setFileName(fileName);

        if (!fileForRead->open(QIODevice::ReadOnly |QIODevice::Text) )
            qDebug()<< "can't open file for read log";

    }*/
}

Logger::~Logger()
{
    if (file)
        file->close();

    //if (fileForRead)
        //fileForRead->close();
    //delete str;
}

void Logger::setShowDateTime(bool value)
{
    m_date = value;
}


void Logger::write(const QString &value)
{
    QString text = value + '\n';
    if (m_date)
        text = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + text;

    qDebug() << text;

    QTextStream out(file);
    out.setCodec("UTF-8");

    if (file) {
        out << text;
        qDebug() << "wtf";
    }

    qDebug() << "ee";

}

#if 0

QString Logger::read() {

    QTextStream in(fileForRead);

    str = in.readAll();

    //QTextStream

    //QDebug() << QString("wtf");

    return str;
}

#endif
