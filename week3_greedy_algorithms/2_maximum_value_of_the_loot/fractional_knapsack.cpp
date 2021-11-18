#include <bits/stdc++.h>
#include <vector>
#include <iomanip>
using namespace std;

int maxIndex(vector<int> weights, vector<int> values)
{
  int index = 0;
  double max = 0;

  for (size_t i = 0; i < weights.size(); i++) //unsigned int (size_t) is used
  {
    if (weights[i] != 0 && (double)values[i] / weights[i] > max)
    {
      max = (double)values[i] / weights[i];
      index = i;
    }
  }

  return index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;

  for (size_t i = 0; i < weights.size(); i++)
  {
    //base case
    if (capacity == 0)
      return value;
    int index = maxIndex(weights, values);
    int ratio = min(capacity, weights[index]);
    value += ratio * (double)values[index] / weights[index];

    weights[index] -= ratio;
    capacity -= ratio;
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
