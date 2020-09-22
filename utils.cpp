#include"utils.h"

void parseWeatherJson(const QByteArray&data,Weather&weather)
{
    QJsonParseError err;
    QJsonDocument root=QJsonDocument::fromJson(data,&err);
    if(err.error!=QJsonParseError::NoError)
    {
        qDebug()<<"JSON ERROR"<<endl;
        qDebug()<<err.errorString()<<endl;
        return;
    }
    else
    {
        QJsonObject rootObj=root.object();
        QJsonObject resultObj=rootObj.value("result").toObject();
        QJsonValue weatherValue=resultObj.value( "HeWeather5");
        if(weatherValue.isArray())
        {
            QJsonObject weatherObj=weatherValue.toArray().at(0).toObject();
            QJsonObject aqiObj=weatherObj.value("aqi").toObject().value("city").toObject();


            Aqi aqi;
            aqi.aqi=aqiObj.value("aqi").toString();
            aqi.qlty=aqiObj.value("qlty").toString();
            aqi.pm25=aqiObj.value("pm25").toString();
            aqi.pm10=aqiObj.value("pm10").toString();
            aqi.no2=aqiObj.value("no2").toString();
            aqi.so2=aqiObj.value("so2").toString();
            aqi.o3=aqiObj.value("o3").toString();

            QJsonObject basicObj=weatherObj.value("basic").toObject();

            Basic basic;
            basic.city=basicObj.value("city").toString();
            basic.cnty=basicObj.value("cnty").toString();
            basic.id=basicObj.value("id").toString();
            basic.lat=basicObj.value("lat").toString();
            basic.lon=basicObj.value("lon").toString();

            QJsonObject weatherItemObj=weatherObj.value("daily_forecast").toObject();
            QVector<WeatherItem> vecWeatherItem;


            int num=7;
            for(int i=0;i!=num;++i)
            {
                QJsonObject dailyForecastObj=weatherObj.value("daily_forecast").toArray().at(i).toObject();
                QJsonObject condObj=dailyForecastObj.value("cond").toObject();
                WeatherItem _wi;
                _wi.txt_d=condObj.value("txt_d").toString();
                _wi.txt_n=condObj.value("txt_n").toString();
                _wi.date=QDateTime::fromString(dailyForecastObj.value("date").toString(),"yyyy-MM-dd");
                QJsonObject tmpObj=dailyForecastObj.value("tmp").toObject();
                _wi.maxTmp=tmpObj.value("max").toString();
                _wi.minTmp=tmpObj.value("min").toString();
                _wi.hum=dailyForecastObj.value("hum").toString();
                qDebug()<<"hum="<<_wi.hum<<endl;
                qDebug()<<"txt_d"<<_wi.txt_d<<endl;
                qDebug()<<"max="<<_wi.maxTmp<<endl;

                QJsonObject windObj=dailyForecastObj.value("wind").toObject();
                Wind wind;
                wind.deg=windObj.value("deg").toString();
                wind.dir=windObj.value("dir").toString();
                wind.sc=windObj.value("sc").toString();
                wind.spd=windObj.value("spd").toString();
                if(!i)
                _wi.aqi=aqi;
                _wi.basic=basic;
                _wi.wind=wind;
                weather=_wi;

            }

        }
    }

}
