#include<cstdio>
#include<cstring>
#include<algorithm>

void reverse(char* str)
{
  if(!str)
    return;
  int i = 0, j = strlen(str)-1;
  while(i<j)
  {
    std::swap(str[i++], str[j--]);
  }
}

//if strlen could not be inclued, then
void reverse2(char* str)
{
  if(!str)
    return;
  char* end = str;
  while(*end)
    ++end;
  --end;
  while(str < end)
    std::swap(*str++, *end--);
}

int main()
{
  char str[] = "Nothing can take the place of persistance!";
  printf("%s\n", str);
  reverse(str);
  printf("%s\n", str);
  reverse2(str);
  printf("%s\n", str);

  //if you want to write like this: char *p = "endurance"
  //you should malloc space for it, otherwise it would collapse in the reverse function.
  //char *p = "sedgewick";
  //reverse2(p);
  return 0;
}
