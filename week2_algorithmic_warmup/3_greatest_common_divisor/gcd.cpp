#include <bits/stdc++.h>
using namespace std;

int gcd_fast(int a, int b)
{
  if (b == 0)
    return a;
  return gcd_fast(b, a % b);
}

int main()
{
  int a, b;
  //cout<<"enter";
  cin >> a >> b;
  cout << gcd_fast(a, b) << endl;
  return 0;
}