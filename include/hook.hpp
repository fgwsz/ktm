#pragma once
#include"handle.hpp"
namespace hook_detail{
// 全局键盘钩子回调函数
static inline LRESULT CALLBACK callback(int n_code,WPARAM w_param,LPARAM l_param)noexcept{
    if (n_code==HC_ACTION){
        _handle(w_param,((KBDLLHOOKSTRUCT*)l_param)->vkCode);
    }
    return ::CallNextHookEx(NULL,n_code,w_param,l_param);
}
static constexpr Logger hook_logger("[HOO] ");
class Hook final{// 全局钩子外覆类
    HHOOK h_hook_;
public:
    inline Hook(HHOOK h_hook)noexcept
        :h_hook_(h_hook){
        if(this->h_hook_){
            hook_logger.println_with_head("Install Ok");
        }else{
            hook_logger.println_with_head("Install Error");
            ::exit(1);
        }
    }
    inline ~Hook(void)noexcept{// 析构时自动卸载全局钩子
        if(this->h_hook_&&::UnhookWindowsHookEx(this->h_hook_)){
            hook_logger.println_with_head("Uninstall Ok");
        }else{
            hook_logger.println_with_head("Uninstall Error");
        }
    }
};
// 安装全局键盘钩子
// 设置为静态变量的原因：
// 在进程结束时自动回收静态变量，从而调用析构函数卸载全局钩子
static Hook const h_hook={SetWindowsHookEx(WH_KEYBOARD_LL,callback,NULL,0)};
}//namespace hook_detail
#define _message_loop() do{ \
    MSG msg; \
    while (GetMessage(&msg,NULL,0,0)){ \
        ::TranslateMessage(&msg); \
        DispatchMessage(&msg); \
    } \
}while(0) \
//