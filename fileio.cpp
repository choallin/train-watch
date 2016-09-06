#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>

#include "fileio.h"

FileIO::FileIO(QObject *parent) :
    QObject(parent),
    m_source(QString())
{
}

bool FileIO::writeFile(const QString& data) const
{
    QFile f(m_source);

    if(!f.open(QIODevice::WriteOnly)) {
        return false;
    }
    QTextStream out(&f);
    out << data;
    f.close();

    return true;
}

QString FileIO::readFile() const
{
    QFile f(m_source);

    if(!f.open(QIODevice::ReadOnly)) {
        return QString();
    }

    return QString(f.readAll());
}

