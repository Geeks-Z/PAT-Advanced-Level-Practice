/*
 * @Descripttion: https://www.liuchuo.net/archives/2019
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-31 12:31:49
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 12:32:21
 */
//简单模拟。使用start和end数组保存每一次变换的开始顺序和结束顺序
//（以1~54的编号存储） 最后根据编号与扑克牌字母数字的对应关系输出end数组
#include <cstdio>
using namespace std;
int main()
{
  int cnt;
  scanf("%d", &cnt);
  int start[55], end[55], scan[55];
  for (int i = 1; i < 55; i++)
  {
    scanf("%d", &scan[i]);
    end[i] = i;
  }
  for (int i = 0; i < cnt; i++)
  {
    for (int j = 1; j < 55; j++)
      start[j] = end[j];
    for (int k = 1; k < 55; k++)
      end[scan[k]] = start[k];
  }
  char c[6] = {"SHCDJ"};
  for (int i = 1; i < 55; i++)
  {
    end[i] = end[i] - 1;
    printf("%c%d", c[end[i] / 13], end[i] % 13 + 1);
    if (i != 54)
      printf(" ");
  }
  return 0;
}