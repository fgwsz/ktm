#pragma once
#include<unordered_map>
#include<list>
template<typename _Type>
class OrderedSet{
    using list_iterator=typename ::std::list<_Type>::iterator;
    ::std::unordered_map<_Type,list_iterator> map_;
    ::std::list<_Type> list_;
public:
    constexpr bool has(_Type const& value)const noexcept{
        return this->map_.count(value)!=0;
    }
    constexpr void insert(_Type const& value)noexcept{
        if(!this->has(value)){
            this->map_[value]=this->list_.insert(this->list_.cend(),value);
        }
    }
    constexpr void erase(_Type const& value)noexcept{
        if(this->has(value)){
            this->list_.erase(this->map_[value]);
            this->map_.erase(value);
        }
    }
    template<typename _Func>
    constexpr void for_each(_Func func)const noexcept{
        for(auto const& element:this->list_){
            func(element);
        }
    }
};
