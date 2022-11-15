#include <vector>

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    if (x == 0 || x < 10) {
      return true;
    }

    std::vector<int> v;

    while (x != 0) {
      v.push_back(x % 10);
      x /= 10;
    }

    int size = v.size();
    for (int i = 0; i < size / 2; i++) {
      if (v[i] != v[size - i - 1]) {
        return false;
      }
    }

    return true;
  }
};
