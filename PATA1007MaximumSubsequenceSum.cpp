/*
 * @Descripttion: 1007 Maximum Subsequence Sum 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-10 10:48:54
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-10 15:21:15
 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
  freopen("input.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &v[i]);
    temp = temp + v[i];
    //temp < 0时 不管后面是什么数，当前的temp都会降低总和
    if (temp < 0)
    {
      temp = 0;
      tempindex = i + 1;
    }
    else if (temp > sum)
    {
      sum = temp;
      leftindex = tempindex;
      rightindex = i;
    }
  }
  if (sum < 0)
    sum = 0;
  printf("%d %d %d", sum, v[leftindex], v[rightindex]);
  return 0;
}