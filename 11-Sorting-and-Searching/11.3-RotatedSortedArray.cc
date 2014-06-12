//Subject: Given a sorted array of n integers that has been rotated an unknown number of times, write code to find an element in the array. You may assume that the array was originally sorted in increasing order.
//Note: No matter how many times the array has benn rotated, it can be split into two increasing order array(rotate in one direction)
//same with leetcode:https://oj.leetcode.com/problems/search-in-rotated-sorted-array/,
//and my leetcode code: https://github.com/kunth/Leetcode/blob/master/Leetcode_search-in-rotated-sorted-array.cc
#include<cstdio>

//return target's index if possibile
int FindInRotatedArray(int A[], int left, int right, int target)
{
  if(!A || left > right)
    return -1;
  if(left == right)
  {
    if(A[left]==target)
      return left;
    else
      return -1;
  }
  int mid = (left+right)/2;
  if(A[left] < A[mid])
  {
    if(target >= A[left] && target<=A[mid])
      return FindInRotatedArray(A, left, mid, target);
    else
      return FindInRotatedArray(A, mid+1, right, target);
  }
  else if(A[left] > A[mid])
  {
    if(A[mid]<=target && target<=A[right])
      return FindInRotatedArray(A, mid, right, target);
    else
      return FindInRotatedArray(A, left, mid-1, target);
  }
  //A[left] == A[mid]
  else
  {
    int ans = FindInRotatedArray(A, left, mid, target);
    if(ans >= 0)
      return ans;
    else
      return FindInRotatedArray(A, mid+1, right, target);
  }
}

int main()
{
  int A[] = {5, 9, 2, 3, 3, 5};
  int ans = FindInRotatedArray(A, 0, sizeof(A)/sizeof(int)-1, 5);
  printf("%d\n", ans);
  return 0;
}
