#include <cstdio>
#include <cstring>

int main(int argc, char **argv) {
  int *p = new int[5];
  p[5] = 11;  // 内存越界
  delete[] p;

  char *str = new char[10];
  const char *str_1 = "hello,wrold";

  strcpy(str, str_1);
  delete[] str;
  return 0;
}
