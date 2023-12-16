#pragma once
#include<type_traits>
#include<iostream>
class Logger{
    static bool global_enable_;
    ::std::string head_;
    static bool init_flag_;
    static bool _init()noexcept;
public:
    Logger(::std::string const& head="")noexcept
        :head_(head)
    {}
    static constexpr void set_global_enable(bool global_enable)noexcept{
        Logger::global_enable_=global_enable;
    }
    template<typename..._Types>
    constexpr Logger const& print(_Types&&...args)const noexcept{
        if constexpr(sizeof...(args)!=0){
            (::std::cout<<...<<::std::forward<_Types>(args));
        }
        return *this;
    }
    template<typename..._Types>
    constexpr Logger const& println(_Types&&...args)const noexcept{
        this->print(::std::forward<_Types>(args)...);
        this->print('\n'); 
        return *this;
    }
    template<typename..._Types>
    constexpr Logger const& print_with_head(_Types&&...args)const noexcept{
        if(this->global_enable_){
            this->print(this->head_);
            this->print(::std::forward<_Types>(args)...);
        }
        return *this;
    }
    template<typename..._Types>
    constexpr Logger const& println_with_head(_Types&&...args)const noexcept{
        if(this->global_enable_){
            this->print(this->head_);
            this->println(::std::forward<_Types>(args)...);
        }
        return *this;
    }
};
bool Logger::global_enable_=true;
bool Logger::init_flag_=Logger::_init();
bool Logger::_init()noexcept{ // 优化::std::cout输出性能
    ::std::ios::sync_with_stdio(false); // 关闭与stdio的同步
    ::std::cin.tie(0);// 关闭::std::cout与::std::cin的绑定
    ::std::cout.tie(0);
    ::std::cout<<::std::unitbuf; // 设置为无缓冲区，实时输出
    return true;
}
