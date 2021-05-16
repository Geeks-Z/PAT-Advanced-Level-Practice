/*
 * @Descripttion: 参考https://blog.csdn.net/SYaoJun/article/details/87351227
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-15 16:37:07
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-15 17:11:25
 */
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
map<string, set<int>> mpT, mpA, mpK, mpP, mpY;
void query(map<string, set<int>> &mp, string &str)
{
  if (mp.find(str) == mp.end())
    printf("Not Found\n");
  else
  {
    for (set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++)
    {
      printf("%07d\n", *it);
    }
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m, id, type;
  string title, author, key, pub, year;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &id);
    char c = getchar();
    getline(cin, title);
    mpT[title].insert(id);
    getline(cin, author);
    mpA[author].insert(id);
    while (cin >> key)
    {
      mpK[key].insert(id);
      c = getchar();
      if (c == '\n')
        break;
    }
    getline(cin, pub);
    mpP[pub].insert(id);
    getline(cin, year);
    mpY[year].insert(id);
  }
  string temp;
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    scanf("%d: ", &type);
    getline(cin, temp);
    cout << type << ": " << temp << endl;
    if (type == 1)
      query(mpT, temp);
    else if (type == 2)
      query(mpA, temp);
    else if (type == 3)
      query(mpK, temp);
    else if (type == 4)
      query(mpP, temp);
    else
      query(mpY, temp);
  }
  return 0;
}