#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> matrix_A(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix_A[i][j];
    cin >> m >> k;
    vector<vector<int>> matrix_B(m, vector<int> (k, 0));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < k; j++)
            cin >> matrix_B[i][j];
    vector<vector<int>> answer(101, vector<int> (101, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            int sum = 0;
            for(int l = 0; l < m; l++){
                sum += matrix_A[i][l] * matrix_B[l][j]; 
            }
            answer[i][j] = sum;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++)
            cout << answer[i][j] << " ";
        cout << "\n";
    }
}