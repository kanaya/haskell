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

template <template <class T> class X> class Container {
public:
  X<int> a;
};

int main() {
  Container<Maybe> x;
  x.a.say_hello();
  return 0;
}


