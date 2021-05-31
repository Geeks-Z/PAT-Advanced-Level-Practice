/*
 * @Descripttion: Resource:https://liuchuo.blog.csdn.net/article/details/52497109?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-3.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-3.control
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-17 14:29:49
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-31 09:23:40
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 99999999;
struct station
{
  double price, dis;
};
bool cmp1(station a, station b)
{
  return a.dis < b.dis;
}
int main()
{
  double cmax, d, davg;
  int n;
  scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
  vector<station> sta(n + 1);
  sta[0] = {0.0, d};
  for (int i = 1; i <= n; i++)
    scanf("%lf%lf", &sta[i].price, &sta[i].dis);
  sort(sta.begin(), sta.end(), cmp1);
  //当前所在的距离 最大距离 当前油价 总价钱 剩余距离(邮箱剩余油可以行驶的距离)
  double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;
  if (sta[0].dis != 0)
  {
    printf("The maximum travel distance = 0.00");
    return 0;
  }
  else
  {
    nowprice = sta[0].price;
  }
  while (nowdis < d)
  {
    maxdis = nowdis + cmax * davg;
    double minPriceDis = 0, minPrice = inf;
    int flag = 0;
    for (int i = 1; i <= n && sta[i].dis <= maxdis; i++)
    {
      if (sta[i].dis <= nowdis)
        continue;
      //处理有比当前加油站更低油价的情况
      if (sta[i].price < nowprice)
      {
        totalPrice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;
        leftdis = 0.0;
        nowprice = sta[i].price;
        nowdis = sta[i].dis;
        flag = 1;
        break;
      }
      //处理比当前加油站油价高的情况
      if (sta[i].price < minPrice)
      {
        minPrice = sta[i].price;
        minPriceDis = sta[i].dis;
      }
    }
    if (flag == 0 && minPrice != inf)
    {
      totalPrice += (nowprice * (cmax - leftdis / davg));
      //从当前加油站加满 行驶至下一加油站后 油箱的油还可行驶的距离
      leftdis = cmax * davg - (minPriceDis - nowdis);
      nowprice = minPrice;
      nowdis = minPriceDis;
    }
    if (flag == 0 && minPrice == inf)
    {
      nowdis += cmax * davg;
      printf("The maximum travel distance = %.2f", nowdis);
      return 0;
    }
  }
  printf("%.2f", totalPrice);
  return 0;
}