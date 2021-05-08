/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-08 20:45:31
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-08 21:26:35
 */
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int a, b, sum;
  cin >> a >> b;
  sum = a + b;
  if (sum < 0)
  {
    cout << '-';
  }
  string str = to_string(abs(sum));
  int len = str.length();
  if (len >= 4)
  {
    for (int i = len - 3; i >= len % 3 && i != 0; i -= 3)
    {
      str.insert(str.begin() + i, ',');
    }
  }
  cout << str;

  return 0;
}