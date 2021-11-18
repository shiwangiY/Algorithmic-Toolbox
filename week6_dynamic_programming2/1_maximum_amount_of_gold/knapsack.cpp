#include <iostream>
#include <vector>

using std::max;
using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
  int n = w.size();
  vector<vector<int>> v(n + 1, vector<int>(W + 1));
  int current_weight = 0;

  for (size_t i = 0; i <= n; i++)
  {
    for (size_t j = 1; j <= W; j++)
    {
      if (i == 0 || j == 0)
        v[i][j] = 0;
      else if (w[i - 1] <= j)
        v[i][j] = max(w[i - 1] + v[i - 1][j - w[i - 1]], v[i - 1][j]);

      else
        v[i][j] = v[i - 1][j];
    }
  }

  current_weight = v[n][W];

  return current_weight;
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
