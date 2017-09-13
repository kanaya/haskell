#include <iostream>
#include <list>

using namespace std;

template <class a> class maybe {
public:
  a x;
};

template <class a, class b, template <class> class X, class fn> X<b> map_over(fn f, X<a> x, b dummy) {
  std::cout << "Hello, X." << std::endl;
}

auto g = [](int x) -> int { return 0; };

int main() {
  maybe<int> x;
  maybe<int> y;
  int z = 0;
  y = map_over(g, x, z);
  return 0;
}


