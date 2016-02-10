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

template <typename a, typename F> Maybe<a> mapOver(F f, const Maybe<a> m) {
  return Maybe<a>(f(m.getValue()));
}

int main() {
  Maybe<int> m(100);
  auto f = [](int x) -> int { return x * 100; };
  std::cout << m.getValue() << std::endl;
  std::cout << mapOver(f, m).getValue() << std::endl;
  return 0;
}
