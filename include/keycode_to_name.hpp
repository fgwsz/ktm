#pragma once
#include<string_view>
#include"keyname.hpp"
static constexpr ::std::string_view keycode_to_name[256]={
    "\\0","\\1","\\2","\\3","\\4","\\5","\\6","\\7",
    KeyName_Backspace         ,//8
    KeyName_Tab               ,//9
    "\\10","\\11","\\12",
    KeyName_Enter             ,//13
    "\\14","\\15","\\16","\\17","\\18",
    KeyName_PauseBreak        ,//19
    KeyName_CapsLk            ,//20
    "\\21","\\22","\\23","\\24","\\25","\\26",
    KeyName_Esc               ,//27
    "\\28","\\29",
    "\\30","\\31",
    KeyName_Space             ,//32
    KeyName_PageUp            ,//33
    KeyName_PageDown          ,//34
    KeyName_End               ,//35
    KeyName_Home              ,//36
    KeyName_Left              ,//37
    KeyName_Up                ,//38
    KeyName_Right             ,//39
    KeyName_Down              ,//40
    "\\41","\\42","\\43",
    KeyName_PrintScreen       ,//44
    KeyName_Insert            ,//45
    KeyName_Delete            ,//46
    "\\47",
    KeyName_0                 ,//48
    KeyName_1                 ,//49
    KeyName_2                 ,//50
    KeyName_3                 ,//51
    KeyName_4                 ,//52
    KeyName_5                 ,//53
    KeyName_6                 ,//54
    KeyName_7                 ,//55
    KeyName_8                 ,//56
    KeyName_9                 ,//57
    "\\58","\\59","\\60","\\61","\\62","\\63","\\64",
    KeyName_A                 ,//65
    KeyName_B                 ,//66
    KeyName_C                 ,//67
    KeyName_D                 ,//68
    KeyName_E                 ,//69
    KeyName_F                 ,//70
    KeyName_G                 ,//71
    KeyName_H                 ,//72
    KeyName_I                 ,//73
    KeyName_J                 ,//74
    KeyName_K                 ,//75
    KeyName_L                 ,//76
    KeyName_M                 ,//77
    KeyName_N                 ,//78
    KeyName_O                 ,//79
    KeyName_P                 ,//80
    KeyName_Q                 ,//81
    KeyName_R                 ,//82
    KeyName_S                 ,//83
    KeyName_T                 ,//84
    KeyName_U                 ,//85
    KeyName_V                 ,//86
    KeyName_W                 ,//87
    KeyName_X                 ,//88
    KeyName_Y                 ,//89
    KeyName_Z                 ,//90
    KeyName_LeftWin           ,//91
    KeyName_RightWin          ,//92
    KeyName_Application       ,//93
    "\\94","\\95","\\96","\\97","\\98","\\99",
    "\\100","\\101","\\102","\\103","\\104","\\105",
    KeyName_Multiply          ,//106// Operator*
    KeyName_Plus              ,//107// Operator+
    "\\108",
    KeyName_Minus             ,//109// Operator-
    "\\110",
    KeyName_Divide            ,//111,// Operator/
    KeyName_F1                ,//112
    KeyName_F2                ,//113
    KeyName_F3                ,//114
    KeyName_F4                ,//115
    KeyName_F5                ,//116
    KeyName_F6                ,//117
    KeyName_F7                ,//118
    KeyName_F8                ,//119
    KeyName_F9                ,//120
    KeyName_F10               ,//121
    KeyName_F11               ,//122
    KeyName_F12               ,//123
    "\\124","\\125","\\126","\\127","\\128","\\129",
    "\\130","\\131","\\132","\\133","\\134","\\135","\\136","\\137","\\138","\\139",
    "\\140","\\141","\\142","\\143",
    KeyName_NumLock           ,//144
    KeyName_ScrollLock        ,//145
    "\\146","\\147","\\148","\\149",
    "\\150","\\151","\\152","\\153","\\154","\\155","\\156","\\157","\\158","\\159",
    KeyName_LeftShift         ,//160
    KeyName_RightShfit        ,//161
    KeyName_LeftCtrl          ,//162
    KeyName_RightCtrl         ,//163
    KeyName_LeftAlt           ,//164
    KeyName_RightAlt          ,//165
    "\\166","\\167","\\168","\\169",
    "\\170","\\171","\\172","\\173","\\174","\\175","\\176","\\177","\\178","\\179",
    "\\180","\\181","\\182","\\183","\\184","\\185",
    KeyName_Semicolon         ,//186// ;
    KeyName_Equal             ,//187// ,//
    KeyName_Comma             ,//188// ,
    KeyName_Hyphen            ,//189// -
    KeyName_Period            ,//190// .
    KeyName_Slash             ,//191// /
    KeyName_BackQuote         ,//192// `
    "\\193","\\194","\\195","\\196","\\197","\\198","\\199",
    "\\200","\\201","\\202","\\203","\\204","\\205","\\206","\\207","\\208","\\209",
    "\\210","\\211","\\212","\\213","\\214","\\215","\\216","\\217","\\218",
    KeyName_LeftSquareBracket ,//219// [
    KeyName_VerticalBar       ,//220// |
    KeyName_RightSquareBracket,//221// ]
    KeyName_SingleQuote       ,//222// '
    "\\223","\\224","\\225","\\226","\\227","\\228","\\229",
    "\\230","\\231","\\232","\\233","\\234","\\235","\\236","\\237","\\238","\\239",
    "\\240","\\241","\\242","\\243","\\244","\\245","\\246","\\247","\\248","\\249",
    "\\250","\\251","\\252","\\253","\\254","\\255"
};
