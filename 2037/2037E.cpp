#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

int main() {
  // read in number of test cases
  int t;
  cin >> t;

  // iterate through test cases
  while (t--) {
    // get length of binary string
    int n;
    cin >> n;

    // initialize array of 1s
    int bitstring[n];
    fill(bitstring, bitstring+n, 1);

    // incrementally figure out where 0s should be placed
    int left = 0;
    int right = 1;
    int cumulative_count = 0;
    int zero_count = 0;
    bool is_impossible = false;
    while (right < n) {
      // get number of 01s in the substring
      int count;
      cout << "? " << left + 1 << " " << right + 1 << endl;
      cin >> count;

      if (count - cumulative_count > zero_count) {
        // set 0s to create the right amount of 01s
        int offset_idx = 1;
        while (offset_idx <= count) {
          assert((right - offset_idx) >= 0 && "Number of 01s should never exceed length");
          bitstring[right - offset_idx] = 0;
          offset_idx++;
          zero_count++;
        }        
      } else if (count - cumulative_count == zero_count) {
        // if count is equivalent to zero_count, keep the one
      } else if (count == 0 && cumulative_count == 0) {
        // if both counts are 0, keep going
      } else if (count - cumulative_count == 0) {
        // no new 01s, must be 0
        bitstring[right] = 0;
        zero_count++;
      } else {
        assert(false && "Unreachable");
      }

      // if no 01s and right is at the end, this is impossible
      cumulative_count = count;
      if (cumulative_count == 0 && right == n - 1) {
        is_impossible = true;
        break;
      }

      // increment pointers and update state
      right++;
    }

    // output correct answer
    if (is_impossible) {
      cout << "! IMPOSSIBLE" << endl;
    } else {
      cout << "! ";
      for (int i = 0; i < n; i++) {
        cout << bitstring[i];
      }
      cout << endl;
    }
  }
}  
