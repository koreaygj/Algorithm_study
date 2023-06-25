#include <bits/stdc++.h>
using namespace std;
struct jewel{
    int weight;
    int cost;
};
bool cmp(jewel a, jewel b){
    return a.weight < b.weight;
}
void solution(){
    int n, k;
    vector<jewel> info;
    vector<int> bag;
    cin >> n >> k;
    long long int ans = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        info.push_back({a, b});
    }
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        bag.push_back(a);
    }
    sort(info.begin(), info.end(), cmp);
    sort(bag.begin(), bag.end());
    priority_queue<int> pq;
    int index = 0;
    for(int i = 0; i < k; i++){
        while(index < n && info[index].weight <= bag[i]){
            pq.push(info[index++].cost);
        }
        if(pq.empty())
            continue;
        else{
            ans += pq.top();
            pq.pop();
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