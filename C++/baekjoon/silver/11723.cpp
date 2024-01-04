#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> m;
    int bits = 0;
    for(int i = 0; i < m; i++){
        string order;
        int val = 0;
        cin >> order;
        if(order == "add"){
            cin >> val;
            bits |= (1 <<  val);
        }
        else if(order == "remove"){
            cin >> val;
            bits &= ~(1 << val);
        }
        else if(order == "check"){
            cin >> val;
            if(bits & (1 << val))
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if(order == "toggle"){
            cin >> val;
            bits ^= (1 << val);
        }
        else if(order == "all"){
            bits = (1 << 21) - 1;
        }
        else if(order == "empty"){
            bits = 0;
        }
    }
    return 0;
}