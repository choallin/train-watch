#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QJsonDocument>
#include <QQmlEngine>

#include "trainwatchapi.h"
#include "lib/jsonapi/manager.h"

TrainWatchApi::TrainWatchApi(QObject* parent):
    QObject(parent)
{

}

TrainWatchApi::~TrainWatchApi()
{

}

void TrainWatchApi::getStations(const QString& searchString)
{
    // workaround bug iOS - cannot reuse QNetworkAccessManager QTBUG-49751
    // otherwise accessibility not detected if switch off and on again
    QNetworkAccessManager* networkAccessManager = new QNetworkAccessManager(this);
    if(networkAccessManager->networkAccessible() != QNetworkAccessManager::Accessible) {
        if(networkAccessManager->networkAccessible() == QNetworkAccessManager::NotAccessible) {
            qWarning() << "getStations: NO ACCESS TO NETWORK";
            return;
        }
        qWarning() << "getStations NO ACCESS: The network accessibility cannot be determined.";
        return;
    }

    QString uri;
    uri = "http://www.mocky.io/v2/583c87d029000065106ecb12";
    //uri = "http://192.168.43.187:2300/version/1/country/de/stations?starts_with=" + searchString;

    QNetworkRequest request(uri);

    networkAccessManager->get(request);
    connect(networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(stationSearchRequestFinished(QNetworkReply*)));
}

void TrainWatchApi::stationSearchRequestFinished(QNetworkReply* reply)
{
    if(!reply) {
        qWarning("stations-search response is null");
        return;
    }
    const qint64 available = reply->bytesAvailable();
    if(available == 0) {
        qWarning("stations-search: no bytes received, error: %s", qPrintable(reply->errorString()));
        return;
    }
    const int httpStatusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug("stations-search http status: %d, %lld bytes available", httpStatusCode, available);
    if(httpStatusCode != 200) {
        return;
    }

    QJsonDocument jdoc = QJsonDocument::fromJson(reply->readAll());

    JSONAPI::Manager& jsonApiManager = JSONAPI::Manager::instance();
    QList<QObject*> stations = jsonApiManager.deserialize(jdoc.object());

    QListIterator<QObject*> lit(stations);
    while(lit.hasNext()){
        Station* station = dynamic_cast<Station*>(lit.next());
        QQmlEngine::setObjectOwnership(station, QQmlEngine::JavaScriptOwnership);
    }

    emit stationsFinished(QVariant::fromValue(stations));
}


