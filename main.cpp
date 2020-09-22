#include "calendar.h"
#include<QTextCodec>
#include <QApplication>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QApplication a(argc, argv);

    Calendar w;
    w.show();
    return a.exec();
}
