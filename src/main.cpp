#include"config.hpp"
#define CONSOLE_ENABLE true // 设置控制台是否可用
#if CONSOLE_ENABLE
    #define LOGGER_GLOBAL_ENABLE true
#else
    //不显示控制台窗口
    #pragma comment(linker,"/subsystem:windows /entry:mainCRTStartup")
    #define LOGGER_GLOBAL_ENABLE false
#endif
static bool const logger_global_enable=[]{
    Logger::set_global_enable(LOGGER_GLOBAL_ENABLE);
    return LOGGER_GLOBAL_ENABLE;
}();
int main()noexcept{
    _message_loop();
    return 0;
}
