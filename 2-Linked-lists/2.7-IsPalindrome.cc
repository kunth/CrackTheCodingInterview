#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

bool IsPalindrome(ListNode* head)
{
  if(!head)
    return false;
  ListNode *p = head;
  vector<int>vec;
  do{
      vec.push_back(p->val);
      p = p->next;
  }while(p && p!=head);

  if(!p)
    return false;
  vector<int>rvec(vec.rbegin(), vec.rend());
  return vec==rvec;
}

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* h1 = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    ListNode* h3 = new ListNode(2);
    ListNode* h4 = new ListNode(0);
    head->next = h1;
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = head;
    if(IsPalindrome(head))
      printf("yes\n");
    else
      printf("no\n");
    return 0;
}

