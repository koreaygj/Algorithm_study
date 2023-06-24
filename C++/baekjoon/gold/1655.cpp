#include <bits/stdc++.h>
using namespace std;
void solution(){
    int n;
    int mid;
    priority_queue<int> down;
    priority_queue<int, vector<int>, greater<>> up;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        int index = 0;
        cin >> a;
        if(i == 0){
            cout << a << "\n";
            mid = a;
            continue;
        }
        if(i == 1){
            if(mid > a){
                up.push(mid);
                mid = a;
            }
            else{
                up.push(a);
            }
            cout << mid << "\n";
            continue;
        }
        if(mid >= a){
            down.push(a);
            if(down.size() > up.size()){
                up.push(mid);
                mid = down.top();
                down.pop();
            }
        }
        else{
            up.push(a);
            if(up.size() - 1 > down.size()){
                down.push(mid);
                mid = up.top();
                up.pop();
            }
        }
        cout << mid << "\n";
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    solution();
}