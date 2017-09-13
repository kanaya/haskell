#include <iostream>
#include <list>

template <typename a, typename fn> std::list<a> mapOver(fn f, std::list<a> l) {
  std::list<a> r(l.size());
  // auto i = l.cbegin();
  typename std::list<a>::const_iterator i = l.cbegin();
  // auto j = r.begin();
  typename std::list<a>::iterator j = r.begin();
  while (i != l.cend()) *j++ = f(*i++);
  return r;
}

template <typename a> void showList(const std::list<a> &l) {
  auto i = l.cbegin();
  while (i != l.cend()) {
    std::cout << *i << ' ';
    ++i;
  }
  std::cout << std::endl;
}

int main() {
  std::list<int> l(10, 1);
  showList(l);
  auto f = [](int x) -> int { return x * 100; };
  std::list<int> m = mapOver(f, l);
  showList(m);
  return 0;
}
