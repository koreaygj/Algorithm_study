#include <bits/stdc++.h>

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    int memo[1000001] = {0};
    queue<int> q;
    q.push(x);
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      if(cur == y){
        answer = memo[cur];
        break;
      }
      int next[3] = {cur + n, cur * 2, cur * 3};
      for(auto nx : next){
        if(nx > y || memo[nx] != 0)
          continue;
        memo[nx] = memo[cur] + 1;
        q.push(nx);
      }
    }
    return answer;
}