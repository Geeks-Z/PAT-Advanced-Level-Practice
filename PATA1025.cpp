/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-19 17:03:28
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-19 17:19:25
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 101;
struct Stu
{
  string id;
  int score, r, localId;
  Stu(string _id, int _score, int _localId)
  {
    id = _id;
    score = _score;
    localId = _localId;
  }
};

bool cmp(Stu a, Stu b)
{
  if (a.score != b.score)
  {
    return a.score > b.score;
  }
  else
  {
    return a.id < b.id;
  }
}

vector<Stu> allStu;
int main()
{
  // freopen("input.txt", "r", stdin);
  //考场数量 每个考场考生人数 分数 总人数
  int count, k, score, total = 0;
  string id;
  cin >> count;
  for (int i = 0; i < count; i++)
  {
    cin >> k;
    total += k;
    for (int j = 0; j < k; j++)
    {
      cin >> id >> score;
      allStu.push_back(Stu(id, score, i + 1));
    }
    //考场内排序
    sort(allStu.begin() + allStu.size() - k, allStu.end(), cmp);
    int j = allStu.size() - k;
    allStu[j].r = 1;
    for (j; j < allStu.size(); j++)
    {
      if (allStu[j + 1].score == allStu[j].score)
      {
        allStu[j + 1].r = allStu[j].r;
      }
      else
      {
        allStu[j + 1].r = j + 2 - (allStu.size() - k);
      }
    }
  }
  cout << total << endl;
  //所有考生排序
  sort(allStu.begin(), allStu.end(), cmp);
  int r = 1;
  for (int i = 0; i < allStu.size(); i++)
  {

    if (i > 0 && allStu[i].score != allStu[i - 1].score)
    {
      r = i + 1;
      cout << allStu[i].id << ' ' << r << ' ' << allStu[i].localId << ' ' << allStu[i].r << endl;
    }
    else
    {
      cout << allStu[i].id << ' ' << r << ' ' << allStu[i].localId << ' ' << allStu[i].r << endl;
    }
  }
  return 0;
}