#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    string a, b;
    string answer = "";
    string ans = "";
    cin >> a >> b;
    int size = max(a.size(), b.size()) + 1;
    int add = 0;
    bool flag = false;
    vector<int> i_a(size , 0);
    vector<int> i_b(size , 0);
    int index = 0;
    for(int i = a.size()-1; i >= 0; i--){
        i_a[index++] = a[i] - '0';
    }
    index = 0;
    for(int i = b.size()-1; i >= 0; i--){
        i_b[index++] = b[i] - '0';
    }
    for(int i = 0; i < size; i++){
        add = i_a[i] + i_b[i] + add;
        if(add >= 10)
        {
            answer += to_string(add % 10);
            add /= 10;
            if(i == size - 2)
                flag = true;
        }
        else
        {
            answer += to_string(add);
            add = 0;
        }
    }
    for(int i = size - 1; i >= 0; i--){
        if(flag == false && i == size - 1)
            continue;
        ans += answer[i];
    }
    cout << ans << "\n";
}