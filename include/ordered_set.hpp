#pragma once
#include<unordered_map>
#include<list>
#include<type_traits>
template<typename _Type>
class OrderedSet{
    using list_iterator=typename ::std::list<_Type>::iterator;
    ::std::unordered_map<_Type,list_iterator> map_;
    ::std::list<_Type> list_;
public:
    inline constexpr bool has(_Type const& value)const noexcept{
        return this->map_.count(value)!=0;
    }
    inline constexpr void insert(_Type const& value)noexcept{
        if(!this->has(value)){
            this->map_[value]=this->list_.insert(this->list_.cend(),value);
        }
    }
    inline constexpr void erase(_Type const& value)noexcept{
        if(this->has(value)){
            this->list_.erase(this->map_[value]);
            this->map_.erase(value);
        }
    }
    template<typename _Func>
    inline constexpr void for_each(_Func&& func)const noexcept{
        for(auto const& element:this->list_){
            ::std::forward<_Func>(func)(element);
        }
    }
};
