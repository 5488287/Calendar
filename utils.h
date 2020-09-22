#ifndef TOOL_H
#define TOOL_H
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
#include"otherhead.h"
#include"texthead.h"
#include"weather.h"
void parseWeatherJson(const QByteArray&data,Weather&weather);
#endif // TOOL_H
