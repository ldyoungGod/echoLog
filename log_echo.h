#ifndef LOG_ECHO_H
#define LOG_ECHO_H
#include <string>
/**
 * @brief 输出日志信息到屏幕
 */

class log_echo
{
public:
    static void Info(const char* _fmt,...);
    static void Debug(const char* _fmt,...);
    static void Warn(const char* _fmt,...);
    static void Error(const char* _fmt,...);
private:
    static void _echoLog(std::string str, int level/*0:info,1:debug,2:warn,3:error*/);
    static std::string unix_time();
};

#endif // LOG_ECHO_H
