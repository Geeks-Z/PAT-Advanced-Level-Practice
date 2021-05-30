/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-30 21:40:14
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-30 22:54:04
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 10001;
const int INF = 0x3fffffff;
vector<int> Adj[MAXN];

int count, curMaxDepth = -1, maxDepth = -1;
bool vis[MAXN] = {false};

void DFS(int s, int depth)
{
  vis[s] = true;
  curMaxDepth = max(curMaxDepth, depth);
  for (int i = 0; i < Adj[s].size(); i++)
  {
    int v = Adj[s][i];
    if (vis[v] == false)
    {
      DFS(v, depth + 1);
    }
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int u, v;
  cin >> count;
  for (size_t i = 0; i < count - 1; i++)
  {
    cin >> u >> v;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
  }
  int cnt = 0;
  vector<int> res;
  for (int i = 1; i <= count; i++)
  {
    if (vis[i] == false)
    {
      cnt++;
      DFS(i, 0);
    }
  }
  if (cnt > 1)
  {
    cout << "Error: " << cnt << " components" << endl;
  }
  else
  {
    for (int i = 1; i <= count; i++)
    {
      curMaxDepth = -1;
      fill(vis, vis + MAXN, false);
      if (vis[i] == false)
      {
        DFS(i, 0);
      }
      if (curMaxDepth > maxDepth)
      {
        maxDepth = curMaxDepth;
        res.clear();
        res.push_back(i);
      }
      else if (curMaxDepth == maxDepth)
      {
        res.push_back(i);
      }
    }
  }

  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << endl;
  }

  return 0;
}