#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<>> card;
long long int ans;
void solution(){
    if(card.size() == 1)
        return;
    int a = card.top();
    card.pop();
    int b = card.top();
    card.pop();
    ans += a + b;
    card.push(a + b);
    solution();
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        card.push(a);
    }
    solution();
    cout << ans << "\n";
}