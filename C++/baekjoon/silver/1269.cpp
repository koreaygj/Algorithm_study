#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int answer = a;
    map<int, bool> set;
    for(int i = 0; i < a; i++)
    {
        int input;
        cin >> input;
        set[input] = true;
    }
    for(int i = 0; i < b; i++)
    {
        int input;
        cin >> input;
        if(set.find(input) != set.end())
        {
            answer--;
            continue;
        }
        answer++;
    }
    cout << answer << "\n";
}