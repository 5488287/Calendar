
#include"calendarItem.h"
#include<QTextCodec>
CalendarItem::CalendarItem()
{

//    flag_plan=false;
//    flag_todo=false;
//    flag_festival=false;
//    flag_special=false;
    strDay="-1";
    flag_plan=true;
    flag_todo=true;
    flag_festival=true;
    flag_special=true;
    flag_display=false;

    lab_tag=new QLabel(this);
    lab_day=new QLabel(this);
    lab_weather=new QLabel(this);
    lab_festival=new QLabel(lab_tag);
    lab_special=new QLabel(lab_tag);
    lab_plan=new QLabel(lab_tag);
    lab_todo=new QLabel(lab_tag);
    text_detail=new QTextDocument("hello",this);
    hlayout=new QHBoxLayout(this);
    vlayout=new QVBoxLayout(this);
    v_tagLayout=new QVBoxLayout(lab_tag);

    vlayout->addWidget(lab_day);
    vlayout->addWidget(lab_weather);
    vlayout->addWidget(lab_festival);
    vlayout->addWidget(lab_special);

    hlayout->addWidget(lab_tag);
    hlayout->addLayout(vlayout);

    v_tagLayout->addWidget(lab_festival);
    v_tagLayout->addWidget(lab_special);
    v_tagLayout->addWidget(lab_plan);
    v_tagLayout->addWidget(lab_todo);
    lab_tag->setLayout(v_tagLayout);




    this->setLayout(hlayout);


  /*  QPalette palette;
    palette.setColor(QPalette::Background,QColor(255,255,0));
    this->setAutoFillBackground(true);
    this->setPalette(palette)*/;

    QFont font("Microsoft YaHei",10,75);
    lab_day->setFont(font);

    changePlanAttribute();
    changeTodoAttribute();
    changeSpecialAttribute();
    changeFestivalAttribute();

//    QTextCodec* pCodec = QTextCodec::codecForName("utf-8");
//    QByteArray sunny=pCodec->fromUnicode("晴");
//    QVector<QByteArray> vec_sunny;
//    vec_sunny.push_back(sunny);
//    vec_transformWeathers.push_back(vec_sunny);

//    QVector<QByteArray> vec_rainny;
//    vec_rainny.push_back(pCodec->fromUnicode("小雨"));
//    vec_rainny.push_back(pCodec->fromUnicode("中雨"));
//    vec_rainny.push_back(pCodec->fromUnicode("大雨"));
//    vec_rainny.push_back(pCodec->fromUnicode("暴雨"));
//    vec_rainny.push_back(pCodec->fromUnicode("阵雨"));
//    vec_rainny.push_back(pCodec->fromUnicode(tr("雷阵雨")));

//    vec_transformWeathers.push_back(vec_rainny);

//    QVector<QByteArray> vec_cloudy;
//    vec_cloudy.push_back(pCodec->fromUnicode("多云"));

//    QVector<QByteArray> vec_snowy;
//    vec_snowy.push_back(pCodec->fromUnicode("小雪"));
//    vec_snowy.push_back(pCodec->fromUnicode("中雪"));
//    vec_snowy.push_back(pCodec->fromUnicode("大雪"));
//    vec_snowy.push_back(pCodec->fromUnicode("暴雪"));
//    vec_transformWeathers.push_back(vec_snowy);

//    QVector<QByteArray> vec_windy;
//    vec_windy.push_back(pCodec->fromUnicode("刮风"));
//    vec_transformWeathers.push_back(vec_windy);

//    QVector<QByteArray> vec_overcast;
//    vec_windy.push_back(pCodec->fromUnicode("阴"));
//    vec_transformWeathers.push_back(vec_overcast);


}

const CalendarItem& CalendarItem::operator=(const CalendarItem&ci)
{
    qDebug()<<"op ="<<endl;
    return *this;
}

CalendarItem::CalendarItem(const CalendarItem&ci)
{
    *this=ci;
}

void CalendarItem::mousePressEvent(QMouseEvent *ev)
{
    qDebug()<<"hello"<<endl;
}

void CalendarItem::setDay(int day)
{
    lab_day->setText(QString("%1").arg(day));
    strDay=QString("%1").arg(day);
}


void CalendarItem::setPlanEnable(bool flag)
{
    flag_plan=flag;
}

void CalendarItem::setTodoEnable(bool flag)
{
    flag_todo=flag;
}

void CalendarItem::setSpecialEnable(bool flag)
{
    flag_special=flag;
}

void CalendarItem::setFestivalEnable(bool flag)
{
    flag_festival=flag;
}

void CalendarItem::changePlanAttribute()
{
    if(flag_plan)
    {
        QPalette palette;
        palette.setColor(QPalette::Background,QColor(255,0,0));
        lab_plan->setAutoFillBackground(true);
        lab_plan->setPalette(palette);
    }
    else
    {
        lab_plan->setAutoFillBackground(false);
    }
}

void CalendarItem::changeTodoAttribute()
{
    if(flag_todo&&flag_display)
    {
        QPalette palette;
        palette.setColor(QPalette::Background,QColor(0,255,0));
        lab_todo->setAutoFillBackground(true);
        lab_todo->setPalette(palette);
    }
    else
    {
        lab_todo->setAutoFillBackground(false);
    }
}

void CalendarItem::changeFestivalAttribute()
{
    if(flag_festival)
    {
        QPalette palette;
        palette.setColor(QPalette::Background,QColor(0,0,255));
        lab_festival->setAutoFillBackground(true);
        lab_festival->setPalette(palette);
    }
    else
    {
        lab_festival->setAutoFillBackground(false);
    }
}

void CalendarItem::changeSpecialAttribute()
{
    if(flag_special)
    {
        QPalette palette;
        palette.setColor(QPalette::Background,QColor(255,0,255));
        lab_special->setAutoFillBackground(true);
        lab_special->setPalette(palette);
    }
    else
    {
        lab_special->setAutoFillBackground(false);
    }
}

void CalendarItem::changeWeatherBG(const QString &weather)
{

//    QTextCodec* pCodec = QTextCodec::codecForName("UTF-8");

//    for(auto it=vec_transformWeathers.begin();it!=vec_transformWeathers.end();++it)
//    {

//        for(auto _it=it->begin();_it!=it->end();++_it)
//        {
//            qDebug()<<"index="<<it-vec_transformWeathers.begin()<<":"<<pCodec->fromUnicode(*_it)<<endl;
//        }
//    }

//    QByteArray tmp=pCodec->fromUnicode(weather);
//    int index=-1;
//    qDebug()<<"weather="<<tmp<<endl;
//    for(auto it=vec_transformWeathers.begin();it!=vec_transformWeathers.end();++it)
//    {

//        for(auto _it=it->begin();_it!=it->end();++_it)
//        {
//            if(!tmp.compare(*_it))
//            {
//                index=it-vec_transformWeathers.begin();
//                break;
//            }
//        }
//    }
//    if(index==SUNNY)
//        weatherPath=":/weather/ico/sunny.png";
//    if(index==RAINNY)
//        weatherPath=":/weather/ico/rain.png";
//    if(index==CLOUDY)
//        weatherPath=":/weather/ico/cloudy.png";
//    if(index==SNOWY)
//        weatherPath=":/weather/ico/snow.png";
//    if(index==OVERCAST)
//        weatherPath=":/weather/ico/overcast.png";

        if(weather=="晴")
            weatherPath=":/weather/ico/sunny.png";
        if(weather.contains("雨"))
            weatherPath=":/weather/ico/rain.png";
        if(weather=="多云")
            weatherPath=":/weather/ico/cloudy.png";
        if(weather.contains("雪"))
            weatherPath=":/weather/ico/snow.png";
        if(weather=="阴")
            weatherPath=":/weather/ico/overcast.png";


    if(img_weather.load(weatherPath))
    {
        this->setPixmap(QPixmap::fromImage(img_weather));
        this->resize(img_weather.size());
    }
    else {
        qDebug()<<"FALSE"<<endl;
    }
}


void CalendarItem::changeDisplayAttribute()
{

}

bool CalendarItem::isMonthDay()
{
    if(strDay=="-1")
        return false;
    else
        return true;
}

const QString& CalendarItem::getDay()
{
    return strDay;
}

const QString& CalendarItem::getMonth()
{
    return strMonth;
}

const QString& CalendarItem::getYear()
{
    return strYear;
}

const QDateTime& CalendarItem::getActivateDate()
{
    return calendarDate;
}

void CalendarItem::setYear(int year)
{
    strYear=QString("%1").arg(year);
}

void CalendarItem::setMonth(int month)
{
    strMonth=QString("%1").arg(month);
}

void CalendarItem::setActiveDate(const QDateTime &time)
{
    calendarDate=time;
}


CalendarItem::~CalendarItem()
{

    delete lab_day;
    delete lab_weather;
    delete lab_festival;
    delete lab_special;
    delete lab_plan;
    delete lab_todo;
    delete v_tagLayout;
    delete lab_tag;
    delete text_detail;
    delete vlayout;
    delete hlayout;



    lab_tag=nullptr;
    lab_day=nullptr;
    lab_weather=nullptr;
    lab_festival=nullptr;
    lab_special=nullptr;
    text_detail=nullptr;
    hlayout=nullptr;
    vlayout=nullptr;
    v_tagLayout=nullptr;
    lab_plan=nullptr;
    lab_todo=nullptr;

}
