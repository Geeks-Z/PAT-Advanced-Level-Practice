/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-15 20:41:41
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-15 22:01:06
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindromic(string str)
{
  int len = str.length();
  for (int i = 0; i < len / 2; i++)
  {
    if (str[i] != str[len - 1 - i])
    {
      return false;
    }
  }
  return true;
}

string add(string str)
{
  string reverseStr = str;
  reverse(reverseStr.begin(), reverseStr.end());
  int carry = 0, len = str.length();
  for (int i = len - 1; i >= 0; i--)
  {
    str[i] = str[i] + reverseStr[i] + carry - '0';
    carry = 0;
    if (str[i] - '0' > 9)
    {
      carry = 1;
      str[i] = str[i] - 10;
    }
  }
  if (carry)
  {
    str = "1" + str;
  }
  return str;
}
int main()
{
  // freopen("input.txt", "r", stdin);
  string n, beforeN;
  int k, step = 0, len = 0;
  cin >> n >> k;
  if (isPalindromic(n))
  {
    cout << n << endl;
    cout << 0;
  }
  else
  {
    for (int i = 1; i <= k; i++)
    {
      if (!isPalindromic(n))
      {
        // beforeN = n;
        // reverse(n.begin(), n.end());
        //部分不通过
        // n = to_string(stol(beforeN) + stol(n));
        n = add(n);
        step = i;
      }
      else
      {
        break;
      }
    }
    cout << n << endl;
    cout << step;
  }

  return 0;
}