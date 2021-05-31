/*
 * @Descripttion: https://blog.csdn.net/liuchuo/article/details/54428567
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-31 15:36:12
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 16:07:14
 */
//因为sum数组是递增的，所以改用二分法查找
//Func函数的作用是二分查找，修改tempsum和j的值
//一开始接收输入的时候可以直接保存它的sum函数，即sum[i]表示1～i的所有数字的总和
#include <iostream>
#include <vector>
using namespace std;
vector<int> sum, resultArr;
int n, m;
void Func(int i, int &j, int &tempsum)
{
  int left = i, right = n;
  //返回第一个大于等于m的right
  while (left < right)
  {
    int mid = (left + right) / 2;
    if (sum[mid] - sum[i - 1] >= m)
      right = mid;
    else
      left = mid + 1;
  }
  j = right;
  tempsum = sum[j] - sum[i - 1];
}
int main()
{
  // freopen("input.txt", "r", stdin);
  scanf("%d%d", &n, &m);
  sum.resize(n + 1);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &sum[i]);
    sum[i] += sum[i - 1];
  }
  int minans = sum[n];
  for (int i = 1; i <= n; i++)
  {
    int j, tempsum;
    Func(i, j, tempsum);
    if (tempsum > minans)
      continue;
    if (tempsum >= m)
    {
      if (tempsum < minans)
      {
        resultArr.clear();
        minans = tempsum;
      }
      resultArr.push_back(i);
      resultArr.push_back(j);
    }
  }
  for (int i = 0; i < resultArr.size(); i += 2)
    printf("%d-%d\n", resultArr[i], resultArr[i + 1]);
  return 0;
}