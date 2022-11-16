#include <stack>
#include <string>

class Solution {
public:
  bool isValid(std::string str) {
    std::stack<char> st;
    bool ret = true;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
        st.push(str[i]);
      } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
        if (st.empty()) {
          ret = false;
          break;
        }

        if ((str[i] == ')' && st.top() == '(') ||
            (str[i] == ']' && st.top() == '[') ||
            (str[i] == '}' && st.top() == '{')) {
          st.pop();
        } else {
          ret = false;
          break;
        }
      }
    }

    ret = (!st.empty()) ? false : ret;

    return ret;
  }
};
