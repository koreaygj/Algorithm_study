#include <iostream>
#include <algorithm>
#include <vector>
#define mod 1000000007
using namespace std;
vector<vector<long long int>> answer(2, vector<long long int> (2, 0));
vector<vector<long long int>> multiply(vector<vector<long long int>> matrix_A, vector<vector<long long int>> matrix_B, long long int n){
    vector<vector<long long int>> result(2, vector<long long int> (2, 0));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            long long int sum = 0;
            for(int k = 0; k < 2; k++){
                sum += matrix_A[i][k] * matrix_B[k][j];
            }
            result[i][j] = sum % mod;
        }
    }
    return result;
}
vector<vector<long long int>> &solution(vector<vector<long long int>> &matrix, long long int n){
    if(n == 1){
        return matrix;
    }
    else{
        if(n % 2 == 0){
            vector<vector<long long int>> &temp = solution(matrix, n / 2);
            answer = multiply(temp, temp, n); 
            return answer;
        }
        else{
            vector<vector<long long int>> &temp = solution(matrix, n / 2);
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
    long long int n;
    vector<vector<long long int>> begin(2, vector<long long int> (2, 0));
    begin[0][0] = 1;
    begin[0][1] = 1;
    begin[1][0] = 1;
    cin >> n;
    answer = solution(begin, n);
    cout << answer[0][1];
}