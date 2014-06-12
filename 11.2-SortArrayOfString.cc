//Write a method to sort an array of strings so that all the anagrams are next to each other.
#include<string>
#include<vector>
#include<cstdio>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
 * I though it was palindrome at first.
void SortString(vector<string>&vec)
{
  int cnt = 0;
  for(int i = 0; i<vec.size(); ++i)
  {
    string str(vec[i].rbegin(), vec[i].rend());
    if(str == vec[i])
      swap(vec[i], vec[cnt++]);
  }
}
*/

void SortString(vector<string>&vec)
{
  unordered_map<string, vector<string> >mp;
  for(int i = 0; i<vec.size(); ++i)
  {
    string str = vec[i];
    sort(str.begin(), str.end());
    mp[str].push_back(vec[i]);
  }
  int cnt = 0;
  for(auto it = mp.begin(); it != mp.end(); ++it)
  {
    if(it->second.size()>1)
    {
      for(int i = 0; i<it->second.size(); ++i)
        vec[cnt++] = it->second[i];
    }
  }
  for(auto it = mp.begin(); it != mp.end(); ++it)
  {
    if(it->second.size()==1)
      vec[cnt++] = it->second.back();
  }
}

int main()
{
  vector<string>vec, v;
  vec.push_back("ada");
  vec.push_back("hello world");
  vec.push_back("test");
  vec.push_back("aad");
  vec.push_back("ttes");
  vec.push_back("tste");
  vec.push_back("ttte");
  //copy(vec.begin(), vec.end(), back_inserter(v));
  //printf("%d\n", v.size());
  for(int i = 0; i<vec.size(); ++i)
    printf("%s\n", vec[i].c_str());
  printf("\n");
  SortString(vec);

  for(int i = 0; i<vec.size(); ++i)
    printf("%s\n", vec[i].c_str());
  return 0;
}
