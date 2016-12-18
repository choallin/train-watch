#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QJsonDocument>
#include <QQmlEngine>

#include "trainwatchapi.h"
#include "lib/jsonapi/manager.h"
#include "../dataClasses/station.h"
#include "../dataClasses/country.h"

TrainWatchApi::TrainWatchApi(QObject* parent):
    QObject(parent),
    m_endPoint("localhost"),
    m_version("1")
{

}

TrainWatchApi::~TrainWatchApi()
{

}

QString TrainWatchApi::api()
{
    return QString("http://%1/version/%2/")
            .arg(m_endPoint)
            .arg(m_version);
}

QNetworkAccessManager* TrainWatchApi::getNetworkAccessManager()
{
    // workaround bug iOS - cannot reuse QNetworkAccessManager QTBUG-49751
    // otherwise accessibility not detected if switch off and on again
    QNetworkAccessManager* networkAccessManager = new QNetworkAccessManager(this);
    if(networkAccessManager->networkAccessible() != QNetworkAccessManager::Accessible) {
        if(networkAccessManager->networkAccessible() == QNetworkAccessManager::NotAccessible) {
            qWarning("no access to network");
            networkAccessManager->deleteLater();
            return 0;
        }
        qWarning("no access: The network accessibility cannot be determined.");
        networkAccessManager->deleteLater();
        return 0;
    }

    return networkAccessManager;
}

bool TrainWatchApi::isSuccessFull(QNetworkReply* reply)
{
    if(!reply) {
        qWarning("response is null");
        return false;
    }
    const qint64 available = reply->bytesAvailable();
    if(available == 0) {
        qWarning("no bytes received, error: %s", qPrintable(reply->errorString()));
        return false;
    }
    const int httpStatusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug("http status: %d, %lld bytes available", httpStatusCode, available);
    if(httpStatusCode != 200) {
        return false;
    }

    return true;
}

void TrainWatchApi::getStations(const QString& searchString)
{
    QNetworkAccessManager* networkAccessManager = getNetworkAccessManager();
    if(!networkAccessManager){
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
    QNetworkAccessManager* networkAccessManager = qobject_cast<QNetworkAccessManager*>(sender());

    if(!isSuccessFull(reply)){
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

    reply->deleteLater();
    networkAccessManager->deleteLater();
}

void TrainWatchApi::getCountries()
{
    QNetworkAccessManager* networkAccessManager = getNetworkAccessManager();
    if(!networkAccessManager){
        return;
    }

    QString uri;
    uri = "http://www.mocky.io/v2/583c87d029000065106ecb12";
    //uri = "http://192.168.43.187:2300/version/1/country/de/stations?starts_with=" + searchString;

    QNetworkRequest request(uri);

    networkAccessManager->get(request);
    connect(networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(countriesSearchRequestFinished(QNetworkReply*)));
}

void TrainWatchApi::countriesSearchRequestFinished(QNetworkReply* reply)
{
    QNetworkAccessManager* networkAccessManager = qobject_cast<QNetworkAccessManager*>(sender());

    if(!isSuccessFull(reply)){
       return;
    }

    QJsonDocument jdoc = QJsonDocument::fromJson(reply->readAll());

    JSONAPI::Manager& jsonApiManager = JSONAPI::Manager::instance();
    QList<QObject*> countries = jsonApiManager.deserialize(jdoc.object());

    QListIterator<QObject*> lit(countries);
    while(lit.hasNext()){
        Country* country = dynamic_cast<Country*>(lit.next());
        QQmlEngine::setObjectOwnership(country, QQmlEngine::JavaScriptOwnership);
    }

    emit countriesFinished(QVariant::fromValue(countries));

    reply->deleteLater();
    networkAccessManager->deleteLater();
}

