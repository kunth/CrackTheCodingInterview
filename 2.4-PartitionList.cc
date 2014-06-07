//This subject is a little simpler than https://oj.leetcode.com/problems/partition-list/
//which my solution is https://github.com/kunth/Leetcode/blob/master/Leetcode_partition-list.cpp
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct linklist
{
  int val;
  linklist* next;
  linklist():val(0), next(NULL){}
  linklist(int num):val(num), next(NULL){}
}LinkList;

//solution1: O(n) space
LinkList* Partition(LinkList* head, int v)
{
  if(!head)
    return NULL;
  vector<int>vec;
  LinkList*p = head;
  while(p)
  {
    vec.push_back(p->val);
    p = p->next;
  }
  for(int cur = 0, i = 0, j = vec.size()-1; i<j;)
  {
    if(vec[cur]<v)
    {
      if(cur==i)
        cur = i = i+1;
      else
        swap(vec[cur], vec[i++]);
    }
    else
      swap(vec[cur], vec[j--]);
  }
  p = head;
  for(int i = 0; i<vec.size(); ++i)
  {
    p->val = vec[i];
    p = p->next;
  }
  return head;
}

//solution2: O(1) space
LinkList* Partition2(LinkList* head, int v)
{
  if(!head)
    return NULL;
  LinkList *before = NULL, *after = NULL, *nxt = NULL;
  while(head)
  {
    nxt = head->next;
    if(head->val < v)
    {
      head->next = before;
      before = head;
    }
    else
    {
      head->next = after;
      after = head;
    }
    head = nxt;
  }
  if(!before)
    return after;
  nxt = before;
  while(nxt->next)
    nxt = nxt->next;
  nxt->next = after;
  return before;
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
  LinkList *h1 = new LinkList(8);
  LinkList *h2 = new LinkList(7);
  LinkList *h3 = new LinkList(2);
  LinkList *h4 = new LinkList(5);
  head->next = h1;
  h1->next = h2;
  h2->next = h3;
  h3->next = h4;

  PR(head);
  //Partition1(head, 5);
  head = Partition2(head, 6);
  PR(head);
  return 0;
}
