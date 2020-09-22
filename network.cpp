#include"network.h"


Network::Network()
{
    this->url=QUrl("https://way.jd.com/he/freeweather?city=hangzhou&appkey=46faedfcfcaf5b3df72c9d64ac015b5b");
    this->head=QUrl("https://way.jd.com/he/freeweather?city=");
    this->suffix="appkey=";
    naManager=new QNetworkAccessManager();
}

Network::Network(QUrl&url,Type type)
{
   this->url=url;
   this->type=type;
}

const Network& Network::operator=(const Network&nw)
{
    this->url=nw.url;
    this->type=nw.type;
    this->head=nw.head;
    this->city=nw.city;
    this->vec_results=nw.vec_results;
    this->map_keyValues=nw.map_keyValues;
    return *this;
}

Network::Network(const Network&nw)
{
    *this=nw;
}

const QUrl& Network::constructUrl(const QUrl &head, const QString &city, const QString &suffix, const QString &appkey)
{
    QString tmp;
    tmp=head.toString()+city+suffix+appkey;
    qDebug()<<"TMP="<<tmp<<endl;
    return QUrl(tmp);
}

void Network::connectionEstablish(const QUrl&url)
{
    //connect(naManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_requestFinished(QNetworkReply* reply)));
    connect(naManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_requestFinished(QNetworkReply*)));
    request.setUrl(url);
}

void Network::post(const QUrl &url)
{

}

void Network::get(const QUrl &url)
{
  connectionEstablish(url);
  qDebug()<<url<<endl;

  QNetworkReply *reply=naManager->get(request);
}

void Network::http(const QUrl &rul)
{

}

void Network::slot_requestFinished(QNetworkReply* reply)
{
    QVariant statusCode=reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(statusCode.isValid())
        qDebug()<<"status code="<<statusCode.toInt();
    QVariant reason=reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    if(reason.isValid())
        qDebug()<<"reason="<<reason.toString()<<endl;
    QNetworkReply::NetworkError err=reply->error();
    if(err!=QNetworkReply::NoError)
    {
        qDebug()<<"Failed:"<<reply->errorString()<<endl;
    }
    else
    {
  //   QTextCodec* gbk = QTextCodec::codecForName("gbk");
  //   QByteArray gb = gbk->fromUnicode(reply->readAll());
   //  qDebug()<<gb<<endl;
     QByteArray gb=reply->readAll();
     QTextCodec* pCodec = QTextCodec::codecForName("UTF-8");
     qDebug()<<pCodec->fromUnicode(gb)<<endl;
     parseWeatherJson(gb,weather);
     qDebug()<<weather;
     emit finish();
    }
}

void Network::setHead(const QUrl&url)
{
    this->head=url;
}
void Network::setCity(const QString&city)
{
    this->city=city;
}
void Network::setSuffix(const QString&suffix)
{
    this->suffix=suffix;
}
void Network::setAppkey(const QString&appKey)
{
    //this->appkey=appKey;
}

const Weather& Network::getWeatherContent()
{
    return weather;
}

Network::~Network()
{
    delete naManager;
    naManager=nullptr;
}
