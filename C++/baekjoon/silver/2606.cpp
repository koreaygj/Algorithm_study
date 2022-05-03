#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int pc;
vector<vector<int>> link(105, vector<int>(105, 0));
vector<int> memo(105, 0);
int answer = 0;
void solution(int prev)
{
    cout << endl;
    for(int i = 1; i <= pc; i++)
    {
        if(memo[i] == 1)
            continue;
        if(link[prev][i] == 1 || link[i][prev] == 1)
        {
        answer++;
        memo[i] = 1;
        solution(i);
        }
    }
    return;
}

int main(void){
    int n;
    cin >> pc;
    cin >> n;
    memo[1] = 1;
    for(int i = 1;i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        link[a][b] = 1;
    }
    solution(1);
    cout << answer << "\n";
}