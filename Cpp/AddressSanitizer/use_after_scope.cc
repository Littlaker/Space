volatile int *p = 0;
int main(int argc, char **argv) {
  {
    int x = 0;
    p = &x;
  }
  *p = 100;
  return 0;
}
