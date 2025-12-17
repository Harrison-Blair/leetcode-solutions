#include <unordered_set>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=2110 lang=cpp
 *
 * [2110] Number of Smooth Descent Periods of a Stock
 */

// @lc code=start
class Solution {
 public:
  long long getDescentPeriods(vector<int>& prices) {
    long total = 0;
    int count = 1;

    for (int i = 0; i < prices.size(); i++) {
      if (i == 0) {
        total += count;
        continue;
      }

      if (prices[i - 1] - 1 == prices[i])
        count++;
      else
        count = 1;

        total += count;
    }
    return total;
  }
};
// @lc code=end
