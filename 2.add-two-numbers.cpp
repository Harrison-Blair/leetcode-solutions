using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry) {
      int n1 = (l1 != nullptr) ? l1->val : 0;
      int n2 = (l2 != nullptr) ? l2->val : 0;
      int sum = n1 + n2 + carry;
      carry = sum / 10;
      sum %= 10;
      current->next = new ListNode(sum);
      current = current->next;
      if (l1 != nullptr) l1 = l1->next;
      if (l2 != nullptr) l2 = l2->next;
    }
    return dummy->next;
  }
};
// @lc code=end
