/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-11 15:10:36
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-11 16:10:59
 */
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
const int MAXN = 1001;

int main()
{
  // freopen("input.txt", "r", stdin);
  int num1, num2, exp;
  //系数矩阵
  double polyA[MAXN] = {0}, polyB[MAXN] = {0};
  map<int, double> mapp;
  cin >> num1;
  for (int i = 0; i < num1; i++)
  {
    cin >> exp;
    cin >> polyA[exp];
  }
  cin >> num2;
  for (int i = 0; i < num2; i++)
  {
    cin >> exp;
    cin >> polyB[exp];
    for (int i = 0; i < MAXN; i++)
    {
      if (polyA[i] != 0)
      {
        mapp[i + exp] += polyA[i] * polyB[exp];
      }
    }
  }
  //去掉系数为0.0的
  auto iter = mapp.begin();
  while (iter != mapp.end())
  {
    if (iter->second == 0.0)
    {
      mapp.erase(iter++);
    }
    else
    {
      ++iter;
    }
  }
  cout << mapp.size() << ' ';
  map<int, double>::reverse_iterator it;
  for (it = mapp.rbegin(); it != mapp.rend(); it++)
  {
    if (it != mapp.rbegin())
    {
      cout << ' ';
    }
    cout << it->first << ' ';
    printf("%.1f", it->second);
  }

  return 0;
}