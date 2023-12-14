#pragma once
#include<unordered_map>
#include<stack>
#include"logger.hpp"
#include"keycode_of.hpp"
#include"keyboard.hpp"
#include"mouse.hpp"
#include"ordered_set.hpp"
namespace handle_detail{
static void mouse_move_up          ()noexcept;
static void mouse_move_down        ()noexcept;
static void mouse_move_left        ()noexcept;
static void mouse_move_right       ()noexcept;
static void mouse_wheel_up         ()noexcept;
static void mouse_wheel_down       ()noexcept;
static void mouse_left_click       ()noexcept;
static void mouse_left_double_click()noexcept;
static void mouse_right_click      ()noexcept;
static void mouse_key_up           ()noexcept;
static void mouse_left_down        ()noexcept;
static void mouse_right_down       ()noexcept;
static void mouse_dpixel_double    ()noexcept;
static void mouse_dpixel_halve     ()noexcept;
static void app_quit               ()noexcept;
static ::std::unordered_map<DWORD,void(*)()noexcept> const key_down_handle_list={
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
static Logger const mouse_logger   ("[MOU] ");
static Logger const cursor_logger  ("[CUR] ");
static Logger const keyboard_logger("[KEY] ");
static Logger const pixel_logger   ("[PIX] ");
static Logger const wheel_logger   ("[WHE] ");
static Logger const app_logger     ("[APP] ");
static OrderedSet<DWORD> key_down_set={};
static void mouse_key_auto_up()noexcept{
    if(is_mouse_left_down){
        Mouse::mouse_left_up();
        is_mouse_left_down=false;
        mouse_logger.println_with_head("Left Up");
    }else if(is_mouse_right_down){
        Mouse::mouse_right_up();
        is_mouse_right_down=false;
        mouse_logger.println_with_head("Right Up");
    }
}
static void mouse_move_left()noexcept{ 
    Mouse::mouse_move_left();
    cursor_logger.println_with_head(
        "← Pix{",Mouse::current_dpixel_,"} => ",Mouse::mouse_position());
}
static void mouse_move_down()noexcept{
    Mouse::mouse_move_down();
    cursor_logger.println_with_head(
        "↓ Pix{",Mouse::current_dpixel_,"} => ",Mouse::mouse_position());
}
static void mouse_move_up()noexcept{
    Mouse::mouse_move_up();
    cursor_logger.println_with_head(
        "↑ Pix{",Mouse::current_dpixel_,"} => ",Mouse::mouse_position());
}
static void mouse_move_right()noexcept{
    Mouse::mouse_move_right();
    cursor_logger.println_with_head(
        "→ Pix{",Mouse::current_dpixel_,"} => ",Mouse::mouse_position());
}
static void mouse_wheel_up()noexcept{
    Mouse::mouse_wheel_up();
    wheel_logger.println_with_head("↑ Pix{",Mouse::current_dpixel_,"}");
}
static void mouse_wheel_down()noexcept{
    Mouse::mouse_wheel_down();
    wheel_logger.println_with_head("↓ Pix{",Mouse::current_dpixel_,"}");
}
static void app_quit()noexcept{
    app_logger.println_with_head("Quit");
    exit(0);
}
static void mouse_dpixel_double()noexcept{
    Mouse::current_dpixel_=Mouse::current_dpixel_*2;
    pixel_logger.println_with_head("D_Pixel * 2 => ",Mouse::current_dpixel_);
}
static void mouse_dpixel_halve()noexcept{
    Mouse::current_dpixel_=Mouse::current_dpixel_/2!=0
        ?Mouse::current_dpixel_/2
        :1;
    pixel_logger.println_with_head("D_Pixel / 2 => ",Mouse::current_dpixel_);
}
static void mouse_key_up()noexcept{
    mouse_key_auto_up();
}
static void mouse_left_click()noexcept{
    mouse_key_auto_up();
    Mouse::mouse_left_click();
    mouse_logger.println_with_head("Left Click");
}
static void mouse_left_double_click()noexcept{
    mouse_key_auto_up();
    Mouse::mouse_left_double_click();
    mouse_logger.println_with_head("Left Double Click");
}
static void mouse_right_click()noexcept{
    mouse_key_auto_up();
    Mouse::mouse_right_click();
    mouse_logger.println_with_head("Right Click");
}
static void mouse_left_down()noexcept{
    mouse_key_auto_up();
    Mouse::mouse_left_down();
    is_mouse_left_down=true;
    mouse_logger.println_with_head("Left Down");
}
static void mouse_right_down()noexcept{
    mouse_key_auto_up();
    Mouse::mouse_right_down();
    is_mouse_right_down=true;
    mouse_logger.println_with_head("Right Down");
}
static void println_key_down()noexcept{
    keyboard_logger.print_with_head();
    key_down_set.for_each([](DWORD const& key){
        keyboard_logger.print("<",KeyBoard::key_code_to_name(key),">");
    });
    keyboard_logger.println(" Down");
}
static void println_key_up(DWORD vk_code)noexcept{
    keyboard_logger.println_with_head(
        "<",KeyBoard::key_code_to_name(vk_code),">",
        " Up"
    );
}
static void key_down_set_update()noexcept{
    ::std::stack<DWORD> remove_keys;
    key_down_set.for_each([&](DWORD const& key){
       if(::GetAsyncKeyState(key)&0x8000){}else{//按键未实际按下
           remove_keys.push(key);
       }
    });
    while(!remove_keys.empty()){
        key_down_set.erase(remove_keys.top());
        println_key_up(remove_keys.top());
        remove_keys.pop();
    }
}
static void handle(WPARAM w_param,DWORD vk_code)noexcept{
    // 检查按下的<X>单键和<ALT-X>组合键以及各种组合键
    if (w_param==WM_KEYDOWN||w_param==WM_SYSKEYDOWN) {
        //防止其他进程把全局键盘事件截获，造成逻辑上的bug
        key_down_set_update();
        if(!key_down_set.has(vk_code)){
            key_down_set.insert(vk_code);
            println_key_down();
        }
        if(vk_code==KeyCodeOf::leader){
            is_leader_down=true;
        }
        else if(is_leader_down&&
                key_down_handle_list.count(vk_code)!=0){
            key_down_handle_list.at(vk_code)();
        }
    }
    // 检查松开的<X>单键和<ALT-X>组合键以及各种组合键
    else if (w_param==WM_KEYUP||w_param==WM_SYSKEYUP) {
        key_down_set.erase(vk_code);
        key_down_set_update();
        if(vk_code==KeyCodeOf::leader){
            is_leader_down=false;
        }
        println_key_up(vk_code);
    }
}
}// namespace handle_detail
