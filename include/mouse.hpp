#pragma once
#include<Windows.h>
struct Mouse{
    struct Position{
        long x,y;
    };
    static inline Position mouse_position()noexcept{
        POINT point;
        ::GetCursorPos(&point);
        return {point.x,point.y};
    }
    template<typename OutputStream>
    friend inline OutputStream& operator<<(
        OutputStream& os,
        typename Mouse::Position const& pos
    )noexcept{
        return os<<"Pos("<<pos.x<<','<<pos.y<<')';
    }
    static constexpr DWORD const default_dpixel_=32;
    static DWORD current_dpixel_;
};
DWORD Mouse::current_dpixel_=Mouse::default_dpixel_;
#define _Mouse_mouse_click(__dw_flags__) do{ \
    INPUT input; \
    input.type=INPUT_MOUSE; \
    input.mi.dwFlags=DWORD(__dw_flags__); \
    input.mi.dx=0; \
    input.mi.dy=0; \
    input.mi.mouseData=0; \
    input.mi.dwExtraInfo=0; \
    input.mi.time=0; \
    ::SendInput(1,&input,sizeof(INPUT)); \
}while(0) \
//
#define _Mouse_mouse_move(__dx__,__dy__) do{ \
    POINT cursor_pos;\
    ::GetCursorPos(&cursor_pos); \
    ::SetCursorPos(cursor_pos.x+LONG(__dx__),cursor_pos.y+LONG(__dy__)); \
}while(0) \
//
#define _Mouse_mouse_wheel(__scroll_amount__) do{ \
    INPUT input; \
    input.type=INPUT_MOUSE; \
    input.mi.dwFlags=MOUSEEVENTF_WHEEL; \
    input.mi.mouseData=DWORD(__scroll_amount__); \
    input.mi.time=0; \
    input.mi.dwExtraInfo=0; \
    ::SendInput(1,&input,sizeof(INPUT)); \
}while(0) \
//
#define _Mouse_mouse_left_down() do{ \
    _Mouse_mouse_click(MOUSEEVENTF_LEFTDOWN); \
}while(0) \
//
#define _Mouse_mouse_left_up() do{ \
    _Mouse_mouse_click(MOUSEEVENTF_LEFTUP); \
}while(0) \
//
#define _Mouse_mouse_right_down() do{ \
    _Mouse_mouse_click(MOUSEEVENTF_RIGHTDOWN); \
}while(0) \
//
#define _Mouse_mouse_right_up() do{ \
    _Mouse_mouse_click(MOUSEEVENTF_RIGHTUP); \
}while(0) \
//
#define _Mouse_mouse_left_click() do{ \
    _Mouse_mouse_click(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP);\
}while(0) \
//
#define _Mouse_mouse_left_double_click() do{ \
    _Mouse_mouse_left_click(); \
    _Mouse_mouse_left_click(); \
}while(0) \
//
#define _Mouse_mouse_right_click() do{ \
    _Mouse_mouse_click(MOUSEEVENTF_RIGHTDOWN|MOUSEEVENTF_RIGHTUP); \
}while(0) \
//
#define _Mouse_mouse_move_up() do{ \
    _Mouse_mouse_move(0,-static_cast<LONG>(Mouse::current_dpixel_)); \
}while(0) \
//
#define _Mouse_mouse_move_down() do{ \
    _Mouse_mouse_move(0,static_cast<LONG>(Mouse::current_dpixel_)); \
}while(0) \
//
#define _Mouse_mouse_move_left() do{ \
    _Mouse_mouse_move(-static_cast<LONG>(Mouse::current_dpixel_),0); \
}while(0) \
//
#define _Mouse_mouse_move_right() do{ \
    _Mouse_mouse_move(static_cast<LONG>(Mouse::current_dpixel_),0); \
}while(0) \
//
#define _Mouse_mouse_wheel_up() do{ \
    _Mouse_mouse_wheel(static_cast<LONG>(Mouse::current_dpixel_)); \
}while(0) \
//
#define _Mouse_mouse_wheel_down() do{ \
    _Mouse_mouse_wheel(-static_cast<LONG>(Mouse::current_dpixel_)); \
}while(0) \
//
