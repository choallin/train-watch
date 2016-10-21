#include <QJsonArray>

#include "jsondatamodel.h"

JsonDataModel::JsonDataModel(QObject* parent, JsonData *jsonData) :
    QAbstractListModel(parent),
    jsonData(jsonData)
{
}

JsonDataModel::~JsonDataModel()
{
}

int JsonDataModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return jsonData->modelItems().toArray().size();
}

QVariant JsonDataModel::data(const QModelIndex & index, int role) const
{
    if(role == Qt::DisplayRole) {
        return jsonData->modelItems().toArray().at(index.row());
    }
    else {
        return QVariant();
    }
}
