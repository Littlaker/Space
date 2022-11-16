#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  // 穷举法
  // 复杂度:O(n*n)
  // vector<int> twoSum(vector<int>& nums, int target) {
  //    vector<int> res;
  //     for(int i = 0;i<nums.size()-1;i++){
  //         for(int j = i+1;j<nums.size();j++){
  //             if(nums[i] + nums[j] == target)
  //             {
  //                 res.push_back(i);
  //                 res.push_back(j);
  //                 return res;
  //             }
  //         }
  //     }
  //     return res;
  // }

  // map
  // 时间复杂度:O(n*logn)
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> m;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      if (m.count(target - nums[i])) {
        res.push_back(m[target - nums[i]]);
        res.push_back(i);
        return res;
      } else {
        m[nums[i]] = i;
      }
    }
    return res;
  }
};
