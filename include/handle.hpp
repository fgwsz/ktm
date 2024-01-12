#pragma once
extern "C"{
#include<stdlib.h>
}
#include<unordered_map>
#include<stack>
#include"logger.hpp"
#include"keycode_of.hpp"
#include"keycode_to_name.hpp"
#include"keycode_has_name.hpp"
#include"mouse.hpp"
#include"ordered_set.hpp"
namespace handle_detail{
static inline void mouse_move_up          (void)noexcept;
static inline void mouse_move_down        (void)noexcept;
static inline void mouse_move_left        (void)noexcept;
static inline void mouse_move_right       (void)noexcept;
static inline void mouse_wheel_up         (void)noexcept;
static inline void mouse_wheel_down       (void)noexcept;
static inline void mouse_left_click       (void)noexcept;
static inline void mouse_left_double_click(void)noexcept;
static inline void mouse_right_click      (void)noexcept;
static inline void mouse_key_up           (void)noexcept;
static inline void mouse_left_down        (void)noexcept;
static inline void mouse_right_down       (void)noexcept;
static inline void mouse_dpixel_double    (void)noexcept;
static inline void mouse_dpixel_halve     (void)noexcept;
static inline void app_quit               (void)noexcept;
static ::std::unordered_map<DWORD,void(*)(void)noexcept> const key_down_handle_list={
    {KeyCodeOf::mouse_move_up          ,mouse_move_up          },
    {KeyCodeOf::mouse_move_down        ,mouse_move_down        },
    {KeyCodeOf::mouse_move_left        ,mouse_move_left        },
    {KeyCodeOf::mouse_move_right       ,mouse_move_right       },
    {KeyCodeOf::mouse_wheel_up         ,mouse_wheel_up         },
    {KeyCodeOf::mouse_wheel_down       ,mouse_wheel_down       },
    {KeyCodeOf::mouse_left_click       ,mouse_left_click       },
    {KeyCodeOf::mouse_left_double_click,mouse_left_double_click},
    {KeyCodeOf::mouse_right_click      ,mouse_right_click      },
    {KeyCodeOf::mouse_key_up           ,mouse_key_up           },
    {KeyCodeOf::mouse_left_down        ,mouse_left_down        },
    {KeyCodeOf::mouse_right_down       ,mouse_right_down       },
    {KeyCodeOf::mouse_dpixel_double    ,mouse_dpixel_double    },
    {KeyCodeOf::mouse_dpixel_halve     ,mouse_dpixel_halve     },
    {KeyCodeOf::app_quit               ,app_quit               }
};
static bool is_leader_down=false;
static bool is_mouse_left_down=false;
static bool is_mouse_right_down=false;
static constexpr Logger mouse_logger   ("[MOU] ");
static constexpr Logger cursor_logger  ("[CUR] ");
static constexpr Logger keyboard_logger("[KEY] ");
static constexpr Logger pixel_logger   ("[PIX] ");
static constexpr Logger wheel_logger   ("[WHE] ");
static constexpr Logger app_logger     ("[APP] ");
static OrderedSet<DWORD> key_down_set={};
#define _mouse_key_auto_up() do{ \
    if(::handle_detail::is_mouse_left_down){ \
        _Mouse_left_up(); \
        ::handle_detail::is_mouse_left_down=false; \
        ::handle_detail::mouse_logger.println_with_head("Left Up"); \
    }else if(::handle_detail::is_mouse_right_down){ \
        _Mouse_right_up(); \
        ::handle_detail::is_mouse_right_down=false; \
        ::handle_detail::mouse_logger.println_with_head("Right Up"); \
    } \
}while(0) \
//
void mouse_move_left(void)noexcept{ 
    _Mouse_move_left();
    cursor_logger.println_with_head(
        "← Pix{",_Mouse_current_dpixel,"} => ",_Mouse_current_position);
}
void mouse_move_down(void)noexcept{
    _Mouse_move_down();
    cursor_logger.println_with_head(
        "↓ Pix{",_Mouse_current_dpixel,"} => ",_Mouse_current_position);
}
void mouse_move_up(void)noexcept{
    _Mouse_move_up();
    cursor_logger.println_with_head(
        "↑ Pix{",_Mouse_current_dpixel,"} => ",_Mouse_current_position);
}
void mouse_move_right(void)noexcept{
    _Mouse_move_right();
    cursor_logger.println_with_head(
        "→ Pix{",_Mouse_current_dpixel,"} => ",_Mouse_current_position);
}
void mouse_wheel_up(void)noexcept{
    _Mouse_wheel_up();
    wheel_logger.println_with_head("↑ Pix{",_Mouse_current_dpixel,"}");
}
void mouse_wheel_down(void)noexcept{
    _Mouse_wheel_down();
    wheel_logger.println_with_head("↓ Pix{",_Mouse_current_dpixel,"}");
}
void app_quit(void)noexcept{
    app_logger.println_with_head("Quit");
    ::exit(0);
}
void mouse_dpixel_double(void)noexcept{
    _Mouse_current_dpixel=_Mouse_current_dpixel*2;
    pixel_logger.println_with_head("D_Pixel * 2 => ",_Mouse_current_dpixel);
}
void mouse_dpixel_halve(void)noexcept{
    _Mouse_current_dpixel=_Mouse_current_dpixel/2!=0
        ?_Mouse_current_dpixel/2
        :1;
    pixel_logger.println_with_head("D_Pixel / 2 => ",_Mouse_current_dpixel);
}
void mouse_key_up(void)noexcept{
    _mouse_key_auto_up();
}
void mouse_left_click(void)noexcept{
    _mouse_key_auto_up();
    _Mouse_left_click();
    mouse_logger.println_with_head("Left Click");
}
void mouse_left_double_click(void)noexcept{
    _mouse_key_auto_up();
    _Mouse_left_double_click();
    mouse_logger.println_with_head("Left Double Click");
}
void mouse_right_click(void)noexcept{
    _mouse_key_auto_up();
    _Mouse_right_click();
    mouse_logger.println_with_head("Right Click");
}
void mouse_left_down(void)noexcept{
    _mouse_key_auto_up();
    _Mouse_left_down();
    is_mouse_left_down=true;
    mouse_logger.println_with_head("Left Down");
}
void mouse_right_down(void)noexcept{
    _mouse_key_auto_up();
    _Mouse_right_down();
    is_mouse_right_down=true;
    mouse_logger.println_with_head("Right Down");
}
#define _println_key_down() do{ \
    ::handle_detail::keyboard_logger.print_with_head(); \
    ::handle_detail::key_down_set.for_each([](DWORD const& key){ \
        ::handle_detail::keyboard_logger.print("<",::keycode_to_name[key],">"); \
    }); \
    ::handle_detail::keyboard_logger.println(" Down"); \
}while(0) \
//
#define _println_key_up(__vk_code__) do{ \
    ::handle_detail::keyboard_logger.println_with_head( \
        "<",::keycode_to_name[DWORD(__vk_code__)],">", \
        " Up" \
    ); \
}while(0) \
//
#define _key_down_set_update() do{ \
    ::std::stack<DWORD> remove_keys; \
    ::handle_detail::key_down_set.for_each([&](DWORD const& key){ \
       if(::GetAsyncKeyState(key)&0x8000){}else{ /*按键未实际按下*/\
           remove_keys.push(key); \
       } \
    }); \
    while(!remove_keys.empty()){ \
        ::handle_detail::key_down_set.erase(remove_keys.top()); \
        _println_key_up(remove_keys.top()); \
        remove_keys.pop(); \
    } \
}while(0) \
//
#define _handle(__w_param__,__vk_code__) do{ \
    auto _w_param=WPARAM(__w_param__); \
    auto _vk_code=DWORD(__vk_code__); \
    /*<X>单键和<ALT-X>组合键以及其他组合键按下时*/ \
    if (_w_param==WM_KEYDOWN||_w_param==WM_SYSKEYDOWN) { \
        /*防止其他进程把全局键盘事件截获，造成逻辑上的bug*/ \
        _key_down_set_update(); \
        if(::keycode_has_name[_vk_code]&&!::handle_detail::key_down_set.has(_vk_code)){ \
            ::handle_detail::key_down_set.insert(_vk_code); \
            _println_key_down(); \
        } \
        if(_vk_code==KeyCodeOf::leader){ \
            ::handle_detail::is_leader_down=true; \
        } \
        else if(::handle_detail::is_leader_down&& \
                ::handle_detail::key_down_handle_list.count(_vk_code)!=0){ \
            ::handle_detail::key_down_handle_list.at(_vk_code)(); \
        } \
    } \
    /*<X>单键和<ALT-X>组合键以及其他组合键抬起时*/ \
    else if (_w_param==WM_KEYUP||_w_param==WM_SYSKEYUP) { \
        ::handle_detail::key_down_set.erase(_vk_code); \
        _key_down_set_update(); \
        if(_vk_code==KeyCodeOf::leader){ \
            ::handle_detail::is_leader_down=false; \
        } \
        _println_key_up(_vk_code); \
    } \
}while(0) \
//
}// namespace handle_detail