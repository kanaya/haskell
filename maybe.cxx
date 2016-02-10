#include <iostream>

template <typename a> class Maybe {
private:
  a value;
  bool valid;
public:
  Maybe(): a(0), valid(false) { }
  Maybe(a aValue): value(aValue), valid(true) { }
  a getValue() const { return value; }
  bool isValid() const { return valid; }
};

template <typename a, typename F> Maybe<a> mapOver(const Maybe<a> m, F f) {
  return Maybe<a>(f(m.getValue()));
}

int main() {
  Maybe<int> x(100);
  auto f = [](int x) -> int { return x * 100; };
  std::cout << x.getValue() << std::endl;
  return 0;
}
