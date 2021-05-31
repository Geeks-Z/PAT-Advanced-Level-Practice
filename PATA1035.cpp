/*
 * @Descripttion: Resource:https://blog.csdn.net/yu121380/article/details/88741597
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-31 09:38:51
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 09:39:06
 */
#include <bits/stdc++.h>
using namespace std;

#define e exp(1)
#define p acos(-1)
#define mod 1000000007
#define inf 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define mem(a, b) memset(a, b, sizeof(a))
int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}

const int maxn = 1005;
struct node
{
  string id, password;
} s[maxn];

int main()
{
  string name, password;
  bool flag = false;
  int cnt = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    flag = false;
    cin >> name >> password;
    for (int j = 0; j < password.size(); j++)
    {
      if (password[j] == '1')
      {
        flag = true;
        password[j] = '@';
      }
      else if (password[j] == '0')
      {
        flag = true;
        password[j] = '%';
      }
      else if (password[j] == 'l')
      {
        flag = true;
        password[j] = 'L';
      }
      else if (password[j] == 'O')
      {
        flag = true;
        password[j] = 'o';
      }
    }
    if (flag)
      s[cnt].id = name, s[cnt++].password = password;
  }

  if (cnt == 0)
  {
    if (n == 1)
      printf("There is 1 account and no account is modified\n");
    else
      printf("There are %d accounts and no account is modified\n", n);
  }
  else
  {
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
    {
      cout << s[i].id << " " << s[i].password << endl;
    }
  }

  return 0;
}