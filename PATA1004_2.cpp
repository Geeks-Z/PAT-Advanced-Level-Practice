/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-30 16:01:41
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-30 16:05:03
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool inq[101] = {false};
int num[101] = {0};
//结点的静态写法
struct node
{
  //深度
  int depth;
  vector<int> childs;
} Node[101];
//便于按层序输出叶子结点
int maxDepth = 0;

//层序遍历
void BFS(int s)
{
  queue<int> q;
  Node[s].depth = 1;
  inq[s] = true;
  q.push(s);
  while (!q.empty())
  {
    int top = q.front();
    q.pop();
    //更新最大层数
    if (Node[top].depth > maxDepth)
    {
      maxDepth = Node[top].depth;
    }
    //叶子结点
    if (Node[top].childs.size() == 0)
    {
      num[Node[top].depth]++;
    }
    else
    { //添加非叶子结点
      for (int i = 0; i < Node[top].childs.size(); i++)
      {
        if (inq[Node[top].childs[i]] == false)
        {
          Node[Node[top].childs[i]].depth = Node[top].depth + 1;
          q.push(Node[top].childs[i]);
          inq[Node[top].childs[i]] = true;
        }
      }
    }
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int nodesNum, nonleafNodesNum, id, k, child;
  //读取输入
  cin >> nodesNum >> nonleafNodesNum;
  for (int i = 0; i < nonleafNodesNum; i++)
  {
    cin >> id >> k;
    for (int j = 0; j < k; j++)
    {
      cin >> child;
      Node[id].childs.push_back(child);
    }
  }

  BFS(1);
  //按要求输出
  for (int i = 1; i <= maxDepth; i++)
  {
    if (i > 1)
    {
      cout << ' ';
    }

    cout << num[i];
  }

  return 0;
}