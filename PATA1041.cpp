/*
 * @Descripttion: https://www.liuchuo.net/archives/2139
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-31 12:19:23
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 12:19:42
 */
#include <cstdio>
using namespace std;
int a[100001], m[100000];
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    m[a[i]]++;
  }
  for (int i = 0; i < n; i++)
  {
    if (m[a[i]] == 1)
    {
      printf("%d", a[i]);
      return 0;
    }
  }
  printf("None");
  return 0;
}