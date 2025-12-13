#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        unordered_map<int, int> map; // number, index

        for (int i = 0; i < nums.capacity(); i++) {
            int compliment = target - nums[i];

            if (auto search = map.find(compliment); search != map.end() && search->second != i) {
                solution.push_back(search->second);
                solution.push_back(i);
                return solution;
            }
            map[nums[i]] = i;
        }

        return solution;
    }
};
// @lc code=end
