/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-11 20:47:50
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-11 20:53:52
 */
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  string res = "WTL";
  double mul = 1.0;
  for (int i = 0; i < 3; i++)
  {
    double maxVal = 0, temp;
    int maxIndex = 0;
    for (int j = 0; j < 3; j++)
    {
      cin >> temp;
      if (temp > maxVal)
      {
        maxVal = temp;
        maxIndex = j;
      }
    }
    cout << res[maxIndex] << ' ';
    mul *= maxVal;
  }
  printf("%.2f", (mul * 0.65 - 1) * 2);
  return 0;
}