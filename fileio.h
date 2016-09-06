#ifndef FILEIO_H
#define FILEIO_H

#include <QObject>
#include <QString>

class FileIO : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString source READ source WRITE setSource)

private:
    QString m_source;

public:
    FileIO(QObject* parent = 0);

    inline QString source() const { return m_source; }
    inline void setSource(const QString& source) { m_source = source; }

    Q_INVOKABLE bool writeFile(const QString& data) const;
    Q_INVOKABLE QString readFile() const;
};

#endif // FILEIO_H
