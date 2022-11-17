int main(int argc, char **argv) {
  int *p = new int[100];
  for (int i = 0; i <= 100; i++) {
    p[i] = i;
  }
  delete[] p;
  return 0;
}
