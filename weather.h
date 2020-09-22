#ifndef WEATHER_H
#define WEATHER_H
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
#include"texthead.h"
#include"otherhead.h"
struct Aqi
{
    QString aqi;
    QString qlty;
    QString pm25;
    QString pm10;
    QString no2;
    QString so2;
    QString co;
    QString o3;

friend  QDebug& operator<<(QDebug&out,const Aqi&aqi)
{
    out<<"AQI Content"<<endl;

    out<<"aqi="<<aqi.aqi<<endl;
    out<<"qlty="<<aqi.qlty<<endl;
    out<<"pm25="<<aqi.pm25<<endl;
    out<<"pm10="<<aqi.pm10<<endl;
    out<<"no2="<<aqi.no2<<endl;
    out<<"so2"<<aqi.so2<<endl;
    out<<"co"<<aqi.co<<endl;
    out<<"o3"<<aqi.o3<<endl;
    return out;
}

};

struct Basic
{
    QString city;
    QString cnty;
    QString id;
    QString lat;
    QString lon;

 friend  QDebug& operator<<(QDebug&out,const Basic&basic)
    {
        out<<"BASIC Content"<<endl;

        out<<"city="<<basic.city<<endl;
        out<<"cnty="<<basic.cnty<<endl;
        out<<"id="<<basic.id<<endl;
        out<<"lat="<<basic.lat<<endl;
        out<<"lon="<<basic.lon<<endl;
        return out;
    }


};
struct Wind
{
    QString deg;
    QString dir;
    QString sc;
    QString spd;
 friend  QDebug& operator<<(QDebug&out,const Wind&wind)
    {
        out<<"WIND Content"<<endl;

        out<<"deg="<<wind.deg<<endl;
        out<<"dir="<<wind.dir<<endl;
        out<<"sc="<<wind.sc<<endl;
        out<<"spd="<<wind.spd<<endl;
        return out;
    }
};

struct WeatherItem
{
    Wind wind;
    Basic basic;
    Aqi aqi;
    QString txt_d;
    QString txt_n;
    QDateTime date;
    QString hum;
    QString maxTmp;
    QString minTmp;


    const WeatherItem& operator=(const WeatherItem&wi)
    {
        wind=wi.wind;
        basic=wi.basic;
        aqi=wi.aqi;
        txt_d=wi.txt_d;
        txt_n=wi.txt_n;
        date=wi.date;
        hum=wi.hum;
        maxTmp=wi.maxTmp;
        minTmp=wi.minTmp;
        return *this;
    }

    bool operator==(const WeatherItem&wi)
    {
        if(date.toString()==this->date.toString()&&basic.city==wi.basic.city)
            return true;
        else
            return false;
    }
    bool operator!=(const WeatherItem&wi)
    {
        if(*this==wi)
            return false;
        else
            return true;
    }

    WeatherItem()
    {
    }
    WeatherItem(const WeatherItem&df)
    {
        *this=df;
    }

    const QString& getWindDir()
    {
        return wind.dir;
    }
    const QString&getWindDeg()
    {
        return wind.deg;
    }
    const QString&getTxt_d()
    {
        return txt_d;
    }
    const QString&getTxt_n()
    {
        return txt_n;
    }
    const QString&getMaxTmp()
    {
        return maxTmp;
    }
    const QString&getMinTmp()
    {
        return minTmp;
    }
    const QString&getHum()
    {
        return hum;
    }
   friend QDebug& operator<<(QDebug&out,const WeatherItem&wi)
    {
        out<<"WeatherItem"<<wi.date<<"Content"<<endl;
        out<<wi.aqi<<endl;
        out<<wi.basic<<endl;
        out<<wi.wind<<endl;
        out<<"txt_d="<<wi.txt_d<<endl;
        out<<"txt_n="<<wi.txt_n<<endl;
        out<<"hum="<<wi.hum<<endl;
        out<<"maxTmp="<<wi.maxTmp<<endl;
        out<<"minTmp="<<wi.minTmp<<endl;
        return out;
    }
};

class Weather
{
  QMap<QDateTime,QVector<WeatherItem> > mapWeather;
public:
    Weather()
    {

    }
    Weather(const Weather&weather)
    {
      *this=weather;
    }
    const Weather&operator=(const Weather&weather)
    {
        mapWeather=weather.mapWeather;
        return *this;
    }
    const Weather&operator=(const WeatherItem&weatherItem)
    {
        if(mapWeather.value(weatherItem.date).isEmpty())
           {
            QVector<WeatherItem> vec_tmp;
            vec_tmp.push_back(weatherItem);
            mapWeather.insert(weatherItem.date,vec_tmp);
            return *this;
           }
        bool flag=false;
        QVector<WeatherItem> vec_tmp=mapWeather.value(weatherItem.date);
        for(auto it=vec_tmp.begin();it!=vec_tmp.end();++it)
        {
            if(*it==weatherItem)
                flag=true;
        }

        if(flag==false)
        {
            vec_tmp.push_back(weatherItem);
            mapWeather.erase(mapWeather.find(weatherItem.date));
            mapWeather.insert(weatherItem.date,vec_tmp);
            return *this;
        }
        return *this;
    }

    bool isEmpty()
    {
        if(mapWeather.isEmpty())
            return true;
        else
            return false;
    }

    const WeatherItem& findWeatherInfoByDateTime(const QDateTime&time)
    {
        qDebug()<<time<<endl;
        return mapWeather.value(time).at(0);
    }

   friend QDebug operator<<(QDebug out,const Weather&weather)
    {
        for(auto it=weather.mapWeather.constBegin();it!=weather.mapWeather.constEnd();++it)
        {
            QVector<WeatherItem> vec_tmp=it.value();
            for(auto _it=vec_tmp.begin();_it!=vec_tmp.end();++_it)
            {
               out<<*it<<endl;
            }
        }
        return out;
    }

};

#endif // WEATHER_H
