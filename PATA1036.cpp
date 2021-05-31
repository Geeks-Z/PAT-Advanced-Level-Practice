/*
 * @Descripttion: https://blog.csdn.net/chenyutingdaima/article/details/81978251
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-31 09:42:01
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 09:43:14
 */
//1.用结构体数组存储相关信息，用先按性别排序，将女性排在前面，再按分数降序排序，
//这样数组首位是女性最高，末尾是男性最低。
//2.输出时，判断首位和末尾是否是正确的性别，有一个不对，就输出NA。
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node
{
  char name[15], id[15], gender;
  int grade;
} node[110];
bool cmp(Node a, Node b)
{
  if (a.gender != b.gender)
    return a.gender < b.gender;
  else
    return a.grade > b.grade;
}

int main()
{
  int n;
  bool flag = true;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%s %c %s %d", node[i].name, &node[i].gender, node[i].id, &node[i].grade);
  }
  sort(node, node + n, cmp);
  if (node[0].gender == 'F')
  {
    printf("%s %s\n", node[0].name, node[0].id);
  }
  else
  {
    printf("Absent\n");
    flag = false;
  }
  if (node[n - 1].gender == 'M')
  {
    printf("%s %s\n", node[n - 1].name, node[n - 1].id);
  }
  else
  {
    printf("Absent\n");
    flag = false;
  }
  if (flag == true)
  {
    printf("%d\n", node[0].grade - node[n - 1].grade);
  }
  else
  {
    printf("NA\n");
  }
  return 0;
}