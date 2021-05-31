/*
 * @Descripttion: https://www.liuchuo.net/archives/2142
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-31 16:53:37
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 16:53:56
 */
//建立数组a保存每个数字出现的次数，然后判断输出
#include <iostream>
using namespace std;
int a[1001];
int main()
{
  int n, m, temp;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &temp);
    a[temp]++;
  }
  for (int i = 0; i < 1001; i++)
  {
    if (a[i])
    {
      a[i]--;
      if (m > i && a[m - i])
      {
        printf("%d %d", i, m - i);
        return 0;
      }
      a[i]++;
    }
  }
  printf("No Solution");
  return 0;
}