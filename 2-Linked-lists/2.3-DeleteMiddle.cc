#include<cstdio>

typedef struct linklist
{
  int val;
  linklist* next;
  linklist():val(0), next(NULL){}
  linklist(int num):val(num), next(NULL){}
}LinkList;

bool Delete(LinkList* node)
{
  if(!node || !node->next)
    return false;
  node->val = node->next->val;
  node->next = node->next->next;
  return true;
}

//if given access to head
void DeleteMiddle(LinkList* head)
{
  if(!head)
    return;
  LinkList *fast = head, *slow = head, *pre = NULL;
  while(fast)
  {
    fast = fast->next;
    if(fast->next)
    {
      pre = slow;
      slow = slow->next;
      fast = fast->next;
    }
  }
  pre->next = pre->next->next;
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
  LinkList *h2 = new LinkList(3);
  LinkList *h3 = new LinkList(4);
  LinkList *h4 = new LinkList(5);
  head->next = h1;
  h1->next = h2;
  h2->next = h3;
  h3->next = h4;

  PR(head);
  if(!Delete(h2))
    printf("error\n");
  PR(head);
  return 0;
}
