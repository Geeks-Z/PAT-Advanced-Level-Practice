/*
 * @Descripttion: 参考《算法笔记》 胡凡 曾磊
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-29 15:05:44
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-29 16:20:02
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAXN = 2010;
const int INF = 1000000010;
int n, k, numPerson = 0, G[MAXN][MAXN] = {0}, weight[MAXN];
bool vis[MAXN] = {false};

//解决string int 对应关系 1.map/string数组 2. hash
map<string, int> mId;
map<int, string> mName;
map<string, int> Gang;

/**
 * @Descripttion: 处理字名称与编号的映射
 * @param {string} str
 * @return {*}
 */
int getId(string str)
{
  if (mId.find(str) != mId.end())
  {
    return mId[str];
  }
  else
  {
    mId[str] = numPerson;
    mName[numPerson] = str;
    return numPerson++;
  }
}

/**
 * @Descripttion: 访问单个连通块
 * @param {int} nowVisit 现在访问的编号
 * @param {int} &numMember 总成员数量
 * @param {int} &sum 总的通话时间
 * @param {int} &head 头目
 * @return {*}
 */
void DFS(int nowVisit, int &numMember, int &sum, int &head)
{
  numMember++;
  vis[nowVisit] = true;
  //更新头目
  if (weight[nowVisit] > weight[head])
  {
    head = nowVisit;
  }
  //枚举所有人
  for (int i = 0; i < numPerson; i++)
  {
    if (G[nowVisit][i] > 0)
    {
      sum += G[nowVisit][i];
      //删除该边 防止重复访问
      G[nowVisit][i] = G[i][nowVisit] = 0;
      if (vis[i] == false)
      {
        DFS(i, numMember, sum, head);
      }
    }
  }
}

void DFSTravel()
{
  for (int i = 0; i < numPerson; i++)
  {
    if (vis[i] == false)
    {
      int head = i, numMember = 0, sum = 0;
      DFS(i, numMember, sum, head);
      if (numMember > 2 && sum > k)
      {
        Gang[mName[head]] = numMember;
      }
    }
  }
}
int main()
{
  // freopen("input.txt", "r", stdin);
  string a, b;
  int min;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b >> min;
    int id1 = getId(a);
    int id2 = getId(b);
    G[id1][id2] += min;
    G[id2][id1] += min;
    weight[id1] += min;
    weight[id2] += min;
  }
  DFSTravel();
  cout << Gang.size() << endl;
  map<string, int>::iterator it;
  for (it = Gang.begin(); it != Gang.end(); it++)
  {
    cout << it->first << ' ' << it->second << endl;
  }

  return 0;
}