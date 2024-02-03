#ifndef _SIZEFILTER_
#define _SIZEFILTER_

#include <iostream>
#include <set>
using namespace std;
template <class _Ty, class _Container = std::set<_Ty>>
class sizeFilter
{
public:
    typedef sizeFilter<_Ty, _Container> _Myt;
    typedef typename _Container::size_type size_type;
    typedef typename _Container::value_type value_type;

    sizeFilter() : c()
    {
        // 默认构造函数，初始化内置容器
    }

    sizeFilter(const _Container &_Cont) : c(_Cont)
    {
        // 构造函数，通过指定特定的容器构造
    }

    sizeFilter(const _Myt &_Right) : c(_Right.c)
    {
        // 构造函数，通过指定特定的sizeFilter容器构造
    }

    _Myt &operator=(const _Myt &_Right)
    {
        // 使用另一个sizeFilter 赋值
        c = _Right.c;
        return (*this);
    }

    bool empty()
    {
        return (c.empty());
    }

    size_type size() const
    {
        return (c.size());
    }

    bool insert(const value_type &_Val)
    {
        pair<typename _Container::iterator, bool> ret = c.insert(_Val);
        if (ret.second)
        {
            std::cout << "插入 " << _Val << " 成功！" << std::endl;
            return true;
        }
        std::cout << "插入 " << _Val << " 失败！" << std::endl;
        return false;
    }

    bool erase(const value_type &_Val)
    {
        // 擦除
        if (c.erase(_Val) > 0)
        {
            return true;
        }
        return false;
    }

    std::pair<value_type, bool> getMin()
    {
        std::pair<value_type, bool> ret;
        typename _Container::iterator min = c.begin();

        if (min != c.end())
        {
            ret.first = *min;
            ret.second = true;
            return ret;
        }
        ret.second = false;
        return ret;
    }

    std::pair<value_type, bool> getMax()
    {
        // 获取最大值
        std::pair<value_type, bool> ret;
        typename _Container::iterator end = c.end();
        if (c.size() > 0)
        {
            ret.first = *(--end);
            ret.second = true;
        }
        else
        {
            ret.second = false;
        }
        return ret;
    }

protected:
    _Container c;
};
#endif