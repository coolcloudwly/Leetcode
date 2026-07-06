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
        //生成虚拟表头
        ListNode dummy;
        //生成移动指针
        ListNode* cur=&dummy;
        //生成进位标识
        int carry=0;
        //循环依据（l1 or l2 不为空 or 进位标识不为0）
        while(l1!=nullptr||l2!=nullptr||carry!=0){
            //取数
            int a= l1?l1->val:0;
            int b=l2?l2->val:0;

            //相加
            int sum=a+b+carry;

            //取进位
            carry=sum/10;
            //取实际数值
            int num=sum%10;

            //移动指针指向新的实际数值
            cur->next=new ListNode(num);
            //移动指针移动
            cur=cur->next;

            //当链表非空，至链表下一位
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return dummy.next;
    }
};