#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent, QString fileName);
    ~Logger();
    void setShowDateTime(bool value);

private:
    QFile *file;
    //QFile *fileForRead;
    bool m_date;
    //QString str;

public slots:
    void write(const QString &value);
    //QString read();
};

#endif // LOGGER_H
