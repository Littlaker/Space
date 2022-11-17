
int main(int argc, char **argv) {
  int *p = new int[100];

  for (int i = 0; i < sizeof(p); i++) {
    p[i] = i;
  }

  delete[] p;
  p[0] = 99;
  return 0;
}
