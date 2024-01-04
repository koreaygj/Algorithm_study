#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> answer(10, vector<int> (10, 0));
void print(vector<vector<int>> &matrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] % 1000 << " ";
        cout << "\n";
    }
}
vector<vector<int>> multiply(vector<vector<int>> matrix_A, vector<vector<int>> matrix_B, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int sum = 0;
            for(int k = 0; k < n; k++){
                sum += matrix_A[i][k] * matrix_B[k][j];
            }
            answer[i][j] = sum % 1000;
        }
    }
    return answer;
}
vector<vector<int>> &solution(vector<vector<int>> &matrix, int n, long long int count){
    if(count == 1){
        return matrix;
    }
    else{
        if(count % 2 == 0){
            vector<vector<int>> &temp = solution(matrix, n, count / 2);
            answer = multiply(temp, temp, n); 
            return answer;
        }
        else{
            vector<vector<int>> &temp = solution(matrix, n, count / 2);
            answer = multiply(temp, temp, n);
            answer = multiply(answer, matrix, n);
            return answer;
        }
    }
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    long long int b;
    cin >> n >> b;
    vector<vector<int>> matrix(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    answer = solution(matrix, n, b);
    print(answer, n);
}