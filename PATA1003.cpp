/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-09 09:58:45
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-09 21:22:37
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
  //边的目标点
  int v;
  //边的权重
  int w;
};

//最大顶点数
const int MAXN = 510;
//定义无穷大 表示没有连接
const int INF = 10000000;
//顶点数 边数 始点 终点
int n, m, st, ed;
//存储最短距离
int dis[MAXN];
//标记结点是否被访问的数组
bool vis[MAXN] = {false};
//每个结点包含的救援小组数量
int weight[MAXN] = {0};
//起点到当前结点的救援小组数量--点权
int helperNum[MAXN] = {0};
//存储距离最短的方案数量
int num[MAXN] = {0};

//存储图信息的邻接表
vector<Node> Adj[MAXN];

/**
 * @Descripttion: 
 * @param {int} s 起点
 * @return {*}
 */
void dijkstra(int s)
{
  //图之间初始化为无连接
  fill(dis, dis + MAXN, INF);
  dis[s] = 0;
  num[s] = 1;
  helperNum[s] = weight[s];

  //n个顶点循环n次
  for (int i = 0; i < n; i++)
  {
    int u = -1;
    int min = INF;
    //寻找未访问的结点中代价最小的
    for (int j = 0; j < n; j++)
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
    //找到最小的u 更新通过u可以使路径变得更短的顶点信息
    for (int j = 0; j < Adj[u].size(); j++)
    {
      int v = Adj[u][j].v;
      //如果v未被访问 && 以u为中介到达v距离更小
      if (vis[v] == false && dis[v] > dis[u] + Adj[u][j].w)
      {
        dis[v] = dis[u] + Adj[u][j].w;
        num[v] = num[u];
        helperNum[v] = helperNum[u] + weight[v];
      }
      else if (vis[v] == false && dis[v] == dis[u] + Adj[u][j].w)
      {
        //路径条数与点权无关
        num[v] += num[u];
        //如果可以获得更多的救援小组
        if (helperNum[v] < helperNum[u] + weight[v])
        {
          helperNum[v] = helperNum[u] + weight[v];
        }
      }
    }
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  scanf("%d%d%d%d", &n, &m, &st, &ed);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &weight[i]);
  }
  int u, v, w;
  //读入边权
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%d", &u, &v, &w);
    Node positive = {v, w};
    Node reverse = {u, w};
    Adj[u].push_back(positive);
    Adj[v].push_back(reverse);
  }

  dijkstra(st);
  printf("%d %d\n", num[ed], helperNum[ed]);
  return 0;
}