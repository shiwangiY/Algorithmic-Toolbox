#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long gcd(ll a, ll b)
{

  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long long lcm(int a, int b)
{

  return (a / (gcd(a, b)) * b);
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << lcm(a, b) << endl;
  return 0;
}
