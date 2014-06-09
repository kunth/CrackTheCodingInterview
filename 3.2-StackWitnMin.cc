#include<cstdio>
#include<vector>
#include<cassert>
using namespace std;

const int STACKSIZE = 1000;

class StackWithMin{
  int cur_size;
  vector<int>vec, minv;

public:
  StackWithMin()
  {
    cur_size = 0;
    vec.reserve(STACKSIZE);
  }
  int get_stack_size()
  {
    return cur_size;
  }
  void push(int x)
  {
    assert(cur_size < STACKSIZE);
    vec[cur_size++] = x;
    if(minv.empty() || minv.back()>= x)
      minv.push_back(x);
  }

  int pop()
  {
    assert(cur_size);
    if(minv.back()==vec[cur_size-1])
      minv.pop_back();
    return vec[--cur_size];
  }
  int min()
  {
    assert(cur_size);
    return minv.back();
  }
};

int main()
{
  StackWithMin s;
  s.push(5);
  s.push(3);
  s.push(7);
  s.push(3);
  int a = s.min();
  printf("%d\n", a);
  a = s.pop();
  printf("%d\n", a);
  a = s.min();
  printf("%d\n", a);
  s.push(10);
  s.push(1);
  a = s.min();
  printf("%d\n", a);
  a = s.pop();
  printf("%d\n", a);
  a = s.pop();
  printf("%d\n", a);
  a = s.pop();
  printf("%d\n", a);
  a = s.pop();
  printf("%d\n", a);
  a = s.min();
  a = s.pop();
  printf("%d\n", a);
  //a = s.min();
  //a = s.pop();
  //printf("%d\n", a);
  return 0;
}
