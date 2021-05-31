/*
 * @Descripttion: https://blog.csdn.net/DayDream_x/article/details/104362662/
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-31 17:07:22
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 17:07:44
 */
//⽤cha[256]数组变量标记str1出现过的字符为true，str2出现过的字符为false,
//输出str1的时候根据cha[str1[i]]是否为true,如果是true就输出
#include <iostream>
#include <string>
using namespace std;
bool cha[256];

int main()
{
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  for (int i = 0; i < s1.size(); i++)
  {
    cha[s1[i]] = true;
  }
  for (int i = 0; i < s2.size(); i++)
  {
    cha[s2[i]] = false;
  }
  for (int i = 0; i < s1.size(); i++)
  {
    if (cha[s1[i]])
      cout << s1[i];
  }
  return 0;
}