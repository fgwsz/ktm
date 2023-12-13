#pragma once
#include<Windows.h>
class Mouse{
    static void _mouseClick(DWORD dw_flags);
    static void _mouseMove(LONG dx,LONG dy);
    static void _mouseWheel(DWORD scroll_amount);
public:
    static void mouseLeftDown();
    static void mouseLeftUp();
    static void mouseRightDown();
    static void mouseRightUp();
    static void mouseLeftClick();
    static void mouseLeftDoubleClick();
    static void mouseRightClick();
    static void mouseMoveUp();
    static void mouseMoveDown();
    static void mouseMoveLeft();
    static void mouseMoveRight();
    static void mouseWheelUp();
    static void mouseWheelDown();
    struct Position{
        int x;
        int y;
    };
    static void mousePosition(Position& position);
    static DWORD current_dpixel_;
    static constexpr DWORD const default_dpixel_=32;
};
DWORD Mouse::current_dpixel_=Mouse::default_dpixel_;
void Mouse::_mouseClick(DWORD dw_flags){
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = dw_flags;
    input.mi.dx = 0;
    input.mi.dy = 0;
    input.mi.mouseData = 0;
    input.mi.dwExtraInfo = 0;
    input.mi.time = 0;
    SendInput(1, &input, sizeof(INPUT));
}
void Mouse::_mouseMove(LONG dx,LONG dy){
    POINT cursor_pos;
    GetCursorPos(&cursor_pos);
    SetCursorPos(cursor_pos.x+dx, cursor_pos.y+dy);
}
void Mouse::_mouseWheel(DWORD scroll_amount){
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    input.mi.mouseData = scroll_amount;
    input.mi.time = 0;
    input.mi.dwExtraInfo = 0;
    SendInput(1, &input, sizeof(INPUT));
}
void Mouse::mouseLeftDown(){
    Mouse::_mouseClick(MOUSEEVENTF_LEFTDOWN);
}
void Mouse::mouseLeftUp(){
    Mouse::_mouseClick(MOUSEEVENTF_LEFTUP);
}
void Mouse::mouseRightDown(){
    Mouse::_mouseClick(MOUSEEVENTF_RIGHTDOWN);
}
void Mouse::mouseRightUp(){
    Mouse::_mouseClick(MOUSEEVENTF_RIGHTUP);
}
void Mouse::mouseLeftClick() {
    Mouse::_mouseClick(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP);
}
void Mouse:: mouseLeftDoubleClick() {
    Mouse::mouseLeftClick();
    Mouse::mouseLeftClick();
}
void Mouse:: mouseRightClick() {
    Mouse::_mouseClick(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP);
}
void Mouse:: mouseMoveUp(){
    Mouse::_mouseMove(0,-static_cast<LONG>(Mouse::current_dpixel_));
}
void Mouse:: mouseMoveDown(){
    Mouse::_mouseMove(0,static_cast<LONG>(Mouse::current_dpixel_));
}
void Mouse:: mouseMoveLeft(){
    Mouse::_mouseMove(-static_cast<LONG>(Mouse::current_dpixel_),0);
}
void Mouse:: mouseMoveRight(){
    Mouse::_mouseMove(static_cast<LONG>(Mouse::current_dpixel_),0);
}
void Mouse:: mouseWheelUp(){
    Mouse::_mouseWheel(static_cast<LONG>(Mouse::current_dpixel_));
}
void Mouse:: mouseWheelDown(){
    Mouse::_mouseWheel(-static_cast<LONG>(Mouse::current_dpixel_));
}
void Mouse::mousePosition(Mouse::Position& position){
    POINT point;
    GetCursorPos(&point);
    position.x=point.x;
    position.y=point.y;
}
