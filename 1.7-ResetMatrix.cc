//Write an algorithm such that if an element in an M*N matrix is 0, its entire row and column are set to 0.
//ResetMatrix is done by myself, but its turns out bad efficiency.
//ResetMatrix2 is done according to the book, which I think is much better.
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

void SetF(vector<vector<bool> >&f, int r, int c)
{
  for(int i = 0; i<f.size(); ++i)
    f[i][c] = true;
  for(int j = 0; j<f[0].size(); ++j)
    f[r][j] = true;
}

void ResetMatrix(vector<vector<int> >&matrix)
{
  if(matrix.empty())
    return;
  int row = matrix.size();
  int col = matrix[0].size();
  vector<vector<bool> >f(row, vector<bool>(col, false));
  for(int i = 0; i<row; ++i)
  {
    for(int j = 0; j<col; ++j)
    {
      if(matrix[i][j]==0)
      {
        f[i][j] = true;
        SetF(f, i, j);
        //break; //Break here is wrong.
      }
    }
  }
  for(int i = 0; i<row; ++i)
  {
    for(int j = 0; j<col; ++j)
    {
      if(f[i][j])
        matrix[i][j] = 0;
    }
  }
}

//According to the book's solution
void ResetMatrix2(vector<vector<int> >&matrix)
{
  if(matrix.empty())
    return;
  int row = matrix.size(), col = matrix[0].size();
  bool* frow = new bool[row];
  bool* fcol = new bool[col];
  memset(frow, false, sizeof(frow));
  memset(fcol, false, sizeof(fcol));
  for(int i = 0; i<row; ++i)
  {
    for(int j = 0; j<col; ++j)
    {
      if(matrix[i][j]==0)
        frow[i] = fcol[j] = true;
    }
  }
  for(int i = 0; i<row; ++i)
  {
    for(int j = 0; j<col; ++j)
    {
      if(frow[i] || fcol[j])
        matrix[i][j] = 0;
    }
  }
  delete frow;
  delete fcol;
}

//test output
void PR(vector<vector<int> >&mat)
{
  for(int i = 0; i<mat.size(); ++i)
  {
    for(int j = 0; j<mat[0].size(); ++j)
    {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main()
{
  vector<vector<int> >input;
  int a1[] = {1, 2, 3, 0, 5};
  int a2[] = {5, 4, 1, 2, 1};
  int a3[] = {1, 9, 1, 2, 3};
  int a4[] = {1, 3, 0, 1, 0};
  int a5[] = {1, 2, 2, 1, 4};
  vector<int>v1, v2, v3, v4, v5;
  v1.insert(v1.end(), a1, a1+sizeof(a1)/sizeof(int));
  v2.insert(v2.end(), a2, a2+sizeof(a2)/sizeof(int));
  v3.insert(v3.end(), a3, a3+sizeof(a3)/sizeof(int));
  v4.insert(v4.end(), a4, a4+sizeof(a4)/sizeof(int));
  v5.insert(v5.end(), a5, a5+sizeof(a5)/sizeof(int));
  input.push_back(v1);
  input.push_back(v2);
  input.push_back(v3);
  input.push_back(v4);
  input.push_back(v5);
  vector<vector<int> >input2(input);
  PR(input);
  ResetMatrix(input);
  PR(input);

  PR(input2);
  ResetMatrix2(input2);
  PR(input2);
  return 0;
}
