#pragma once
#include<Windows.h>
class Mouse{
    static void _mouse_click(DWORD dw_flags)noexcept;
    static void _mouse_move(LONG dx,LONG dy)noexcept;
    static void _mouse_wheel(DWORD scroll_amount)noexcept;
public:
    static void mouse_left_down()noexcept;
    static void mouse_left_up()noexcept;
    static void mouse_right_down()noexcept;
    static void mouse_right_up()noexcept;
    static void mouse_left_click()noexcept;
    static void mouse_left_double_click()noexcept;
    static void mouse_right_click()noexcept;
    static void mouse_move_up()noexcept;
    static void mouse_move_down()noexcept;
    static void mouse_move_left()noexcept;
    static void mouse_move_right()noexcept;
    static void mouse_wheel_up()noexcept;
    static void mouse_wheel_down()noexcept;
    struct Position{
        long x,y;
    };
    static Position mouse_position()noexcept;
    static DWORD current_dpixel_;
    static constexpr DWORD const default_dpixel_=32;
};
DWORD Mouse::current_dpixel_=Mouse::default_dpixel_;
void Mouse::_mouse_click(DWORD dw_flags)noexcept{
    INPUT input;
    input.type=INPUT_MOUSE;
    input.mi.dwFlags=dw_flags;
    input.mi.dx=0;
    input.mi.dy=0;
    input.mi.mouseData=0;
    input.mi.dwExtraInfo=0;
    input.mi.time=0;
    ::SendInput(1,&input,sizeof(INPUT));
}
void Mouse::_mouse_move(LONG dx,LONG dy)noexcept{
    POINT cursor_pos;
    ::GetCursorPos(&cursor_pos);
    ::SetCursorPos(cursor_pos.x+dx,cursor_pos.y+dy);
}
void Mouse::_mouse_wheel(DWORD scroll_amount)noexcept{
    INPUT input;
    input.type=INPUT_MOUSE;
    input.mi.dwFlags=MOUSEEVENTF_WHEEL;
    input.mi.mouseData=scroll_amount;
    input.mi.time=0;
    input.mi.dwExtraInfo=0;
    ::SendInput(1,&input,sizeof(INPUT));
}
void Mouse::mouse_left_down()noexcept{
    Mouse::_mouse_click(MOUSEEVENTF_LEFTDOWN);
}
void Mouse::mouse_left_up()noexcept{
    Mouse::_mouse_click(MOUSEEVENTF_LEFTUP);
}
void Mouse::mouse_right_down()noexcept{
    Mouse::_mouse_click(MOUSEEVENTF_RIGHTDOWN);
}
void Mouse::mouse_right_up()noexcept{
    Mouse::_mouse_click(MOUSEEVENTF_RIGHTUP);
}
void Mouse::mouse_left_click()noexcept{
    Mouse::_mouse_click(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP);
}
void Mouse::mouse_left_double_click()noexcept{
    Mouse::mouse_left_click();
    Mouse::mouse_left_click();
}
void Mouse::mouse_right_click()noexcept{
    Mouse::_mouse_click(MOUSEEVENTF_RIGHTDOWN|MOUSEEVENTF_RIGHTUP);
}
void Mouse::mouse_move_up()noexcept{
    Mouse::_mouse_move(0,-static_cast<LONG>(Mouse::current_dpixel_));
}
void Mouse::mouse_move_down()noexcept{
    Mouse::_mouse_move(0,static_cast<LONG>(Mouse::current_dpixel_));
}
void Mouse::mouse_move_left()noexcept{
    Mouse::_mouse_move(-static_cast<LONG>(Mouse::current_dpixel_),0);
}
void Mouse::mouse_move_right()noexcept{
    Mouse::_mouse_move(static_cast<LONG>(Mouse::current_dpixel_),0);
}
void Mouse::mouse_wheel_up()noexcept{
    Mouse::_mouse_wheel(static_cast<LONG>(Mouse::current_dpixel_));
}
void Mouse::mouse_wheel_down()noexcept{
    Mouse::_mouse_wheel(-static_cast<LONG>(Mouse::current_dpixel_));
}
typename Mouse::Position Mouse::mouse_position()noexcept{
    POINT point;
    ::GetCursorPos(&point);
    return {point.x,point.y};
}
template<typename OutputStream>
OutputStream& operator<<(OutputStream& os,typename Mouse::Position const& pos)noexcept{
    return os<<"Pos("<<pos.x<<','<<pos.y<<')';
}
