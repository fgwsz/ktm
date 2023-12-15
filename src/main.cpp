#include"config.hpp"
int main() {
    #define CONSOLE_ENABLE
    #ifdef CONSOLE_ENABLE
        //显示打印信息
        Logger::set_global_enable(true);
    #else
        //不显示控制台窗口
        #pragma comment(linker,"/subsystem:windows /entry:mainCRTStartup")
        //不显示打印信息
        Logger::set_global_enable(false);
    #endif
    ::message_loop();
    return 0;
}
