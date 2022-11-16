#include <string>
#include <vector>

// 动态规划

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    int length = s.length();
    if (length < 2) {
      return s;
    }

    // dp[i][i] = 1
    // dp[i][j] = d[i+1][j-1] && s[i][j]
    std::vector<std::vector<int>> dp(length, std::vector<int>(length));
    for (int i = 0; i < length; i++) {
      dp[i][i] = 1;
    }

    int maxLength = 1;
    int begin = 0;

    // 枚举子串长度
    for (int len = 2; len <= length; len++) {
      // 枚举左边界
      for (int left = 0; left < length - len + 1; left++) {
        // 右边界 = 左边界 + 长度 - 1
        int right = left + len - 1;

        if (s[left] != s[right]) {
          continue;
        }

        if (len == 2) {
          dp[left][right] = 1;
        } else {
          dp[left][right] = dp[left + 1][right - 1];
        }

        if (dp[left][right] && right - left + 1 > maxLength) {
          maxLength = right - left + 1;
          begin = left;
        }
      }
    }

    return s.substr(begin, maxLength);
  }
};
