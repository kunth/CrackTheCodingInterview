#include<string>
#include<cstdio>
using namespace std;

string Compression(const string& str)
{
  if(str.empty())
    return str;
  string ans;
  char ch = str[0];
  int cnt = 1;
  for(int i = 1; i < str.length(); ++i)
  {
    if(str[i]==ch)
      ++cnt;
    else
    {
      ans += ch;
      ans += '1' + cnt - 1;
      cnt = 1;
      ch = str[i];
    }
  }
  //ans.append(1, ch);
  ans += ch;
  ans += '1' + cnt - 1;
  return ans.length() < str.length() ? ans : str;
};

int main()
{
  string str = "aabcccccaaa";
  string ans = Compression(str);
  printf("%s\n", str.c_str());
  printf("%s\n", ans.c_str());
  return 0;
}
