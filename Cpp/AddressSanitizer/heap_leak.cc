
int main(int argc, char **argv) {
  // heap leak
  int *a = new int[1024];
  a[0] = 0;

  return 0;
}
