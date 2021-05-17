/*
 * @Descripttion: 参考https://www.liuchuo.net/archives/2057
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-17 08:10:32
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-17 08:19:47
 */
#include <cstdio>
using namespace std;
int main()
{
  char c[14] = {"0123456789ABC"};
  printf("#");
  for (int i = 0; i < 3; i++)
  {
    int num;
    scanf("%d", &num);
    printf("%c%c", c[num / 13], c[num % 13]);
  }
  return 0;
}