#ifndef UNTITLED7_CUSTOMGENIERARCHY_H
#define UNTITLED7_CUSTOMGENIERARCHY_H

#include <typeinfo>
#include <iostream>
#include "TypeList.h"

template <class T>
class Universal
{
public:
  T val;
};

template <size_t cur_num, size_t level, size_t level_st, size_t level_len, size_t okay, class T, template <class> class U>
class CustomGenIerarchy;

template <size_t cur_num, size_t level, size_t level_st, size_t level_len, class T, template <class> class U>
class CustomGenIerarchy <cur_num, level, level_st, level_len, 1, T, U>
{
};

template <size_t cur_num, size_t level_st, size_t level_len, class T, template <class> class U>
class CustomGenIerarchy<cur_num, 1, level_st, level_len, 0, T, U> : public CustomGenIerarchy<cur_num + level_len, 0, level_st + level_len, level_len, ((cur_num + level_len > Length<T>::value) ? 1 : 0), T, U>
{
public:
  CustomGenIerarchy()
  {

    std::cout << cur_num << ' ' << typeid(val.val).name() << std::endl;
  }
  U <typename TypeAt<cur_num - 1, T>::res > val;
};

template <size_t cur_num, size_t level_st, size_t level_len, class T, template <class> class U>
class CustomGenIerarchy<cur_num, 0, level_st, level_len, 0, T, U> : public CustomGenIerarchy< level_st + level_len + (cur_num - level_st)*3, 1, level_st + level_len, level_len*3, ((level_st + level_len + (cur_num - level_st)*3 > Length<T>::value) ? 1 : 0), T, U>,
                                                                    public CustomGenIerarchy< level_st + level_len + (cur_num - level_st)*3 + 1, 1, level_st + level_len, level_len*3, ((level_st + level_len + (cur_num - level_st)*3 + 1 > Length<T>::value) ? 1 : 0), T, U>,
                                                                    public CustomGenIerarchy< level_st + level_len + (cur_num - level_st)*3 + 2, 1, level_st + level_len, level_len*3, ((level_st + level_len + (cur_num - level_st)*3 + 2 > Length<T>::value) ? 1 : 0), T, U>
{
public:
  CustomGenIerarchy()
  {
    std::cout << cur_num << ' ' << typeid(val.val).name() << std::endl;
  }
  U <typename TypeAt<cur_num - 1, T>::res > val;
};
#endif //UNTITLED7_CUSTOMGENIERARCHY_H
