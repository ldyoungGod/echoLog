#include "log_echo.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <dirent.h>
#include <unistd.h>

enum FRONT_COLOR
{
    BLACK = 30,//黑
    RED,//红
    GREEN,//绿
    YELLOW,//黄色
    BLUE,//蓝色
    VIOLET,//紫色
    DARK_GREEN,//深绿
    WRITE//白色
};

enum BACK_COLOR
{
    _NULL_COLOR,
    _BLACK = 40,//黑
    _DARK_RED,//深红
    _GREEN,//绿
    _YELLOW,//黄色
    _BLUE,//蓝色
    _VIOLET,//紫色
    _DARK_GREEN,//深绿
    _WRITE//白色
};

void log_echo::Info(const char* _fmt,...)
{
    char xbuf[8192] = { 0 };

    va_list arg;
    va_start(arg, _fmt);
    vsnprintf(xbuf, sizeof(xbuf), _fmt, arg);
    va_end(arg);
    log_echo::_echoLog(xbuf,0);
}

void log_echo::Debug(const char* _fmt,...)
{
    char xbuf[8192] = { 0 };

    va_list arg;
    va_start(arg, _fmt);
    vsnprintf(xbuf, sizeof(xbuf), _fmt, arg);
    va_end(arg);
    log_echo::_echoLog(xbuf,1);
}

void log_echo::Warn(const char* _fmt,...)
{
    char xbuf[8192] = { 0 };

    va_list arg;
    va_start(arg, _fmt);
    vsnprintf(xbuf, sizeof(xbuf), _fmt, arg);
    va_end(arg);
    log_echo::_echoLog(xbuf,2);
}

void log_echo::Error(const char* _fmt,...)
{
    char xbuf[8192] = { 0 };

    va_list arg;
    va_start(arg, _fmt);
    vsnprintf(xbuf, sizeof(xbuf), _fmt, arg);
    va_end(arg);
    log_echo::_echoLog(xbuf,3);
}

void log_echo::_echoLog(std::string str, int level)
{
    switch (level)
    {
    case 0:
        printf("[%s]-[info]:\033[%d;%dm%s\033[0m", log_echo::unix_time().c_str(),_NULL_COLOR,BLACK, str.c_str());
        break;
    case 1:
        printf("[%s]-[debug]:\033[%d;%dm%s\033[0m", log_echo::unix_time().c_str(),_NULL_COLOR,GREEN, str.c_str());
        break;
    case 2:
        printf("[%s]-[warn]:\033[%d;%dm%s\033[0m", log_echo::unix_time().c_str(),_BLACK,YELLOW, str.c_str());
        break;
    case 3:
        printf("[%s]-[error]:\033[%d;%dm%s\033[0m", log_echo::unix_time().c_str(),_VIOLET,RED, str.c_str());
        break;
    default:
        break;
    }
}

std::string log_echo::unix_time()
{
    time_t tv_sec = time(nullptr);
    char buf[64] = {0};
//    struct timeval tmVal;
//    gettimeofday(&tmVal,nullptr);
//    sprintf(buf,"%ld",tmVal.tv_usec/1000);
    struct tm nowtime;
    localtime_r(&tv_sec, &nowtime);

    sprintf(buf,
            "%04d-%02d-%02d %02d:%02d:%02d",
            nowtime.tm_year + 1900,
            nowtime.tm_mon + 1,
            nowtime.tm_mday,
            nowtime.tm_hour,
            nowtime.tm_min,
            nowtime.tm_sec);

    return buf;
}
