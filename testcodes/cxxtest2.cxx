#include <iostream>

template <class T> class List {
public:
  T a;
  void say_hello() {
    std::cout << "Hello, List." << std::endl;
  }
};

template <class T> class Maybe {
public:
  T a;
  void say_hello() {
    std::cout << "Hello, Maybe." << std::endl;
  }
};

template <class> using Int = int;

template <class T, template <class> class X> class Container {
public:
  X<T> a;
};

int main() {
  Container<int, List> x;
  x.a.say_hello();
  return 0;
}


