#include<cstdio>
#include<algorithm>
#include<unordered_map>
using namespace std;

//Samw with leetcode: https://oj.leetcode.com/problems/linked-list-cycle-ii/
//1. use hash map 2. break in the circle into 2 linked list with same postfix, find the first same postfix
//

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//Solution 1, copied from my Leetcode: https://github.com/kunth/Leetcode/blob/master/Leetcode_linked-list-cycle-ii.cc

class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool>mp;
        while(head)
        {
            if(mp[head]==true)
                return head;
            mp[head] = true;
            head = head->next;
        }
        return NULL;
    }
};

//Solution 2, break the circle. Without extra space.
class Solution {
private:
    int Cnt_link_len(ListNode* head)
    {
        int cnt = 0;
        while(head)
        {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode *fast = head->next, *slow = head;
        while(fast && fast != slow)
        {
            fast = fast->next;
            if(fast)
                fast = fast->next;
            else
                return NULL;
            slow = slow->next;
        }
        if(!fast)
            return NULL;
        fast = fast->next;
        slow->next = NULL;
        int len1 = Cnt_link_len(head);
        int len2 = Cnt_link_len(fast);
        if(len1<len2)
            swap(head, fast);
        len1 = len1>=len2 ? len1-len2 : len2-len1;
        while(len1--)
            head = head->next;
        while(head && head != fast)
        {
            head = head->next;
            fast = fast->next;
        }
        if(!head)
            return NULL;
        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(-1);
    ListNode* h1 = new ListNode(-7);

    ListNode* h2 = new ListNode(7);
    ListNode* h3 = new ListNode(-4);
    ListNode* h4 = new ListNode(19);
    ListNode* h5 = new ListNode(6);
    ListNode* h6 = new ListNode(-9);
    ListNode* h7 = new ListNode(-5);
    ListNode* h8 = new ListNode(-2);
    ListNode* h9 = new ListNode(-5);

    head->next = h1;
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    h7->next = h8;
    h8->next = h9;
    h9->next = h6;

    Solution* so = new Solution();
    ListNode* ans = so->detectCycle(head);
    printf("%d\n", ans->val);
    return 0;
}

