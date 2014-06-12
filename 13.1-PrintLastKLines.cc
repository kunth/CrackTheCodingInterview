//Write a methond to print the last K lines of an input file using c++
//
#include<fstream>
#include<iostream>
using namespace std;

void PrintLastKLines(char* filepath, int K)
{
  ifstream ifs(filepath);
  string str[K];
  int cnt = 0;
  while(ifs.good())
  {
    getline(ifs, str[cnt%K]);
    ++cnt;
  }
  if(cnt < K)
  {
    for(int i = 0; i<cnt; ++i)
      cout<<str[i]<<endl;
  }
  else
  {
    for(int i = cnt%K; i<K; ++i)
      cout<<str[i]<<endl;
    for(int i = 0; i<cnt%K; ++i)
      cout<<str[i]<<endl;
  }
}

int main()
{
  char* path = "11.2-SortArrayOfString.cc";
  PrintLastKLines(path, 11);
  return 0;
}
