/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-11 14:53:12
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-11 15:00:08
 */
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int count, res = 0, cur = 0, nextFloor;
  scanf("%d", &count);
  res += count * 5;
  for (int i = 0; i < count; i++)
  {
    cin >> nextFloor;
    if (nextFloor >= cur)
    {
      res += 6 * (nextFloor - cur);
    }
    if (nextFloor < cur)
    {
      res += 4 * (cur - nextFloor);
    }
    cur = nextFloor;
  }

  cout << res;
  return 0;
}