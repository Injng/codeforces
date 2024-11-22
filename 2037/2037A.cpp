#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // fast io
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // read in number of test cases
  int t;
  cin >> t;

  // iterate through test cases
  for (int i = 0; i < t; i++) {
    // read in length of array
    int n;
    cin >> n;

    // read in array
    vector<int> a;
    for (int j = 0; j < n; j++) {
      int aj;
      cin >> aj;
      a.push_back(aj);
    }

    // sort the array
    sort(a.begin(), a.end());

    // calculate score
    int score = 0;
    int curr_value = a[0];
    bool scored = false;
    for (int j = 1; j < n; j++) {
      if (scored) {
        curr_value = a[j];
        scored = false;
      } else if (a[j] == curr_value) {
        score++;
        scored = true;
      } else {
        curr_value = a[j];
      }
    }

    // output final score
    cout << score << "\n";
  }
}

