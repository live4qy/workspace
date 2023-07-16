#### std::weak_ptr\<\> :

weak_ptr只用于解决shared_ptr引起的循环引用问题:\
例如以下程序:
```cpp
class B;

class A{
public:
std::shared_ptr<B> shared_B;
};

class B{
public:
std::shared_ptr<A> shared_A;
};

int main(){
  std::shared_ptr<A> shared_A = std::make_shared<A>();
  std::shared_ptr<B> shared_B = std::make_shared<B>();
  shared_A->shared_B = shared_B;
  shared_B->shared_A = shared_A;
  return 0;
}
```
当程序结束后，栈上的shared_A和shared_B被释放，\
但堆上的A.shared_B和B.shared_A互相引用，引用计数都为1，不会被释放，\
这就出现了内存泄漏的问题。

std::weak_ptr可以解决这个问题，可以将代码修改为:
```cpp
class B;

class A{
public:
std::weak_ptr<B> weak_B;
};

class B{
public:
std::shared_ptr<A> shared_A;
};

int main(){
  std::shared_ptr<A> shared_A = std::make_shared<A>();
  std::shared_ptr<B> shared_B = std::make_shared<B>();
  shared_A->weak_B = shared_B;
  shared_B->shared_A = shared_A;
  return 0;
}
```
std::weak_ptr需要绑定shared_ptr\
作用原理是weak_ptr不会改变shared_ptr对象的引用计数.\
只要shared_ptr的引用计数为0，就会被释放.\
因此当shared_A释放时，由于B没有被引用，所以B也会被释放.\
这就消去了循环引用.

std::weak_ptr使用较少，只用于处理std::shared_ptr的循环引用问题
