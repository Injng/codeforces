#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct PowerUp {
  long long location;
  long long value;
  bool used;
  
  PowerUp(long long l, long long v, bool u) : location(l), value(v), used(u) {} 
};

int main() {
  // fast io
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // get number of test cases
  int t;
  cin >> t;

  // iterate through each test case
  while (t--) {
    // n: number of hurdles, m: number of power ups, L: the end position
    int n, m;
    long long L;
    cin >> n >> m >> L;

    // get location of hurdles
    vector<pair<long long, long long>> hurdles;
    for (int i = 0; i < n; i++) {
      long long left, right;
      cin >> left >> right;
      hurdles.emplace_back(left, right);
    }

    // get location and value of power ups
    vector<PowerUp> powerups;
    for (int i = 0; i < m; i++) {
      long long loc, value;
      cin >> loc >> value;
      powerups.push_back(PowerUp(loc, value, false));
    }

    // keep track and calculate power ups needed
    long long power = 1;
    int count = 0;
    bool impossible = false;
    for (int i = 0; i < hurdles.size(); i++) {
      // calculate power needed to get over hurdle
      long long power_needed = hurdles[i].second - hurdles[i].first + 2;

      // if not enough power, find a power up
      if (power < power_needed) {
        // consider all possible powerups that can be reached
        int p_idx = 0;
        vector<PowerUp*> possibilities;
        while (powerups[p_idx].location < hurdles[i].first && p_idx < powerups.size()) {
          if (!powerups[p_idx].used) possibilities.push_back(&powerups[p_idx]);
          p_idx++;
        }

        // sort all the possible powerups
        sort(possibilities.begin(), possibilities.end(),
             [](const PowerUp* a, const PowerUp* b) {
               return a->value > b->value;
             });

        // starting from the largest, take as little powerups as possible to meet need
        p_idx = 0;
        while (power < power_needed && p_idx < possibilities.size()) {
          power += possibilities[p_idx]->value;
          possibilities[p_idx]->used = true;
          count++;
          p_idx++;
        }

        // if power is still not enough, this is impossible
        if (power < power_needed) {
          impossible = true;
          break;
        }
      }   
    }

    // output as necessary
    if (impossible) {
      cout << "-1\n";
    } else {
      cout << count << "\n";
    }
  }
}

