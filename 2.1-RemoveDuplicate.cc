//If you want to compile this, use g++ -std=c++0x
//If extra space is not allowed(in place), then the time would be 0(N^2)
#include<cstdio>
#include<unordered_map>
using namespace std;

typedef struct linklist
{
  int val;
  linklist* next;
  linklist():val(0), next(NULL){};
  linklist(int num):val(num), next(NULL){};
}LinkList;

//time:O(N), space:O(N), if unordered_map's space is considered to be O(N)
void RemoveDuplicate(LinkList* head)
{
  if(!head)
    return;
  unordered_map<int, bool>mp;
  mp[head->val] = true;
  LinkList *cur = head->next, *pre = head;
  while(cur)
  {
    if(mp[cur->val]==true)
    {
      pre->next = cur->next;
      cur = cur->next;
    }
    else
    {
      mp[cur->val] = true;
      cur = cur->next;
      pre = pre->next;
    }
  }
}

//time:O(n^2), space:O(1)
void RemoveInPlace(LinkList* head)
{
  if(!head)
    return;
  LinkList *cur = head, *nxt = NULL, *p = NULL;
  while(cur)
  {
    nxt = cur;
    p = nxt->next;
    while(p)
    {
      if(p->val == cur->val)
        nxt->next = p->next;
      else
        nxt = nxt->next;

      p = p->next;
    }
    cur = cur->next;
  }
}

//print list element
void PR(LinkList* head)
{
  if(!head)
    return;
  LinkList*p = head;
  while(p)
  {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
}

int main()
{
  LinkList *head = new LinkList(1);
  LinkList *h1 = new LinkList(2);
  LinkList *h2 = new LinkList(1);
  LinkList *h3 = new LinkList(1);
  LinkList *h4 = new LinkList(1);
  head->next = h1;
  h1->next = h2;
  h2->next = h3;
  h3->next = h4;
  PR(head);
  //RemoveDuplicate(head);
  RemoveInPlace(head);
  PR(head);
  return 0;
}
