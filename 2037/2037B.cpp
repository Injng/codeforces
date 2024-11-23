#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // fast io
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // read in number of test cases
  int n;
  cin >> n;

  // iterate through test cases
  for (int i = 0; i < n; i++) {
    // read in number of values
    int k;
    cin >> k;

    // read in all the values
    vector<int> values;
    for (int j = 0; j < k; j++) {
      int value;
      cin >> value;
      values.push_back(value);
    }

    // sort vector in increasing order
    sort(values.begin(), values.end());

    // test all combinations of two dimensions
    int curr_n = values[0];
    bool is_outputted = false;
    for (int j = 0; j < k - 1; j++) {
      if (values[j] != curr_n) {
        curr_n = values[j];
      } else if (j != 0) {
        continue;
      }
      
      for (int l = j + 1; l < k; l++) {
        if (curr_n * values[l] == k - 2) {
          cout << curr_n << " " << values[l] << "\n";
          is_outputted = true;
          break;
        }
      }

      if (is_outputted) break;
    }
  }
}

