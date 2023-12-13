#pragma once
#include"handle.hpp"
// 全局键盘钩子回调函数
static LRESULT CALLBACK keyBoardCallBack(int n_code, WPARAM w_param, LPARAM l_param) {
    static KBDLLHOOKSTRUCT* p_key_data=nullptr;
    if (n_code == HC_ACTION) {
        p_key_data = (KBDLLHOOKSTRUCT*)l_param;
        handle(w_param,p_key_data->vkCode);
    }
    return CallNextHookEx(NULL, n_code, w_param, l_param);
}
static Logger hook_logger(true,"[HOO] ");
// 全局钩子外覆类
class Hook final{
    HHOOK h_hook_;
public:
    Hook(HHOOK h_hook):h_hook_(h_hook){
        if(this->h_hook_){
            hook_logger.println("HOOK INSTALL OK");
        }else{
            hook_logger.println("HOOK INSTALL ERROR");
            exit(1);
        }
    }
    // 析构时自动卸载全局钩子
    ~Hook(){
        if(this->h_hook_&&UnhookWindowsHookEx(this->h_hook_)){
            hook_logger.println("HOOK UNINSTALL OK");
        }else{
            hook_logger.println("HOOK UNINSTALL ERROR");
        }
    }
};
// 安装全局键盘钩子
// 设置为静态变量的原因：
// 在进程结束时自动回收静态变量，从而调用析构函数卸载全局钩子
static Hook h_hook={SetWindowsHookEx(WH_KEYBOARD_LL, keyBoardCallBack, NULL, 0)};
// 消息循环
static void message_loop(){
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
