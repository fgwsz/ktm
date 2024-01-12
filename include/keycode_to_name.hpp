#ifndef __KEYCODE_TO_NAME_HPP__
#define __KEYCODE_TO_NAME_HPP__
#include<string_view>
#include"keyname.hpp"
#define KeyNameOf(__keycode__) "\\"#__keycode__
static constexpr ::std::string_view keycode_to_name[256]={
    KeyNameOf(0),KeyNameOf(1),KeyNameOf(2),KeyNameOf(3),KeyNameOf(4),KeyNameOf(5),KeyNameOf(6),KeyNameOf(7),
    KeyName_Backspace         ,//8
    KeyName_Tab               ,//9
    KeyNameOf(10),KeyNameOf(11),KeyNameOf(12),
    KeyName_Enter             ,//13
    KeyNameOf(14),KeyNameOf(15),KeyNameOf(16),KeyNameOf(17),KeyNameOf(18),
    KeyName_PauseBreak        ,//19
    KeyName_CapsLk            ,//20
    KeyNameOf(21),KeyNameOf(22),KeyNameOf(23),KeyNameOf(24),KeyNameOf(25),KeyNameOf(26),
    KeyName_Esc               ,//27
    KeyNameOf(28),KeyNameOf(29),
    KeyNameOf(30),KeyNameOf(31),
    KeyName_Space             ,//32
    KeyName_PageUp            ,//33
    KeyName_PageDown          ,//34
    KeyName_End               ,//35
    KeyName_Home              ,//36
    KeyName_Left              ,//37
    KeyName_Up                ,//38
    KeyName_Right             ,//39
    KeyName_Down              ,//40
    KeyNameOf(41),KeyNameOf(42),KeyNameOf(43),
    KeyName_PrintScreen       ,//44
    KeyName_Insert            ,//45
    KeyName_Delete            ,//46
    KeyNameOf(47),
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
    KeyNameOf(58),KeyNameOf(59),KeyNameOf(60),KeyNameOf(61),KeyNameOf(62),KeyNameOf(63),KeyNameOf(64),
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
    KeyNameOf(94),KeyNameOf(95),KeyNameOf(96),KeyNameOf(97),KeyNameOf(98),KeyNameOf(99),
    KeyNameOf(100),KeyNameOf(101),KeyNameOf(102),KeyNameOf(103),KeyNameOf(104),KeyNameOf(105),
    KeyName_Multiply          ,//106// Operator*
    KeyName_Plus              ,//107// Operator+
    KeyNameOf(108),
    KeyName_Minus             ,//109// Operator-
    KeyNameOf(110),
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
    KeyName_F13               ,//124
    KeyName_F14               ,//125
    KeyName_F15               ,//126
    KeyName_F16               ,//127
    KeyName_F17               ,//128
    KeyName_F18               ,//129
    KeyName_F19               ,//130
    KeyName_F20               ,//131
    KeyNameOf(132),KeyNameOf(133),KeyNameOf(134),KeyNameOf(135),KeyNameOf(136),KeyNameOf(137),KeyNameOf(138),KeyNameOf(139),
    KeyNameOf(140),KeyNameOf(141),KeyNameOf(142),KeyNameOf(143),
    KeyName_NumLock           ,//144
    KeyName_ScrollLock        ,//145
    KeyNameOf(146),KeyNameOf(147),KeyNameOf(148),KeyNameOf(149),
    KeyNameOf(150),KeyNameOf(151),KeyNameOf(152),KeyNameOf(153),KeyNameOf(154),KeyNameOf(155),KeyNameOf(156),KeyNameOf(157),KeyNameOf(158),KeyNameOf(159),
    KeyName_LeftShift         ,//160
    KeyName_RightShfit        ,//161
    KeyName_LeftCtrl          ,//162
    KeyName_RightCtrl         ,//163
    KeyName_LeftAlt           ,//164
    KeyName_RightAlt          ,//165
    KeyNameOf(166),KeyNameOf(167),KeyNameOf(168),KeyNameOf(169),
    KeyNameOf(170),KeyNameOf(171),KeyNameOf(172),
    KeyName_MediaVolumeMute   ,//173
    KeyName_MediaVolumeDown   ,//174
    KeyName_MediaVolumeUp     ,//175
    KeyName_MediaNextTrack    ,//176
    KeyName_MediaPrevTrack    ,//177
    KeyName_MediaStop         ,//178
    KeyName_MediaPlayPause    ,//179
    KeyNameOf(180),KeyNameOf(181),KeyNameOf(182),KeyNameOf(183),KeyNameOf(184),KeyNameOf(185),
    KeyName_Semicolon         ,//186// ;
    KeyName_Equal             ,//187// =
    KeyName_Comma             ,//188// ,
    KeyName_Hyphen            ,//189// -
    KeyName_Period            ,//190// .
    KeyName_Slash             ,//191// /
    KeyName_BackQuote         ,//192// `
    KeyNameOf(193),KeyNameOf(194),KeyNameOf(195),KeyNameOf(196),KeyNameOf(197),KeyNameOf(198),KeyNameOf(199),
    KeyNameOf(200),KeyNameOf(201),KeyNameOf(202),KeyNameOf(203),KeyNameOf(204),KeyNameOf(205),KeyNameOf(206),KeyNameOf(207),KeyNameOf(208),KeyNameOf(209),
    KeyNameOf(210),KeyNameOf(211),KeyNameOf(212),KeyNameOf(213),KeyNameOf(214),KeyNameOf(215),KeyNameOf(216),KeyNameOf(217),KeyNameOf(218),
    KeyName_LeftSquareBracket ,//219// [
    KeyName_VerticalBar       ,//220// |
    KeyName_RightSquareBracket,//221// ]
    KeyName_SingleQuote       ,//222// '
    KeyNameOf(223),KeyNameOf(224),KeyNameOf(225),KeyNameOf(226),KeyNameOf(227),KeyNameOf(228),KeyNameOf(229),
    KeyNameOf(230),KeyNameOf(231),KeyNameOf(232),KeyNameOf(233),KeyNameOf(234),KeyNameOf(235),KeyNameOf(236),KeyNameOf(237),KeyNameOf(238),KeyNameOf(239),
    KeyNameOf(240),KeyNameOf(241),KeyNameOf(242),KeyNameOf(243),KeyNameOf(244),KeyNameOf(245),KeyNameOf(246),KeyNameOf(247),KeyNameOf(248),KeyNameOf(249),
    KeyNameOf(250),KeyNameOf(251),KeyNameOf(252),KeyNameOf(253),KeyNameOf(254),KeyNameOf(255)
};
#endif//!__KEYCODE_TO_NAME_HPP__
