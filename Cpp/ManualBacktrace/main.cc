#include <cstdio>
#include <string>

const char *str[] = {"hello, world", "hello, world", "hello, world",
                     "hello, world", "hello, world", "hello, world",
                     "hello, world"};

void caller_func();
void callee_func();

void caller_func() {
  char cstr[24] = {0};
  cstr[0] = 'c';
  callee_func();
}
void callee_func() {
  static int i = 0;
  char cstr[24] = {0};
  cstr[0] = 'c';
  str[i++] = "hello,world";

  caller_func();
}

int main() {
  caller_func();
  return 0;
}
