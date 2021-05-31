/*
 * @Descripttion: https://blog.csdn.net/liuchuo/article/details/52264827?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162242777116780271580249%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=162242777116780271580249&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_v2~rank_v29-1-52264827.nonecase&utm_term=1038&spm=1018.2226.3001.4450
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-31 10:36:10
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 10:39:56
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp0(string a, string b)
{
  return a + b < b + a;
}
string str[10010];
int main()
{
  // freopen("input.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    cin >> str[i];
  sort(str, str + n, cmp0);
  string s;
  for (int i = 0; i < n; i++)
    s += str[i];
  while (s.length() != 0 && s[0] == '0')
    s.erase(s.begin());
  if (s.length() == 0)
    cout << 0;
  cout << s;
  return 0;
}