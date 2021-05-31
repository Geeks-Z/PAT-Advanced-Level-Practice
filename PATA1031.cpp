/*
 * @Descripttion: 参考https://blog.csdn.net/liuchuo/article/details/52119867
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-17 10:07:34
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-17 10:50:12
 */
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
  char c[81], u[30][30];
  memset(u, ' ', sizeof(u));
  scanf("%s", c);
  int n = strlen(c) + 2;
  //分析：假设n = 字符串长度 + 2，因为2 * n1 + n2 = n，且要保证n2 >= n1, n1尽可能地大，分类讨论：
  //1. 如果n % 3 == 0，n正好被3整除，直接n1 == n2 == n3;
  //2. 如果n % 3 == 1，因为n2要比n1大，所以把多出来的那1个给n2
  //3. 如果n % 3 == 2, 就把多出来的那2个给n2
  //所以得到公式：n1 = n / 3，n2 = n / 3 + n % 3
  int n1 = n / 3, n2 = n / 3 + n % 3, index = 0;
  for (int i = 0; i < n1; i++)
    u[i][0] = c[index++];
  for (int i = 1; i <= n2 - 2; i++)
    u[n1 - 1][i] = c[index++];
  for (int i = n1 - 1; i >= 0; i--)
    u[i][n2 - 1] = c[index++];
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < n2; j++)
      printf("%c", u[i][j]);
    printf("\n");
  }
  return 0;
}