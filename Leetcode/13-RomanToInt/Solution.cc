#include <map>
#include <string>

class Solution {
public:
  int romanToInt(std::string str) {
    if (str.empty()) {
      return -1;
    }

    std::map<char, int> m = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                             {'C', 100}, {'D', 500}, {'M', 1000}};
    int ret = 0;
    int prevNum = m[str[0]];
    for (int i = 0; i < str.length(); i++) {
      if (m.find(str[i]) == m.end()) {
        ret = -1;
        break;
      }

      int curNum = m[str[i]];

      if (curNum > prevNum) {
        ret = ret + curNum - 2 * prevNum;
      } else {
        ret = ret + curNum;
      }
      prevNum = curNum;
    }
    return ret;
  }
};
