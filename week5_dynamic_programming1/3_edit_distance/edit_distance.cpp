#include <iostream>
#include <string>

using std::min;
using std::string;

int edit_distance(const string &str1, const string &str2)
{
  int n = str1.length();
  int m = str2.length();
  int dp[n + 1][m + 1];

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {

      if (i == 0)
        dp[i][j] = j;
      else if (j == 0)
        dp[i][j] = i;

      else if (str1[i - 1] == str2[j - 1])
        dp[i][j] = min(min((dp[i][j - 1] + 1), (dp[i - 1][j] + 1)), dp[i - 1][j - 1]);

      else
      {
        dp[i][j] = min(min((dp[i][j - 1] + 1), (dp[i - 1][j] + 1)), (dp[i - 1][j - 1] + 1));
      }
    }
  }

  return dp[n][m];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
