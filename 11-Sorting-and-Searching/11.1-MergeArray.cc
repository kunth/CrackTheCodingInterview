//You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a methond to merge B into A in sorted order.
//
#include<cstdio>
#include<algorithm>

void Merge(int A[], int m, int B[], int n)
{
  if(!A || !B)
    return;
  int k = m+n-1;
  while(m && n)
  {
    if(A[m-1] > B[n-1])
      A[k--] = A[--m];
    else
      A[k--] = B[--n];
  }
  while(n)
    A[k--] = A[--n];
}

int main()
{
  int A[100], B[20];
  const int m = 17, n = 19;
  srand(1);
  for(int i = 0; i<m; ++i)
    A[i] = rand() % 120;

  std::sort(A, A+m);
  for(int i = 0; i<m; ++i)
    printf("%d ", A[i]);
  printf("\n");

  srand(11);
  for(int i = 0; i<n; ++i)
    B[i] = rand() % 110;

  std::sort(B, B+n);
  for(int i = 0; i<n; ++i)
    printf("%d ", B[i]);
  printf("\n");

  Merge(A, m, B, n);
  for(int i = 0; i<m+n; ++i)
    printf("%d ", A[i]);
  printf("\n");

  return 0;
}
