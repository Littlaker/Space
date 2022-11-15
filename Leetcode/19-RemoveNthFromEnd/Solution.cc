struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 快慢指针
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) {
      return nullptr;
    }

    ListNode dummy(0, head);
    ListNode* fast = head;
    ListNode* slow = &dummy;

    while (n-- && fast) {
      fast = fast->next;
    }

    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy.next;
  }
};
