#include <algorithm>
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(false)

using namespace std;

struct Region {
  int x;
  int y;
  int d1;
  int d2;
  Region(int x, int y, int d1, int d2) : x(x), y(y), d1(d1), d2(d2) {}
};

bool checkValid(Region* r, const int& n) {
  return r->x + r->d1 + r->d2 <= n && r->y + r->d2 <= n && r->y - r->d1 > 0;
}

int calculate_diff(const vector<vector<int>>& city, Region* r, const int& n) {
  int sum[5] = {};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      // 1
      if (1 <= i && i < r->x + r->d1 && 1 <= j && j <= r->y &&
          i - r->x < -j + r->y) {
        sum[0] += city[i][j];
      }
      // 2
      else if (1 <= i && i <= r->x + r->d2 && r->y < j && j <= n &&
               i - r->x < j - r->y) {
        sum[1] += city[i][j];
      }
      // 3
      else if (r->x + r->d1 <= i && i <= n && 1 <= j &&
               j < r->y - r->d1 + r->d2 &&
               i - r->x - r->d1 > j - r->y + r->d1) {
        sum[2] += city[i][j];
      }
      // 4
      else if (r->x + r->d2 < i && i <= n && r->y - r->d1 + r->d2 <= j &&
               j <= n && i - r->x - r->d2 > -j + r->y + r->d2) {
        sum[3] += city[i][j];
      }
      // 5
      else
        sum[4] += city[i][j];
    }
  }

  int max_sum = sum[0], min_sum = sum[0];
  for (int i = 1; i < 5; i++) {
    max_sum = max_sum < sum[i] ? sum[i] : max_sum;
    min_sum = min_sum > sum[i] ? sum[i] : min_sum;
  }
  return max_sum - min_sum;
}

int main() {
  fastio;
  int n;
  cin >> n;

  vector<vector<int>> city(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cin >> city[i][j];
  }

  Region* region = new Region(1, 1, 1, 1);
  int min_diff = 40005;
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++) {
      for (int d1 = 1; d1 < n; d1++) {
        for (int d2 = 1; d2 < n; d2++) {
          region->x = x;
          region->y = y;
          region->d1 = d1;
          region->d2 = d2;
          if (checkValid(region, n)) {
            int rs = calculate_diff(city, region, n);
            min_diff = min_diff > rs ? rs : min_diff;
          }
        }
      }
    }
  }

  cout << min_diff << "\n";
  return 0;
}