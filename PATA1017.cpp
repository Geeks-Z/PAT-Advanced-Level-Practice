/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-13 10:20:55
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-14 17:30:36
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 501;
const int INF = 100010;
bool vis[MAXN] = {false};
//连接矩阵 起点到该点最短距离 点权 station数量 自行车数量 第二标尺最优值
int G[MAXN][MAXN], dis[MAXN], weight[MAXN], n, minNeed = INF, capacity, minBack = INF;
//最优路径  临时路径
vector<int> path[MAXN], tempPath, bestPath;

void dijkstra(int s)
{
  fill(dis, dis + n + 1, INF);
  dis[s] = 0;
  for (int i = 0; i < n + 1; i++)
  {
    //找到最小的u
    int u = -1, min = INF;
    for (int j = 0; j < n + 1; j++)
    {
      if (vis[j] == false && dis[j] < min)
      {
        u = j;
        min = dis[j];
      }
    }

    if (u == -1)
    {
      return;
    }
    vis[u] = true;
    for (int v = 0; v < n + 1; v++)
    {
      if (vis[v] == false && G[u][v] != INF)
      {
        if (dis[u] + G[u][v] < dis[v])
        {
          dis[v] = dis[u] + G[u][v];
          path[v].clear();
          path[v].push_back(u);
        }
        else if (dis[u] + G[u][v] == dis[v])
        {
          path[v].push_back(u);
        }
      }
    }
  }
}
/**
 * @Descripttion: 输出路径
 * @param {int} s 起点
 * @param {int} v 当前访问的结点
 * @return {*}
 */
void DFS(int v)
{
  tempPath.push_back(v);
  if (v == 0)
  {
    int need = 0, back = 0;
    for (int i = tempPath.size() - 1; i >= 0; i--)
    {
      int id = tempPath[i];
      if (weight[id] > 0)
      {
        back += weight[id];
      }
      else
      {
        if (back > (0 - weight[id]))
        {
          back += weight[id];
        }
        else
        {
          need += ((0 - weight[id]) - back);
          back = 0;
        }
      }
    }
    if (need < minNeed)
    {
      minNeed = need;
      minBack = back;
      bestPath = tempPath;
    }
    else if (need == minNeed && back < minBack)
    {
      minBack = back;
      bestPath = tempPath;
    }

    tempPath.pop_back();
    return;
  }

  for (int i = 0; i < path[v].size(); i++)
  {
    DFS(path[v][i]);
  }
  tempPath.pop_back();
}
int main()
{
  // freopen("input.txt", "r", stdin);
  fill(G[0], G[0] + MAXN * MAXN, INF);
  int sp, m;
  cin >> capacity >> n >> sp >> m;
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &weight[i]);
    weight[i] = weight[i] - capacity / 2;
  }

  int s1, s2, time;
  for (int i = 0; i < m; i++)
  {
    cin >> s1 >> s2 >> time;
    G[s1][s2] = G[s2][s1] = time;
  }

  dijkstra(0);
  DFS(sp);

  printf("%d 0", minNeed);
  for (int i = bestPath.size() - 2; i >= 0; i--)
    printf("->%d", bestPath[i]);
  printf(" %d", minBack);

  return 0;
}