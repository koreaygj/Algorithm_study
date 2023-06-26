#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
void solution(){
    int n, m;
    bool book[1001] = {0};
    vector<pair<int, int>> person;
    int ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        person.push_back({a, b});
    }
    sort(person.begin(), person.end(), cmp);
    for(int i = 0; i < m; i++){
        int st = person[i].first;
        int end = person[i].second;
        for(int j = st; j <= end; j++){
            if(!book[j]){
                book[j] = 1;
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solution();
    }
}