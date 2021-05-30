/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-12 20:09:40
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-30 20:25:02
 */
#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int val)
{
  //要在这里做判断 否则有个测试点过不去 <=1的数都不是素数
  if (val <= 1)
  {
    return false;
  }
  for (int i = 2; i <= (int)sqrt(1.0 * val); i++)
  {
    if (val % i == 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  freopen("input.txt", "r", stdin);
  int num, d;
  while (scanf("%d", &num) != EOF)
  {
    if (num < 0)
    {
      break;
    }
    cin >> d;
    if (isPrime(num) == false) //本身就不是素数
    {
      cout << "No" << endl;
      continue;
    }
    int rev = 0;
    //获取d进制下的相反数
    while (num != 0)
    {
      rev = rev * d + (num % d);
      num = num / d;
    }
    // cout << rev << ' ';
    if (isPrime(rev))
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }

  return 0;
}