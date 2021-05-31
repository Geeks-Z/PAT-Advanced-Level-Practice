/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-31 08:24:01
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 08:40:12
 */
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 100001;
bool vis[MAXN] = {false};
struct node
{
  int next;
  char data;
} Node[MAXN];

int main()
{
  // freopen("input.txt", "r", stdin);
  int st, ed, count, id, idNext;
  char data;
  bool flag = false;
  cin >> st >> ed >> count;
  for (size_t i = 0; i < count; i++)
  {
    // cin >> id >> data >> idNext;
    scanf("%d %c %d", &id, &data, &idNext);
    Node[id].data = data;
    Node[id].next = idNext;
  }
  int temp = st;
  // vis[st] = true;
  while (temp != -1)
  {
    vis[temp] = true;
    temp = Node[temp].next;
  }
  temp = ed;
  while (temp != -1)
  {
    if (vis[temp] == true)
    {
      flag = true;
      cout << temp << endl;
      break;
    }
    temp = Node[temp].next;
  }
  if (!flag)
  {
    cout << -1 << endl;
  }

  return 0;
}