#include <set>
#include <string>
using namespace std;

// 滑动窗口
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.empty()) {
      return 0;
    }

    std::set<char> set;
    int left = 0;
    int maxSubstrLen = 0;

    for (int i = 0; i < s.size(); i++) {
      while (set.find(s[i]) != set.end()) {
        set.erase(s[left]);
        left++;
      }

      maxSubstrLen = max(maxSubstrLen, i - left + 1);
      set.insert(s[i]);
    }

    return maxSubstrLen;
  }
};
