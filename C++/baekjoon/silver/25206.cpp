#include <iostream>
#include <map>
using namespace std;
int main() {
  map<string, double> scores;
  scores.insert({"A+", 4.5});
  scores.insert({"A0", 4.0});
  scores.insert({"B+", 3.5});
  scores.insert({"B0", 3.0});
  scores.insert({"C+", 2.5});
  scores.insert({"C0", 2.0});
  scores.insert({"D+", 1.5});
  scores.insert({"D0", 1.0});
  scores.insert({"F", 0.0});
  double grade_sum = 0;
  double score_sum = 0;
  for (int i = 0; i < 20; i++) {
    string tmp, score;
    double grade;
    cin >> tmp >> grade >> score;
    if (score == "P") continue;
    grade_sum += grade;
    score_sum += scores[score] * grade;
  }
  printf("%0.6lf\n", score_sum / grade_sum);
}