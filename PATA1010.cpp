/*
 * @Descripttion: Source:https://www.liuchuo.net/archives/2458
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-30 19:06:16
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-30 19:31:35
 */
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
/**
 * @Descripttion: 给定一个数值和一个进制，将它转化为10进制
 * @param {string} n
 * @param {long long} radix
 * @return {*}
 */
long long convert(string n, long long radix)
{
  long long sum = 0;
  int index = 0, temp = 0;
  for (auto it = n.rbegin(); it != n.rend(); it++)
  {
    temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
    sum += temp * pow(radix, index++);
  }
  return sum;
}

/**
 * @Descripttion: 找到令两个数值相等的进制数-二分查找
 * @param {string} n
 * @param {long long} num
 * @return {*}
 */
long long find_radix(string n, long long num)
{
  //max_element查询最大值所在的第一个位置
  char it = *max_element(n.begin(), n.end());
  //最低位需保证n有意义
  long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
  long long high = max(num, low);
  while (low <= high)
  {
    long long mid = (low + high) / 2;
    long long t = convert(n, mid);
    //如果使用当前进制转化得到数值比另一个大或者小于0，说明这个进制太大
    if (t < 0 || t > num)
      high = mid - 1;
    else if (t == num)
      return mid;
    else
      low = mid + 1;
  }
  return -1;
}
int main()
{
  // freopen("input.txt", "r", stdin);
  string n1, n2;
  long long tag = 0, radix = 0, result_radix;
  cin >> n1 >> n2 >> tag >> radix;
  result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
  if (result_radix != -1)
  {
    printf("%lld", result_radix);
  }
  else
  {
    printf("Impossible");
  }
  return 0;
}