/*
 * @Descripttion: https://www.liuchuo.net/archives/2021
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-31 16:36:15
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 16:42:22
 */
//简单模拟。所有结点连起来会形成一个环形，
//dis[i]存储第1个结点到第i个结点的下一个结点的距离，
//sum保存整个路径一圈的总和值。
//求得结果就是dis[right – 1] – dis[left – 1]和 sum – dis[right – 1] – dis[left – 1]中较小的那一个～～
//注意：可能left和right的顺序颠倒了，这时候要把left和right的值交换
#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n;
  scanf("%d", &n);
  vector<int> dis(n + 1);
  int sum = 0, left, right, cnt;
  for (int i = 1; i <= n; i++)
  {
    int temp;
    scanf("%d", &temp);
    sum += temp;
    dis[i] = sum;
  }
  scanf("%d", &cnt);
  for (int i = 0; i < cnt; i++)
  {
    scanf("%d %d", &left, &right);
    if (left > right)
      swap(left, right);
    int temp = dis[right - 1] - dis[left - 1];
    printf("%d\n", min(temp, sum - temp));
  }
  return 0;
}