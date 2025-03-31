#include <algorithm>
#include <iostream>
#include <queue>
#define fastio cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
struct Part {
  int index;
  int weight;
  int time;
};

int main() {
  fastio;
  int n, m, t;
  cin >> n >> m >> t;
  queue<Part> plane[2];
  for (int i = 0; i < n; i++) {
    int d;
    Part tmp;
    tmp.index = i;
    cin >> d >> tmp.weight >> tmp.time;
    if (d == 0)
      plane[0].push(tmp);
    else
      plane[1].push(tmp);
  }
  bool truck = 0;
  int clock = 0;
  int logs[n][2];
  fill(&logs[0][0], &logs[0][0] + (n * 2), -1);
  while (!plane[0].empty() || !plane[1].empty()) {
    if (!plane[truck].empty()) {
      Part cur_part = plane[truck].front();
      bool is_wait = true;
      if (plane[!truck].empty()) {
        if (cur_part.time > clock) clock = cur_part.time;
      } else {
        Part next_part = plane[!truck].front();
        if (cur_part.time > clock && next_part.time > clock) {
          if (cur_part.time <= next_part.time) {
            is_wait = true;
            clock = cur_part.time;
          } else {
            is_wait = false;
            clock = next_part.time;
          }
        } else if (cur_part.time > clock && next_part.time <= clock) {
          is_wait = false;
        }
      }
      if (is_wait) {
        vector<int> is_all;
        vector<int> index;
        int total_weight = 0;
        while (!plane[truck].empty()) {
          Part tmp = plane[truck].front();
          if (tmp.time > clock) break;
          if (tmp.weight <= m - total_weight) {
            plane[truck].pop();
            index.push_back(tmp.index);
            is_all.push_back(true);
            total_weight += tmp.weight;
          } else {
            if (m - total_weight == 0) break;
            plane[truck].front().weight -= m - total_weight;
            index.push_back(tmp.index);
            is_all.push_back(false);
            break;
          }
        }
        for (int i = 0; i < index.size(); i++) {
          if (logs[index[i]][0] == -1) logs[index[i]][0] = clock;
          if (is_all[i]) logs[index[i]][1] = clock + t;
        }
      }
    }
    truck = !truck;
    clock += t;
  }
  for (const auto log : logs) {
    cout << log[0] << " " << log[1] << "\n";
  }
}