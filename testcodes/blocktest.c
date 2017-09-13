#include <Block.h>
#include <stdio.h>

typedef int (^int_to_int)(int);

int_to_int make_plus_n(int n) {
  return Block_copy(^(int x) {
      return n + x;
    });
}

int main(void) {
  int_to_int make_plus_10 = make_plus_n(10);
  int x = make_plus_10(1);
  printf("x = %d\n", x);
  return 0;
}

