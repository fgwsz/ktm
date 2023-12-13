#pragma once
#include"key_code.hpp"
// 快捷键设置
struct KeyCodeOf{
static constexpr DWORD leader                 =KeyCode_LeftAlt;
static constexpr DWORD mouse_move_up          =KeyCode_K      ;// Vim K
static constexpr DWORD mouse_move_down        =KeyCode_J      ;// Vim J
static constexpr DWORD mouse_move_left        =KeyCode_H      ;// Vim H
static constexpr DWORD mouse_move_right       =KeyCode_L      ;// Vim L
static constexpr DWORD mouse_wheel_up         =KeyCode_B      ;// Back
static constexpr DWORD mouse_wheel_down       =KeyCode_N      ;// Next
static constexpr DWORD mouse_left_click       =KeyCode_O      ;// GameBoy O
static constexpr DWORD mouse_left_double_click=KeyCode_A      ;// GameBoy A
static constexpr DWORD mouse_right_click      =KeyCode_X      ;// GameBoy X
static constexpr DWORD mouse_key_up           =KeyCode_U      ;// Up or Undo
static constexpr DWORD mouse_left_down        =KeyCode_G      ;// Get
static constexpr DWORD mouse_right_down       =KeyCode_I      ;// Invert
static constexpr DWORD mouse_dpixel_double    =KeyCode_2      ;// * 2
static constexpr DWORD mouse_dpixel_halve     =KeyCode_Hyphen ;// - Decrease
static constexpr DWORD app_quit               =KeyCode_Q      ;// Quit
};
