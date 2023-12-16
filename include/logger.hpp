#pragma once
#include<type_traits>
#include<iostream>
#include<string_view>
class Logger{
    ::std::string_view head_;
    static bool init_flag_;
    static inline bool _init(void)noexcept;
public:
    inline constexpr Logger(::std::string_view const& head="")noexcept
        :head_(head)
    {}
    template<typename..._Types>
    inline constexpr Logger const& print(_Types&&...args)const noexcept{
        if constexpr(sizeof...(args)!=0){
            (::std::cout<<...<<::std::forward<_Types>(args));
        }
        return *this;
    }
    template<typename..._Types>
    inline constexpr Logger const& println(_Types&&...args)const noexcept{
        this->print(::std::forward<_Types>(args)...);
        this->print('\n'); 
        return *this;
    }
    template<typename..._Types>
    inline constexpr Logger const& print_with_head(_Types&&...args)const noexcept{
        this->print(this->head_);
        this->print(::std::forward<_Types>(args)...);
        return *this;
    }
    template<typename..._Types>
    inline constexpr Logger const& println_with_head(_Types&&...args)const noexcept{
        this->print(this->head_);
        this->println(::std::forward<_Types>(args)...);
        return *this;
    }
};
bool Logger::init_flag_=Logger::_init();
bool Logger::_init(void)noexcept{ // 优化::std::cout输出性能
    ::std::ios::sync_with_stdio(false); // 关闭与stdio的同步
    ::std::cin.tie(nullptr);::std::cout.tie(nullptr); // 关闭::std::cout与::std::cin的绑定
    ::std::cout<<::std::unitbuf; // 设置为无缓冲区，实时输出
    return true;
}
