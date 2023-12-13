#pragma once
#include<unordered_map>
#include"logger.hpp"
#include"key_code_of.hpp"
#include"key_board.hpp"
#include"mouse.hpp"
static Logger mouse_logger   (true,"[MOU] ");
static Logger keyboard_logger(true,"[KEY] ");
static Logger app_logger     (true,"[APP] ");
static void mouse_move_up          ();
static void mouse_move_down        ();
static void mouse_move_left        ();
static void mouse_move_right       ();
static void mouse_wheel_up         ();
static void mouse_wheel_down       ();
static void mouse_left_click       ();
static void mouse_left_double_click();
static void mouse_right_click      ();
static void mouse_key_up           ();
static void mouse_left_down        ();
static void mouse_right_down       ();
static void mouse_dpixel_double    ();
static void mouse_dpixel_halve     ();
static void app_quit               ();
static ::std::unordered_map<DWORD,void(*)()> const key_down_handle_list={
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
static Mouse::Position mouse_position={};
static void println_key_down(DWORD vk_code){
    keyboard_logger.println(
        "<",KeyBoard::keyCodeToName(vk_code),">",
        "{",vk_code,"}",
        " KEY DOWN"
    );
}
static void println_key_up(DWORD vk_code){
    keyboard_logger.println(
        "<",KeyBoard::keyCodeToName(vk_code),">",
        "{",vk_code,"}",
        " KEY UP"
    );
}
static void handle(WPARAM w_param,DWORD vk_code){
    // 检查按下的<X>单键和<ALT-X>组合键以及各种组合键
    if (w_param==WM_KEYDOWN||w_param==WM_SYSKEYDOWN) {
        println_key_down(vk_code);
        if(vk_code==KeyCodeOf::leader){
            is_leader_down=true;
        }
        else if(is_leader_down&&key_down_handle_list.count(vk_code)!=0){
            key_down_handle_list.at(vk_code)();
        }
    }
    // 检查松开的<X>单键和<ALT-X>组合键以及各种组合键
    else if (w_param==WM_KEYUP||w_param==WM_SYSKEYUP) {
        println_key_up(vk_code);
        if(vk_code==KeyCodeOf::leader){
            is_leader_down=false;
        }
    }
}
static void println_mouse_position_before_move(){
    Mouse::mousePosition(mouse_position);
    mouse_logger.println(
        "MOUSE MOVE BEFORE POSITION(",
        mouse_position.x,",",
        mouse_position.y,")"
    );
}
static void println_mouse_position_after_move(){
    Mouse::mousePosition(mouse_position);
    mouse_logger.println(
        "MOUSE MOVE AFTER  POSITION(",
        mouse_position.x,",",
        mouse_position.y,")"
    );
}
static void mouse_key_auto_up(){
    if(is_mouse_left_down){
        mouse_logger.println("MOUSE LEFT UP");
        Mouse::mouseLeftUp();
        is_mouse_left_down=false;
    }else if(is_mouse_right_down){
        mouse_logger.println("MOUSE RIGHT UP");
        Mouse::mouseRightUp();
        is_mouse_right_down=false;
    }
}
static void mouse_move_left(){ 
    mouse_logger.println("MOUSE MOVE LEFT");
    println_mouse_position_before_move();
    Mouse::mouseMoveLeft();
    println_mouse_position_after_move();
}
static void mouse_move_down(){
    mouse_logger.println("MOUSE MOVE DOWN");
    println_mouse_position_before_move();
    Mouse::mouseMoveDown();
    Mouse::mousePosition(mouse_position);
    println_mouse_position_after_move();
}
static void mouse_move_up(){
    mouse_logger.println("MOUSE MOVE UP");
    println_mouse_position_before_move();
    Mouse::mouseMoveUp();
    println_mouse_position_after_move();
}
static void mouse_move_right(){
    mouse_logger.println("MOUSE MOVE RIGHT");
    println_mouse_position_before_move();
    Mouse::mouseMoveRight();
    println_mouse_position_after_move();
}
static void mouse_wheel_up(){
    mouse_logger.println("MOUSE WHEEL UP");
    Mouse::mouseWheelUp();
}
static void mouse_wheel_down(){
    mouse_logger.println("MOUSE WHEEL DOWN");
    Mouse::mouseWheelDown();
}
static void app_quit(){
    app_logger.println("APP QUIT");
    exit(0);
}
static void mouse_dpixel_double(){
    mouse_logger.println("MOUSE D_PIXEL * 2");
    mouse_logger.println("MOUSE D_PIXEL BEFORE IS ",Mouse::current_dpixel_);
    Mouse::current_dpixel_=Mouse::current_dpixel_*2;
    mouse_logger.println("MOUSE D_PIXEL AFTER  IS ",Mouse::current_dpixel_);
}
static void mouse_dpixel_halve(){
    mouse_logger.println("MOUSE D_PIXEL / 2");
    mouse_logger.println("MOUSE D_PIXEL BEFORE IS ",Mouse::current_dpixel_);
    Mouse::current_dpixel_=Mouse::current_dpixel_/2==0
        ?1
        :Mouse::current_dpixel_/2
    ;
    mouse_logger.println("MOUSE D_PIXEL AFTER  IS ",Mouse::current_dpixel_);
}
static void mouse_key_up(){
    mouse_key_auto_up();
}
static void mouse_left_click(){
    mouse_key_auto_up();
    mouse_logger.println("MOUSE LEFT CLICK");
    Mouse::mouseLeftClick();
}
static void mouse_left_double_click(){
    mouse_key_auto_up();
    mouse_logger.println("MOUSE LEFT DOUBLE CLICK");
    Mouse::mouseLeftDoubleClick();
}
static void mouse_right_click(){
    mouse_key_auto_up();
    mouse_logger.println("MOUSE RIGHT CLICK");
    Mouse::mouseRightClick();
}
static void mouse_left_down(){
    mouse_key_auto_up();
    mouse_logger.println("MOUSE LEFT DOWN");
    Mouse::mouseLeftDown();
    is_mouse_left_down=true;
}
static void mouse_right_down(){
    mouse_key_auto_up();
    mouse_logger.println("MOUSE RIGHT DOWN");
    Mouse::mouseRightDown();
    is_mouse_right_down=true;
}
