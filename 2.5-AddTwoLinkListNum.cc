//Same with Leetcode: https://oj.leetcode.com/problems/add-two-numbers/
//And my solution is: https://github.com/kunth/Leetcode/blob/master/Leetcode_add-two-numbers.cc

//copied from my leetcode
class Solution {
public:
    int cnt_list_node(ListNode* head)
    {
        int cnt = 0;
        while(head)
        {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        int v = 0, carry = 0;
        int c1 = cnt_list_node(l1);
        int c2 = cnt_list_node(l2);
        if(c1 < c2)
            swap(l1, l2);
        ListNode*p = l1, *pre = NULL;
        while(l2)
        {
            pre = p;
            v = p->val + l2->val + carry;
            carry = v / 10;
            v %= 10;
            p->val = v;
            p = p->next;
            l2 = l2->next;
        }
        while(carry)
        {
            if(p)
            {
                pre = p;
                v = p->val + carry;
                carry = v/10;
                v %= 10;
                p->val = v;
                p = p->next;
            }
            else
            {
                ListNode* nd = new ListNode(carry);
                pre->next = nd;
                return l1;
            }
        }
        return l1;
    }
};
