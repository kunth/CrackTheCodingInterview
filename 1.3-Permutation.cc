//Firstly, say the sorting solution, which is simple and direct, takes O(nlogn) time.
//Then, come up with a better solution, just O(n) time.
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

bool isPermutation(const string& s1, const string& s2)
{
  if(s1.length() != s2.length())
    return false;
  int arr[256];
  memset(arr, 0, sizeof(arr));
  for(int i = 0; i<s1.length(); ++i)
    ++arr[(int)s1[i]];
  for(int i = 0; i<s2.length(); ++i)
  {
    if(arr[(int)s2[i]])
      --arr[(int)s2[i]];
    else
      return false;
  }
  return true;
}

int main()
{
  string s1 = "c/c++", s2 = "c+/c.";
  string s3 = "asdf zxce", s4= " safdcezx";
  if(isPermutation(s3, s4))
    printf("s3 s4 isPermutation\n");
  else
    printf("s3 s4 not isPermutation\n");

  if(isPermutation(s1, s2))
    printf("s2 s1 isPermutation\n");
  else
    printf("s2 s1 not isPermutation\n");
  return 0;
}
