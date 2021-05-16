/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-15 08:54:59
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-15 09:15:24
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int a, b, flag = 0;
  cin >> a >> b;
  vector<int> res;
  while (a != 0)
  {
    res.push_back(a % b);
    a = a / b;
  }
  for (int i = 0; i < res.size() / 2; i++)
  {
    if (res[i] != res[res.size() - 1 - i])
    {
      flag = 1;
      break;
    }
  }
  if (flag)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
  if (res.size() == 0)
  {
    cout << "0";
  }
  for (int i = res.size() - 1; i >= 0; i--)
  {
    if (i < res.size() - 1)
    {
      cout << ' ';
    }
    cout << res[i];
  }

  return 0;
}