#include <cstdlib>

int main() {
  int *p = new int[10];

  int *p1 = reintpret<int *>(malloc(sizeof(int) * 10));

  return 0;
}
