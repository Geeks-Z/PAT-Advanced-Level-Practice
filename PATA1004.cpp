/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-14 19:50:13
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-14 21:35:27
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 101;
vector<int> parent[MAXN];
bool vis[MAXN] = {false};
int maxDep = -1, leaf[MAXN] = {0};
void DFS(int s, int depth)
{
  vis[s] = true;
  if (parent[s].size() == 0)
  {
    leaf[depth]++;
    maxDep = max(depth, maxDep);
  }
  else
  {
    for (int i = 0; i < parent[s].size(); i++)
    {
      DFS(parent[s][i], depth + 1);
    }
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  //结点数量 非叶子结点
  int n, m, id, k, child;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> id >> k;
    for (int j = 0; j < k; j++)
    {
      cin >> child;
      parent[id].push_back(child);
    }
  }
  DFS(1, 0);

  for (int i = 0; i <= maxDep; i++)
  {
    if (i > 0)
    {
      cout << " ";
    }
    cout << leaf[i];
  }

  return 0;
}