//money change again

#include <bits/stdc++.h>

std::vector<int> denominations = {1, 3, 4};

int get_change(int m)
{
  std::vector<int> change(m + 1, m + 1);
  change[0] = 0;
  for (int i = 0; i < change.size(); i++)
  {
    for (int j = 0; j < denominations.size(); j++)
    {
      if (denominations[j] <= i)
      {
        change[i] = std::min(change[i], change[i - denominations[j]] + 1);
      }
    }
  }
  return change[m] == (m + 1) ? -1 : change[m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
