#include <cmath>
#include <iostream>

using namespace std;

bool is_composite(int x) {
  int limit = sqrt(x);
  for (int i = 2; i <= limit; i++) {
    if (x % i == 0) return true;
  }
  return false;
}

int main() {
  // fast io
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // read in number of test cases
  int t;
  cin >> t;

  // iterate through each test case
  for (int i = 0; i < t; i++) {
    // read in permutation length
    int n;
    cin >> n;

    /*
      Since all even numbers are composite, all we need to do is find a way for
      an odd+even number to be composite as the boundary.
    */
    int odd_boundary = -1;
    int even_boundary = -1;
    bool is_break = false;
    for (int j = 1; j <= n; j += 2) {
      for (int k = 2; k <= n; k += 2) {
        if (is_composite(j + k)) {
          odd_boundary = j;
          even_boundary = k;
          is_break = true;
        }
      }
      if (is_break) break;
    }

    // if boundaries are found, return permutation; otherwise return -1
    if (odd_boundary != -1 && even_boundary != -1) {
      // output odds
      for (int j = 1; j <= n; j += 2) {
        if (j != odd_boundary) cout << j << " ";
      }
      cout << odd_boundary << " ";

      // output evens
      cout << even_boundary << " ";
      for (int j = 2; j <= n; j += 2) {
        if (j != even_boundary) cout << j;
        if (j < n - 1) cout << " ";
      }
      cout << "\n";
    } else {
      cout << "-1\n";
    }
  }
}

