#include<cstdio>
#include<cstring>

void Replace(char str[], int len)
{
  int blank = 0;
  for(int i = 0; i<len; ++i)
  {
    if(str[i]==' ')
      ++blank;
  }
  int nl = len + 2*blank;
  str[nl--] = '\0';
  for(int i = len-1; i>=0; --i)
  {
    if(str[i]==' ')
    {
      str[nl--] = '0';
      str[nl--] = '2';
      str[nl--] = '%';
    }
    else
      str[nl--] = str[i];
  }
}

int main()
{
  char str[100], ch[] = "hello Crack The Coding Interview";
  //strncpy(str, ch, sizeof(ch));
  strcpy(str, ch);
  Replace(str, strlen(ch));
  printf("%s\n", ch);
  printf("%s\n", str);
  return 0;
}
