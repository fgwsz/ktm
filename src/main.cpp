#include"config.hpp"
int main() {
    #define DEBUG
    #ifdef DEBUG
        //显示打印信息
        Logger::setGlobalEnable(true);
    #else
        //不显示控制台窗口
        #pragma comment(linker,"/subsystem:windows /entry:mainCRTStartup")
        //不显示打印信息
        Logger::setGlobalEnable(false);
    #endif
    message_loop();
    return 0;
}
