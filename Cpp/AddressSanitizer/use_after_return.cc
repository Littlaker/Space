int *ptr;
//
// 需要导出环境变量
// export ASAN_OPTIONS=detect_stack_use_after_return=1
__attribute__((noinline)) void func() {
  int nums[100];
  ptr = &nums[0];
}

int main(int argc, char **argv) {
  func();
  return ptr[argc];
}
