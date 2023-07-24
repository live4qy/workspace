#include <bits/stdc++.h>

// Primary template.
/// Define a member typedef @c type only if a boolean constant is true.
template<bool, typename _Tp = void>
  struct enable_if
  { };

// Partial specialization for true.
template<typename _Tp>
  struct enable_if<true, _Tp>
  { typedef _Tp type; };

/*
模板定义要点：偏特化第一个参数为true的情况，此时才定义type
第一个参数为false则无法取到type
*/

// 参考资料
// https://blog.csdn.net/jeffasd/article/details/84667090

// 用法1

// 用法2


// 用法3: 校验模板函数模板类型
// 要点：随便找一个有类型的地方，加一个enable_if检查模板参数T即可
// 1.塞到返回值里
template<typename T>
typename std::enable_if<std::is_integral<T>::type, bool>::type
is_odd(T t) {
  return (bool)t%2;
}
// 2.塞到参数里
template<typename T>
bool is_even(typename std::enable_if<std::is_integral<T>::type, T>::type) {
  return (bool)(t%2==0);
}
// 3.塞到模板参数里(新增一个默认参数)
template<typename T, typename = typename std::enable_if<std::is_integral<T>::type,T>::type>
bool is_int(T t){
  return true;
}

int main() {
  // 编译通过
  std::enable_if<1==1,int>::type x;
  // 编译不通过
  // std::enable_if<1==2,int>::type y;
  return 0;
}