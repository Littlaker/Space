#include <cmath>
#include <vector>

// 双指针

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right) {
      int area = std::min(height[left], height[right]) * (right - left);

      if (area > maxArea) {
        maxArea = area;
      }

      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }

    return maxArea;
  }
};
