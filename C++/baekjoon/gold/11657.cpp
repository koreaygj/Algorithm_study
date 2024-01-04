#include <bits/stdc++.h>
using namespace std;
struct trunk{
    int st;
    int end;
    int time;
};
int N, M;
vector<trunk> path;
long long int Dist[501];
void print(){
    for(int i = 0; i < path.size(); i++){
        if(Dist[path[i].st] == 987654321)
            continue;
        if(Dist[path[i].end] > Dist[path[i].st] + path[i].time){
            cout << "-1\n";
            return;
        }
    }
    for(int i = 2; i <= N; i++){
        if(Dist[i] == 987654321)
            cout << "-1\n";
        else
            cout << Dist[i] << "\n";
    }

}
void bellman_ford(){
    Dist[1] = 0;
    for(int i = 1; i < N; i++){
        for(int j = 0; j < path.size(); j++){
            if(Dist[path[j].st] == 987654321)
                continue;
            if(Dist[path[j].end] > Dist[path[j].st] + path[j].time)
                Dist[path[j].end] = Dist[path[j].st] + path[j].time;
        }
    }
    print();
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        path.push_back({a, b, c});
    }
    for(int i = 0; i < 501; i++){
        Dist[i] = 987654321;
    }
    bellman_ford();
}