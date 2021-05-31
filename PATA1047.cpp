/*
 * @Descripttion: https://www.liuchuo.net/archives/2147
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-31 16:49:21
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 16:50:08
 */
/**
 * 题目大意：给出选课人数和课程数目，然后再给出每个人的选课情况，
 * 请针对每门课程输出选课人数以及所有选该课的学生姓名，按照字典序～
 * 分析：建立int的二维数组，course[i][j] = k表示第i号课程上的人的一个列表，
 * k是上这个课的学生的姓名所在的字符数组name[i][j]的i下标～～
 * 注意：strcmp返回的不一定是-1，0，1这几个数字，
 * 要返回bool变量还需要在后面添加strcmp是大于0还是小于0～～
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
char name[40010][5];
vector<int> course[2510];
bool cmp1(int a, int b)
{
  return strcmp(name[a], name[b]) < 0;
}
int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
  {
    int cnt, temp;
    scanf("%s %d", name[i], &cnt);
    for (int j = 0; j < cnt; j++)
    {
      scanf("%d", &temp);
      course[temp].push_back(i);
    }
  }
  for (int i = 1; i <= k; i++)
  {
    printf("%d %d\n", i, course[i].size());
    sort(course[i].begin(), course[i].end(), cmp1);
    for (int j = 0; j < course[i].size(); j++)
      printf("%s\n", name[course[i][j]]);
  }
  return 0;
}