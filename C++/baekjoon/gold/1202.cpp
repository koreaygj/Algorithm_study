#include <bits/stdc++.h>
using namespace std;
struct jewel{
    int weight;
    int cost;
};
bool cmp(jewel a, jewel b){
    if(a.cost == b.cost){
        return a.weight < b.weight;
    }
    return a.cost > b.cost;
}
void solution(){
    int n, k;
    vector<jewel> info;
    multiset<int> bag;
    cin >> n >> k;
    long long int ans = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        info.push_back({a, b});
    }
    sort(info.begin(), info.end(), cmp);
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        bag.insert(a);
    }
    int sz = info.size();
    for(int i = 0; i < n; i++){
        int tmp = info[i].weight;
        auto it = bag.lower_bound(tmp);
        if(it != bag.end()){
            ans += info[i].cost;
            bag.erase(it);
        }
    }
    cout << ans << "\n";
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    solution();
}