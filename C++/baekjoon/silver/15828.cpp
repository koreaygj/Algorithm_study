#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, block = 1;
    cin >> n;
    queue<int> buffer;
    while(block >= 0){
        cin >> block;
        if(buffer.size() == n)
        {
            if(block == 0)
                buffer.pop();
            continue;
        }
        if(block == 0)
            buffer.pop();
        else if(block > 0)
            buffer.push(block);
    }
    if(buffer.size() == 0){
        cout << "empty" << endl;
        return 0;
    }
    int tmp = buffer.size();
    for(int i = 0; i < tmp; i++){
        cout << buffer.front() << " ";
        buffer.pop();
    }
    cout << endl;
    return 0;
}