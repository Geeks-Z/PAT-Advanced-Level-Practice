/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-09 08:36:36
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-30 11:13:31
 */
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main()
{
  freopen("input.txt", "r", stdin);
  map<int, double> mapp;
  for (int i = 0; i < 2; i++)
  {
    //多项式数量 指数 系数
    int count, exp;
    double coefficients;
    cin >> count;
    for (int j = 0; j < count; j++)
    {
      cin >> exp >> coefficients;
      mapp[exp] += coefficients;
    }
  }

  //删除系数为0.0的键值对--报错
  /* map<int, double>::iterator it;
  for (it = mapp.begin(); it != mapp.end(); it++)
  {
    if (it->second == 0.0)
    {
      mapp.erase(it);
    }
  } */
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

  cout << mapp.size();
  if (mapp.size() > 0)
  {
    cout << ' ';
  }
  map<int, double>::reverse_iterator revit;
  for (revit = mapp.rbegin(); revit != mapp.rend(); revit++)
  {
    if (revit != mapp.rbegin())
    {
      cout << ' ';
    }
    printf("%d %.1f", revit->first, revit->second);
  }

  return 0;
}