#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void print(vector<vector<int>> arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
    cout << endl;
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, k;
    int answer = 0;
    long long int ans1 = 0;
    long long int ans2 = 2000000000000;
    cin >> n >> m >> k;
    vector<vector<bool>> board(n + 1, vector<bool> (m + 1, 0));
    vector<vector<int>> temp(n + 1, vector<int> (m + 1, 0));
    vector<vector<long long int>> sum(n + 1, vector<long long int> (m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
             char tmp;
             cin >> tmp;
            board[i][j] = tmp == 'W' ? 1 : 0;
        }
    }
    bool prev = board[1][1];
    for(int i = 1; i <= n ;i++){
        int cnt = 0;
        for(int j = 1; j <= m; j++){
            if(board[i][j] != prev)
                cnt++;
            temp[i][j] = cnt;
            sum[i][j] += temp[i][j] + sum[i - 1][j];
             prev = !prev;
        }
        if(m % 2 == 0)
            prev = !prev;
    }
    for(int i = 1; i <= n - k + 1; i++){
        for(int j = 1; j <= m - k + 1; j++){
            long long int answer = sum[i + k -1][j + k -1] - sum[i - 1][j + k - 1] - sum[i + k -1][j - 1] + sum[i -1][j - 1];
            ans1 = max(ans1, answer);
            ans2 = min(ans2, answer);
        }
    }
    cout << min(ans2, k * k - ans1) << "\n";
}