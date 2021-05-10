/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-10 09:53:56
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-10 09:58:20
 */
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  string list[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  string input, output;
  int sum;
  cin >> input;
  int len = input.length();
  for (int i = 0; i < len; i++)
  {
    sum += (input[i] - '0');
  }
  output = to_string(sum);
  int outputLen = output.length();
  for (int i = 0; i < outputLen; i++)
  {
    if (i > 0)
    {
      cout << ' ';
    }
    cout << list[output[i] - '0'];
  }

  return 0;
}