#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;
  
int L, R, C;
char map[31][31][31];
int dist[31][31][31];

struct point{
  int l;
  int r; 
  int c;
};

bool checkNext(point next){
  if(next.l < 0 || next.l >= L || next.r < 0 || next.r >= R || next.c < 0 || next.c >= C)
    return false;
  if(map[next.l][next.r][next.c] == '#')
    return false;
  if(dist[next.l][next.r][next.c] != INF )
    return false;
  return true;
}

int solution(point startPoint){
  int moveL[] = {-1, 1, 0, 0, 0, 0};
  int moveR[] = {0, 0, -1, 1, 0, 0};
  int moveC[] = {0, 0, 0, 0, -1, 1};
  queue<point> q;
  q.push(startPoint);
  dist[startPoint.l][startPoint.r][startPoint.c] = 0;
  while(!q.empty()){
    point st = q.front();
    q.pop();
    if(map[st.l][st.r][st.c] == 'E')
      return dist[st.l][st.r][st.c];
    for(int i = 0; i < 6; i++){
      point next;
      next.l = st.l + moveL[i];
      next.r = st.r + moveR[i];
      next.c = st.c + moveC[i];
      if(checkNext(next)){
        dist[next.l][next.r][next.c] = dist[st.l][st.r][st.c] + 1;
        q.push(next);
      }
      else{
        continue;
      }
    }
  }
  return INF;
}

void reset(){
  for(int i = 0; i < 31; i++){
    for(int j = 0; j < 31; j++){
      for(int k = 0; k < 31; k++){
        map[i][j][k] = ' ';
        dist[i][j][k] = INF;
      }
    }
  }
}


int main(void){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  vector<int> answer;
  while(1){
    point startPoint;
    cin >> L >> R >> C;
    if(L == 0 && R == 0 && C == 0)
      break;
    for(int i = 0; i < L; i++){
      for(int j = 0; j < R; j++){
        string tmp;
        cin >> tmp;
        for(int k = 0; k < C; k++){
          map[i][j][k] = tmp[k];
          if(map[i][j][k] == 'S'){
            startPoint.l = i;
            startPoint.r = j;
            startPoint.c = k;
          }
          dist[i][j][k] = INF;
        }
      }
    }
    answer.push_back(solution(startPoint));
    reset();
  }
  for(int i = 0; i < answer.size(); i++){
    int ans = answer[i];
    if(ans == INF){
      cout << "Trapped!\n";
    }else{
      cout << "Escaped in " << ans << " minute(s).\n";
    }
  }
}