#ifndef NETWORK_H
#define NETWORK_H
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
#include"texthead.h"
#include"otherhead.h"
#include"utils.h"
#include<QObject>
#include<QtCore>

class Network : public QObject
{
    Q_OBJECT
public:
    enum Type{HTTP,GET,POST};
    Network();
    Network(QUrl&url,Type type);
    Network(const Network&nw);
    const Network& operator=(const Network&nw);
    ~Network();
public:
    const QVector<QMap<QString,QString>>& getResult(QString Url);
    void setHead(const QUrl&url);
    void setCity(const QString&city);
    void setSuffix(const QString&suffix);
    void setAppkey(const QString&appKey);
    const QUrl& constructUrl(const QUrl&head,const QString&city,const QString&suffix,const QString&appkey="46faedfcfcaf5b3df72c9d64ac015b5b");
    void get(const QUrl&url);
    const Weather& getWeatherContent();
signals:
    void finish();
public slots:
    void slot_requestFinished(QNetworkReply* reply);
private:
    void post(const QUrl&url);

    void http(const QUrl&rul);
    void connectionEstablish(const QUrl&url);
private:
    QNetworkRequest request;
    QNetworkAccessManager* naManager;
    QMap<QString,QString> map_keyValues;
    QVector<QMap<QString,QString>> vec_results;
    Type type;
    QUrl head;
    QUrl url;
    QString city;
    QString suffix;
    Weather weather;
    const QString appkey="46faedfcfcaf5b3df72c9d64ac015b5b";

};



#endif // NETWORK_H
