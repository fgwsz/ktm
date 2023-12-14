﻿#pragma once
#include<unordered_map>
#include<string>
#include<Windows.h>
#include"keycode.hpp"
#include"keyname.hpp"
class KeyBoard{
    static ::std::unordered_map<DWORD,::std::string> key_code_to_name_map_;
public:
    static ::std::string const& key_code_to_name(DWORD key_code)noexcept;
};
::std::unordered_map<DWORD,::std::string> KeyBoard::key_code_to_name_map_={
    {KeyCode_A,KeyName_A},
    {KeyCode_B,KeyName_B},
    {KeyCode_C,KeyName_C},
    {KeyCode_D,KeyName_D},
    {KeyCode_E,KeyName_E},
    {KeyCode_F,KeyName_F},
    {KeyCode_G,KeyName_G},
    {KeyCode_H,KeyName_H},
    {KeyCode_I,KeyName_I},
    {KeyCode_J,KeyName_J},
    {KeyCode_K,KeyName_K},
    {KeyCode_L,KeyName_L},
    {KeyCode_M,KeyName_M},
    {KeyCode_N,KeyName_N},
    {KeyCode_O,KeyName_O},
    {KeyCode_P,KeyName_P},
    {KeyCode_Q,KeyName_Q},
    {KeyCode_R,KeyName_R},
    {KeyCode_S,KeyName_S},
    {KeyCode_T,KeyName_T},
    {KeyCode_U,KeyName_U},
    {KeyCode_V,KeyName_V},
    {KeyCode_W,KeyName_W},
    {KeyCode_X,KeyName_X},
    {KeyCode_Y,KeyName_Y},
    {KeyCode_Z,KeyName_Z},
    {KeyCode_0,KeyName_0},
    {KeyCode_1,KeyName_1},
    {KeyCode_2,KeyName_2},
    {KeyCode_3,KeyName_3},
    {KeyCode_4,KeyName_4},
    {KeyCode_5,KeyName_5},
    {KeyCode_6,KeyName_6},
    {KeyCode_7,KeyName_7},
    {KeyCode_8,KeyName_8},
    {KeyCode_9,KeyName_9},
    {KeyCode_Backspace         ,KeyName_Backspace         },
    {KeyCode_Tab               ,KeyName_Tab               },
    {KeyCode_Enter             ,KeyName_Enter             },
    {KeyCode_PauseBreak        ,KeyName_PauseBreak        },
    {KeyCode_CapsLk            ,KeyName_CapsLk            },
    {KeyCode_Esc               ,KeyName_Esc               },
    {KeyCode_Space             ,KeyName_Space             },
    {KeyCode_PageUp            ,KeyName_PageUp            },
    {KeyCode_PageDown          ,KeyName_PageDown          },
    {KeyCode_End               ,KeyName_End               },
    {KeyCode_Home              ,KeyName_Home              },
    {KeyCode_Left              ,KeyName_Left              },
    {KeyCode_Up                ,KeyName_Up                },
    {KeyCode_Right             ,KeyName_Right             },
    {KeyCode_Down              ,KeyName_Down              },
    {KeyCode_PrintScreen       ,KeyName_PrintScreen       },
    {KeyCode_Insert            ,KeyName_Insert            },
    {KeyCode_Delete            ,KeyName_Delete            },
    {KeyCode_LeftWin           ,KeyName_LeftWin           },
    {KeyCode_RightWin          ,KeyName_RightWin          },
    {KeyCode_Application       ,KeyName_Application       },
    {KeyCode_Multiply          ,KeyName_Multiply          },
    {KeyCode_Plus              ,KeyName_Plus              },
    {KeyCode_Minus             ,KeyName_Minus             },
    {KeyCode_Divide            ,KeyName_Divide            },
    {KeyCode_F1                ,KeyName_F1                },
    {KeyCode_F2                ,KeyName_F2                },
    {KeyCode_F3                ,KeyName_F3                },
    {KeyCode_F4                ,KeyName_F4                },
    {KeyCode_F5                ,KeyName_F5                },
    {KeyCode_F6                ,KeyName_F6                },
    {KeyCode_F7                ,KeyName_F7                },
    {KeyCode_F8                ,KeyName_F8                },
    {KeyCode_F9                ,KeyName_F9                },
    {KeyCode_F10               ,KeyName_F10               },
    {KeyCode_F11               ,KeyName_F11               },
    {KeyCode_F12               ,KeyName_F12               },
    {KeyCode_NumLock           ,KeyName_NumLock           },
    {KeyCode_ScrollLock        ,KeyName_ScrollLock        },
    {KeyCode_LeftShift         ,KeyName_LeftShift         },
    {KeyCode_RightShfit        ,KeyName_RightShfit        },
    {KeyCode_LeftCtrl          ,KeyName_LeftCtrl          },
    {KeyCode_RightCtrl         ,KeyName_RightCtrl         },
    {KeyCode_LeftAlt           ,KeyName_LeftAlt           },
    {KeyCode_RightAlt          ,KeyName_RightAlt          },
    {KeyCode_Semicolon         ,KeyName_Semicolon         },
    {KeyCode_Equal             ,KeyName_Equal             },
    {KeyCode_Comma             ,KeyName_Comma             },
    {KeyCode_Hyphen            ,KeyName_Hyphen            },
    {KeyCode_Period            ,KeyName_Period            },
    {KeyCode_Slash             ,KeyName_Slash             },
    {KeyCode_BackQuote         ,KeyName_BackQuote         },
    {KeyCode_LeftSquareBracket ,KeyName_LeftSquareBracket },
    {KeyCode_VerticalBar       ,KeyName_VerticalBar       },
    {KeyCode_RightSquareBracket,KeyName_RightSquareBracket},
    {KeyCode_SingleQuote       ,KeyName_SingleQuote       }
};
::std::string const& KeyBoard::key_code_to_name(DWORD key_code)noexcept{
    if(KeyBoard::key_code_to_name_map_.count(key_code)==0){
        KeyBoard::key_code_to_name_map_.emplace(key_code,"\\"+::std::to_string(key_code));
    }
    return KeyBoard::key_code_to_name_map_.at(key_code);
}