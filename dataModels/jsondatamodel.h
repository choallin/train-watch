#ifndef JSONDATAMODEL_H
#define JSONDATAMODEL_H

#include <QAbstractListModel>

#include "../data/jsondata.h"

class JsonDataModel : public QAbstractListModel
{
    Q_OBJECT

private:
    JsonData* jsonData;

public:
    JsonDataModel(QObject *parent, JsonData* jsonData);
    ~JsonDataModel();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
};

#endif // JSONDATAMODEL_H
