//Same as Leetcode: https://oj.leetcode.com/problems/rotate-image/
//So I tested it on Leetcode.
#include<cstdio>
#include<vector>
using namespace std;

void rotate(vector<vector<int> >&matrix)
{
  if(matrix.empty())
    return;
  int N = matrix.size(), tmp = 0;
  for(int i = 0; i<N; ++i)
  {
    for(int j = 0; j <= i && j < N-1-i; ++j)
    {
      tmp = matrix[i][j];
      matrix[i][j] = matrix[N-1-j][i];
      matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
      matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
      matrix[j][N-1-i] = tmp;
    }
  }
}

int main()
{
  return 0;
}
