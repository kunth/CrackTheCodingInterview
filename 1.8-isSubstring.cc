#include<string>
#include<cstdio>
using namespace std;

bool isSubstr(string s1, string s2)
{
  if(s1.find(s2)!=string::npos)
    return true;
  return false;
}

bool isSubstring(string s1, string s2)
{
  if(s1.length()!=s2.length())
    return false;
  s1 += s1;
  return isSubstr(s1, s2);
}

int main()
{
  string s1 = "erbottlewat", s2 = "bottlewater";
  if(isSubstring(s1, s2))
    printf("yes\n");
  else
    printf("no\n");
  return 0;
}
