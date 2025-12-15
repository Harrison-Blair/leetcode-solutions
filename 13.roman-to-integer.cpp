#include <string>
#include <unordered_map>

using namespace std;
/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
 public:
  unordered_map<char, int> numeralValues = {
      {'I', 1},
      {'V',5},
      {'X',10},
      {'L',50},
      {'C',100},
      {'D',500},
      {'M',1000},
  };

  int romanToInt(string s) {
    int value = 0;

    for (int i = 0; i < s.length(); i++) {
      if (numeralValues[s[i]] < numeralValues[s[i + 1]]) {
        value += numeralValues[s[i + 1]] - numeralValues[s[i]];
        i++;
      } else
        value += numeralValues[s[i]];
    }

    return value;
  }
};
// @lc code=end
