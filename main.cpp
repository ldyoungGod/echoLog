#include <iostream>
#include <vector>
#include "log_echo.h"

using namespace std;


int main(int argc, char *argv[])
{
    log_echo::Info("%s\n","你好INFO");
    log_echo::Debug("%s\n","你好DEBUG");
    log_echo::Warn("%s\n","你好WARN");
    log_echo::Error("%s\n","你好ERROR");
    return 0;
}
