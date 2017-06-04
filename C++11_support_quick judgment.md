# 如何快速的判断编译器是否支持C++11？

## 加入如下宏判断即可：

    #if __cplusplus < 201103L
      #error "should use c++11 implementation"
    #endif

## 解释：

`在c++03中，__cplusplus定义为199711L；在c++11中，__cplusplus定义为201103L。所以利用__cplusplus对编译器进行检测，看其是否支持c++11`
