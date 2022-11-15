struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * 注意点：1. 过十进位 2.链表长度不等 3.最后的进位
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 检查入参
    if (!l1) {
      return l2;
    }

    if (!l2) {
      return l1;
    }

    // 执行相加过程
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int carry = 0;

    while (l1 || l2) {
      int x = l1 ? l1->val : 0;
      int y = l2 ? l2->val : 0;
      int sum = x + y + carry;
      carry = sum / 10;

      ListNode* node = new ListNode(sum % 10);
      if (!head) {
        head = node;
        tail = node;
      } else {
        tail->next = node;
        tail = node;
      }

      if (l1) {
        l1 = l1->next;
      }
      if (l2) {
        l2 = l2->next;
      }
    }

    // 最后的进位
    if (carry) {
      ListNode* node = new ListNode(carry);
      tail->next = node;
    }

    return head;
  }
};
