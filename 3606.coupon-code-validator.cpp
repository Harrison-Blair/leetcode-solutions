#include <set>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode id=3606 lang=cpp
 *
 * [3606] Coupon Code Validator
 */

// @lc code=start
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> solution;
        unordered_map<string, vector<string>> validCoupons;
        string validBusinessLines[] = {"electronics", "grocery", "pharmacy", "restaurant"};

        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i])
                continue;
            if (code[i].find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_") != string::npos || code[i].empty())
                continue;
            if (businessLine[i] != validBusinessLines[0] && 
                businessLine[i] != validBusinessLines[1] && 
                businessLine[i] != validBusinessLines[2] && 
                businessLine[i] != validBusinessLines[3])
                continue;
            validCoupons[businessLine[i]].push_back(code[i]);
        }

        for (int i = 0; i < 4; i ++) {
            sort(validCoupons[validBusinessLines[i]].begin(), validCoupons[validBusinessLines[i]].end());
            for (string code : validCoupons[validBusinessLines[i]]) {
                solution.push_back(code);
            }
        }

        return solution;
    }
};
// @lc code=end

