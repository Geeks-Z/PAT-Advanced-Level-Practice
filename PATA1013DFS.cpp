/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-12 11:29:14
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-12 11:55:03
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1001;
vector<int> Adj[MAXN];
bool vis[MAXN];

void DFS(int u)
{
  vis[u] = true;
  for (int i = 0; i < Adj[u].size(); i++)
  {
    int v = Adj[u][i];
    if (vis[v] == false)
    {
      DFS(v);
    }
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int cityNum, highwayNum, checkNum;
  cin >> cityNum >> highwayNum >> checkNum;
  int city1, city2;
  for (int i = 0; i < highwayNum; i++)
  {
    cin >> city1 >> city2;
    Adj[city1].push_back(city2);
    Adj[city2].push_back(city1);
  }
  int checkCity;
  for (int i = 0; i < checkNum; i++)
  {
    //城市标号从1 - n
    fill(vis, vis + cityNum + 1, false);
    int cnt = 0;
    cin >> checkCity;
    vis[checkCity] = true;
    for (int j = 1; j <= cityNum; j++)
    {
      if (vis[j] == false)
      {
        DFS(j);
        cnt++;
      }
    }
    cout << cnt - 1 << endl;
  }

  return 0;
}