/** 
//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 虚拟头节点，不存数值，方便拼接结果
        ListNode dummy;
        ListNode* cur = &dummy;
        int carry = 0; // 进位
        
        // 只要还有数字没加完 或 存在进位，继续循环
        while(l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + carry;
            
            carry = sum / 10;
            int num = sum % 10;
            
            // 创建新节点接到结果链表尾部
            cur->next = new ListNode(num);
            cur = cur->next;
            
            // 两个链表指针后移
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummy.next;
    }

};