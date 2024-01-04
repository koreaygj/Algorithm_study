#include <iostream>
#include <math.h>
using namespace std;

int Point[100001][2];

int calculateDist(int a[], int b[]){
  return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int maxDist(int n){
  int dist = 0;
  for(int i = 0; i < n - 1; i++){
    dist += calculateDist(Point[i], Point[i + 1]);
  }
  return dist;
}

int calculateDiff(int cur){
  int before = cur - 1;
  int next = cur + 1;
  int dist = calculateDist(Point[before], Point[cur]) + calculateDist(Point[cur], Point[next]);
  int skipDist = calculateDist(Point[before], Point[next]);
  return dist - skipDist;
}

int solution(int n){
  int answer;
  int cur = maxDist(n);
  int diff = 0;
  for(int i = 1; i < n - 1; i++){
    diff = max(calculateDiff(i), diff);
  }
  return answer = cur - diff;
}

int main(void){
  int n;
  cin >> n;
  for(int i = 0; i < 100001; i++){
    for(int j = 0; j < 2; j++)
      Point[i][j] = 0;
  }
  for(int i = 0; i < n ;i++){
    cin >> Point[i][0] >> Point[i][1];
  }
  cout << solution(n) << "\n";
  return 0;
}

 