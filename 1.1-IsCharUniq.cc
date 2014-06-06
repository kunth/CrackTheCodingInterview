//First, ask whether it is a ASCII char set or Unicode char set
//Secod, say the most simple solution, compare every character of the string to every other character, which takes O(n^2) time.
//Then, sorting is another solution, but the string may not be allowed to modify.

#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

//based on the char varies from 'a' to 'z'
bool IsCharUniq(const string& str)
{
  int flag = 0;
  for(int i = 0; i<str.length(); ++i)
  {
    if(flag & 1<<(str[i]-'a'))
      return false;
    flag |= 1<<(str[i]-'a');
  }
  return true;
}

//based on that the string is a ASCII string
bool IsCharUniq2(const string& str)
{
  int idx;
  bool f[256];
  memset(f, false, sizeof(f));
  for(int i = 0; i<str.length(); ++i)
  {
    idx = (int)str[i];
    if(f[idx])
      return false;
    f[idx] = true;
  }
  return true;
}

//test IsCharUniq
int
main()
{
  string str = "endurac !@*$ ";
  if(IsCharUniq2(str))
    printf("is unique\n");
  else
    printf("had duplicate char\n");
  return 0;
}
