#include <iostream>

template <typename a> class Maybe {
private:
  a value;
  bool valid;
public:
  Maybe(): value(0), valid(false) { }
  Maybe(a aValue): value(aValue), valid(true) { }
  a getValue() const { return value; }
  bool isValid() const { return valid; }
};

template <typename a, typename fn> Maybe<a> mapOver(fn f, Maybe<a> m) {
  if (m.isValid())
    return Maybe<a>(f(m.getValue()));
  else
    return Maybe<a>();
}

int main() {
  Maybe<int> m(123);
  auto f = [](int x) { return x * 100; };
  std::cout << m.getValue() << std::endl;
  Maybe<int> n = mapOver(f, m);
  std::cout << n.getValue() << std::endl;
  return 0;
}
