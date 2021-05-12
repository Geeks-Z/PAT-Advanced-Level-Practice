/*
 * @Descripttion: 参考https://www.liuchuo.net/archives/2207
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-12 08:36:32
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-12 09:32:36
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Stu
{
  int id, best;
  int score[4], rank[4];
} stu[2005];

int stuList[1000000] = {0}, sortIndex = -1;
bool cmp(Stu a, Stu b)
{
  return a.score[sortIndex] > b.score[sortIndex];
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m, id;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
    stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
  }

  //每科排序
  for (sortIndex = 0; sortIndex < 4; sortIndex++)
  {
    sort(stu, stu + n, cmp);
    stu[0].rank[sortIndex] = 1;
    for (int i = 1; i < n; i++)
    {
      stu[i].rank[sortIndex] = i + 1;
      if (stu[i].score[sortIndex] == stu[i - 1].score[sortIndex])
      {
        stu[i].rank[sortIndex] = stu[i - 1].rank[sortIndex];
      }
    }
  }

  //寻找最优科目-best
  for (int i = 0; i < n; i++)
  {
    stuList[stu[i].id] = i + 1;
    stu[i].best = 0;
    int minn = stu[i].rank[0];
    for (int j = 1; j <= 3; j++)
    {
      if (stu[i].rank[j] < minn)
      {
        minn = stu[i].rank[j];
        stu[i].best = j;
      }
    }
  }

  char c[5] = {'A', 'C', 'M', 'E'};

  for (int i = 0; i < m; i++)
  {
    cin >> id;
    int temp = stuList[id];
    if (temp)
    {
      int best = stu[temp - 1].best;
      printf("%d %c\n", stu[temp - 1].rank[best], c[best]);
    }
    else
    {
      printf("N/A\n");
    }
  }

  return 0;
}