/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-10 10:03:38
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-10 10:10:07
 */
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  string id, signinTime, signoutTime, minSignInTime = "23:59:59", maxSignOutTime, minSignInId, maxSignOutId;
  int count;
  scanf("%d", &count);
  getchar();
  for (int i = 0; i < count; i++)
  {
    cin >> id >> signinTime >> signoutTime;
    if (signinTime < minSignInTime)
    {
      minSignInId = id;
      minSignInTime = signinTime;
    }
    if (signoutTime > maxSignOutTime)
    {
      maxSignOutId = id;
      maxSignOutTime = signoutTime;
    }
  }
  cout << minSignInId << ' ' << maxSignOutId;
  return 0;
}