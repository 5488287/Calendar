#include "calendar.h"
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
Calendar::Calendar(QWidget *parent)
    : QMainWindow(parent)
{
    currentDay=QDateTime::currentDateTime().toString("dd");
    currentMonth=QDateTime::currentDateTime().toString("MM");
    currentYear=QDateTime::currentDateTime().toString("yyyy");
    currentDateTime=QDateTime::currentDateTime();



    activeYear=currentYear;
    activeMonth=currentMonth;

    btn_priorYear=new QPushButton("Prior Year",this);
    btn_priorMonth=new QPushButton("Prior Month",this);

    btn_nextYear=new QPushButton("Next Year",this);
    btn_nextMonth=new QPushButton("Next Month",this);

    edt_year=new QLineEdit(this);
    edt_month=new QLineEdit(this);

    edt_year->setText(currentYear);
    edt_month->setText(currentMonth);

    widget_grid=new QWidget(this);
    widget_center=new QWidget(this);
    widget_control=new QWidget(this);

    hlayout=new QHBoxLayout(widget_control);
    vlayout=new QVBoxLayout(widget_center);
    hlayout->addWidget(btn_priorYear);
    hlayout->addWidget(btn_priorMonth);

    hlayout->addWidget(edt_year);
    hlayout->addWidget(edt_month);

    hlayout->addWidget(btn_nextMonth);
    hlayout->addWidget(btn_nextYear);

    widget_control->setLayout(hlayout);
    widget_control->setGeometry(this->width()/3,this->width()/6,this->width()/18,this->height()/16);


  //  this->setCentralWidget(widget_control);

    setWeekDayArrange(SUNFIRST,vec_weekDay);
    setCurrentCalendarPage();
    widget_grid->setLayout(glayout);
    vlayout->addWidget(widget_control);
    vlayout->addWidget(widget_grid);
    widget_center->setLayout(vlayout);
    this->setCentralWidget(widget_center);

    network=new Network();

    connect(btn_nextYear,SIGNAL(clicked()),this,SLOT(slot_setNextYear()));
    connect(btn_nextMonth,SIGNAL(clicked()),this,SLOT(slot_setNextMonth()));
    connect(btn_priorYear,SIGNAL(clicked()),this,SLOT(slot_setPriorYear()));
    connect(btn_priorMonth,SIGNAL(clicked()),this,SLOT(slot_setPriorMonth()));
    connect(network,SIGNAL(finish()),this,SLOT(slot_setCalendarWeather()));


//    network->setCity("jianggan");
//    network->setHead(QUrl("https://way.jd.com/he/freeweather?city="));
//    network->setAppkey("46faedfcfcaf5b3df72c9d64ac015b5b");
//    network->setSuffix("&appkey=");
//    QUrl url=network->constructUrl(QUrl("https://way.jd.com/he/freeweather?city="),"zibo","&appkey=","46faedfcfcaf5b3df72c9d64ac015b5b");
//    qDebug()<<"URL="<<url<<endl;

    qDebug()<<"QSSLSOCKET="<<QSslSocket::sslLibraryBuildVersionString()<<endl;
    qDebug()<<"zcqk="<<QSslSocket::supportsSsl()<<endl;
    network->get(QUrl("https://way.jd.com/he/freeweather?city=zibo&appkey=46faedfcfcaf5b3df72c9d64ac015b5b"));




}

int Calendar::getWeekNumStart()
{

    QDateTime yearFirstDay=QDateTime().fromString(activeYear+"01"+"01","yyyyMMdd");
    QDateTime monthFirstDay=QDateTime().fromString(activeYear+activeMonth+"01","yyyyMMdd");
    QString yearFirstDayWeek=yearFirstDay.toString("ddd");
    Week week= convertWeekDay2Week(yearFirstDayWeek);
    int monthDays=getMonthDays(activeYear,activeMonth);
    int dayGap=yearFirstDay.daysTo(monthFirstDay);
    int dayLast=7-week;
    int lastDay=dayGap-dayLast;
    int weeks=lastDay/7;
    int less=lastDay%7;
    return weeks;

}

void Calendar::setWeekNum(int start,int num)
{
    for(auto it=vec_weekNum.begin();it!=vec_weekNum.end();++it)
        delete *it;
    vec_weekNum.clear();
   for(int i=0;i!=num/7;++i)
   {
       QLabel *label=new QLabel(QString("%1").arg(start+i+1),widget_grid);
       vec_weekNum.push_back(label);
   }
   if(num%7)
   {
       QLabel *label=new QLabel(QString("%1").arg(start+num/7+1),widget_grid);
       vec_weekNum.push_back(label);
   }
}

void Calendar::setWeekDayArrange(WeekdayRange wr,QVector<QLabel*>& vec_weekDay)
{
    for(auto it=vec_weekNum.begin();it!=vec_weekNum.end();++it)
        delete *it;
    vec_weekNum.clear();
    QLabel *lab1,*lab2,*lab3,*lab4,*lab5,*lab6,*lab7;

    if(wr==SUNFIRST)
    {
        lab1=new QLabel("周天",widget_grid);
        lab2=new QLabel("周一",widget_grid);
        lab3=new QLabel("周二",widget_grid);
        lab4=new QLabel("周三",widget_grid);
        lab5=new QLabel("周四",widget_grid);
        lab6=new QLabel("周五",widget_grid);
        lab7=new QLabel("周六",widget_grid);

    }
    if(wr==MONFIRST)
    {
        lab1=new QLabel("周一",widget_grid);
        lab2=new QLabel("周二",widget_grid);
        lab3=new QLabel("周三",widget_grid);
        lab4=new QLabel("周四",widget_grid);
        lab5=new QLabel("周五",widget_grid);
        lab6=new QLabel("周六",widget_grid);
        lab7=new QLabel("周天",widget_grid);
    }
    vec_weekDay.push_back(lab1);
    vec_weekDay.push_back(lab2);
    vec_weekDay.push_back(lab3);
    vec_weekDay.push_back(lab4);
    vec_weekDay.push_back(lab5);
    vec_weekDay.push_back(lab6);
    vec_weekDay.push_back(lab7);

}

Calendar::Week Calendar::convertWeekDay2Week(QString &str)
{
    if(str=="周一")
        return MONDAY;
    if(str=="周二")
        return TUESDAY;
    if(str=="周三")
        return WEDNSDAY;
    if(str=="周四")
        return THURSDAY;
    if(str=="周五")
        return FRIDAY;
    if(str=="周六")
        return SATURDAY;
    if(str=="周日")
        return SUNDAY;
}
int Calendar::getMonthDays(const QString&year,const QString&month)
{
    if(month=="02"&&isLeapYear(year))
        return 29;
    if(month=="02")
        return 28;
    if(month=="01"||month=="03"||month=="05"||month=="07"||month=="08"||month=="10"||month=="12")
        return 31;
    return 30;
}

bool Calendar::isLeapYear(QString year)
{
    int y=year.toUInt();
    if(!(y%4)&&(y%100))
        return true;
    return false;
}

void Calendar::setCurrentCalendarPage()
{

    for(auto it=calendarList.begin();it!=calendarList.end();++it)
        delete *it;

    calendarList.clear();
    QDateTime firstDay=QDateTime().fromString(activeYear+activeMonth+"01","yyyyMMdd");
    QString firstDayWeek=firstDay.toString("ddd");


    Week week= convertWeekDay2Week(firstDayWeek);
    int monthDays=getMonthDays(activeYear,activeMonth);
    int dayLast=7-week;
    int anotherDays=monthDays-dayLast;
    int tailDays=anotherDays%7;


    for(int i=7;i!=dayLast;--i)
    {
       CalendarItem * im=new CalendarItem();
       calendarList.push_back(im);
    }
    qDebug()<<"TOP size="<<calendarList.size()<<endl;
    for(int i=0;i!=dayLast;++i)
    {
        CalendarItem *im=new CalendarItem();
        im->setDay(i+1);
        im->setMonth(activeMonth.toInt());
        im->setYear(activeYear.toInt());
        im->setActiveDate(QDateTime::fromString(QString(activeYear+"-"+activeMonth+"-"+"%1").arg(i+1)));
        calendarList.push_back(im);

    }
    qDebug()<<"START size="<<calendarList.size()<<endl;
    for(int i=0;i!=anotherDays-tailDays;++i)
    {
        CalendarItem *im=new CalendarItem();
        im->setDay(dayLast+1+i);
        calendarList.push_back(im);
    }
    qDebug()<<"MAIN size="<<calendarList.size()<<endl;
    for(int i=monthDays-tailDays;i!=monthDays;++i)
    {
        CalendarItem *im=new CalendarItem();
        im->setDay(i+1);
        calendarList.push_back(im);
    }

    qDebug()<<"TAIL size="<<calendarList.size()<<endl;

    for(int i=7-tailDays;i!=0;--i)
    {
        CalendarItem *im=new CalendarItem();
        calendarList.push_back(im);
    }


   glayout=new QGridLayout(widget_grid);
   int index=0;
   for(auto it=vec_weekDay.begin();it!=vec_weekDay.end();++it)
   {
       int index =it-vec_weekDay.begin();
       glayout->addWidget(*it,0,index+1);
   }
   int weekNumStart=getWeekNumStart();
   setWeekNum(weekNumStart,calendarList.size());
   for(auto it=vec_weekNum.begin();it!=vec_weekNum.end();++it)
   {
       int index=it-vec_weekNum.begin();
       glayout->addWidget(*it,index+1,0);
   }
   for(auto it=calendarList.begin();it!=calendarList.end();++it)
   {
       index=it-calendarList.begin();
       glayout->addWidget(*it,index/7+1,index%7+1);

   }
   widget_grid->setLayout(glayout);
   qDebug()<<"size="<<calendarList.size()<<endl;
}

void Calendar::slot_setCalendarWeather()
{
    weather=network->getWeatherContent();
    QDateTime time=QDateTime::currentDateTime();
    QVector<QString> vec_weather;
    for(int i=0;i!=7;++i)
    {
    QDateTime anotherDay=time.addDays(i);
    QString strTmp=anotherDay.toString("yyyy-MM-dd");
     QDateTime tmp=QDateTime::fromString(strTmp,"yyyy-MM-dd");
     qDebug()<<"Date="<<tmp<<endl;
     WeatherItem item=weather.findWeatherInfoByDateTime(tmp);
     vec_weather.push_back(item.getTxt_d());
    calendarList.at(currentDay.toInt()+1+i)->changeWeatherBG(item.getTxt_d());
    }
for(auto it=vec_weather.begin();it!=vec_weather.end();++it)
    qDebug()<<"weather="<<*it<<endl;

}
void Calendar::slot_setNextYear()
{
    delete glayout;
    QString tmp;
    int year=activeYear.toInt()+1;
    if(year>=1000)
        tmp=QString("%1").arg(year);
    if(year<1000)
        tmp="0"+QString("%1").arg(year);
    if(year<100)
        tmp="0"+tmp;
    if(year<10)
        tmp="0"+tmp;
    activeYear=tmp;
    edt_year->setText(activeYear);
    setCurrentCalendarPage();
}

void Calendar::slot_setNextMonth()
{
    delete glayout;
    QString tmp;
    int month=activeMonth.toInt()+1;
    if(month<10)
        tmp="0"+QString("%1").arg(month);
    else
        tmp=QString("%1").arg(month);
    activeMonth=tmp;
    edt_month->setText(activeMonth);
    setCurrentCalendarPage();
}

void Calendar::slot_setPriorYear()
{
    delete glayout;
    QString tmp;
    int year=activeYear.toInt()-1;
    if(year>=1000)
        tmp=QString("%1").arg(year);
    tmp=QString("%1").arg(year);
    if(year<1000)
        tmp="0"+QString("%1").arg(year);
    if(year<100)
        tmp="0"+tmp;
    if(year<10)
        tmp="0"+tmp;
    activeYear=tmp;
    edt_year->setText(activeYear);
    setCurrentCalendarPage();
}

void Calendar::slot_setPriorMonth()
{
    delete glayout;
    QString tmp;
    int month=activeMonth.toInt()-1;
    if(month<10)
        tmp="0"+QString("%1").arg(month);
    else
        tmp=QString("%1").arg(month);
    activeMonth=tmp;
    edt_month->setText(activeMonth);
    setCurrentCalendarPage();
}

void Calendar::readCalendarXML(QString &path)
{


}

void Calendar::saveCalendar2XML(QString&path)
{
//    QFile file(path);
//    if(!file.open(QFile::WriteOnly|QFile::Truncate))
//        return;
//    QDomDocument doc;
//    QDomProcessingInstruction instruction;

//    instruction=doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");

//    doc.appendChild(instruction);

//    QDomElement root=doc.createElement("Calendar");

//    doc.appendChild(root);

//    for(auto it= vec_imageCell.begin();it!= vec_imageCell.end();++it)
//    {
//        State state = (*it)->getState();
//    QDomElement entry=doc.createElement("tag");
//    entry.setAttribute("kind", state.kind);


//    QDomText t_path;
//    QString _path = (*it)->getPath();
//    t_path=doc.createTextNode(_path);
//    QDomElement path=doc.createElement("path");
//    path.appendChild(t_path);
//    entry.appendChild(path);



//    if(state.kind!=-1)
//    {
//    QDomText t_roll,t_yaw,t_pitch;
//    QDomElement angle=doc.createElement("angle");

//    t_yaw=doc.createTextNode(QString("%1").arg(state.angle.yaw));
//    QDomElement yaw=doc.createElement("yaw");

//    t_pitch=doc.createTextNode(QString("%1").arg(state.angle.pitch));
//    QDomElement pitch=doc.createElement("pitch");

//    t_roll=doc.createTextNode(QString("%1").arg(state.angle.roll));
//    QDomElement roll=doc.createElement("roll");



//    yaw.appendChild(t_yaw);
//    pitch.appendChild(t_pitch);
//    roll.appendChild(t_roll);

//    angle.appendChild(yaw);
//    angle.appendChild(pitch);
//    angle.appendChild(roll);

//    entry.appendChild(angle);

//    QDomElement pos=doc.createElement("Pos");
//    QDomText t_posX,t_posY,t_posZ;
//    QDomElement posX,posY,posZ;

//    posX=doc.createElement("X");
//    t_posX=doc.createTextNode(QString("%1").arg(state.pos.x));

//    posY=doc.createElement("Y");
//    t_posY=doc.createTextNode(QString("%1").arg(state.pos.y));


//    posZ=doc.createElement("Z");
//    t_posZ=doc.createTextNode(QString("%1").arg(state.pos.z));


//    pos.appendChild(posX);
//    pos.appendChild(posY);
//    pos.appendChild(posZ);

//    posX.appendChild(t_posX);
//    posY.appendChild(t_posY);
//    posZ.appendChild(t_posZ);

//    entry.appendChild(pos);

//    }

//    root.appendChild(entry);

//    }

//    QTextStream outStream(&file);
//    doc.save(outStream,4);
//    file.close();
}

void Calendar::newRecord(const QDateTime&date,const Info&info)
{
    if(mapCalendarInfo.find(date).value().isEmpty())
    {
        Info info;
        mapCalendarInfo.insert(QDateTime::fromString(currentYear+"-"+currentMonth+"-"+currentDay,"yyyy-MM-dd"),info);
    }
}

CalendarItem* Calendar::find(QDateTime &date)
{
    QString year=QString("%1").arg(date.date().year());
    QString month=QString("%1").arg(date.date().month());
    QString day=QString("%1").arg(date.date().day());
    for(auto it=calendarList.begin();it!=calendarList.end();++it)
    {
        QString _year=(*it)->getYear();
        QString _month=(*it)->getMonth();
        QString _day=(*it)->getDay();
        if(_year==year&&_month==month&&_day==day)
            return *it;
    }
}

