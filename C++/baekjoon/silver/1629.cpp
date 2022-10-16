#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int solution(int a, int b, int c){ 
    if(b == 0)
        return 0;
    if(b == 1)
        return a % c;
    long long int tmp = solution(a, b / 2, c) % c;
    tmp = tmp * tmp % c;
    if(b % 2 == 0)
        return tmp % c;
    else
        return a * tmp % c;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    cout << solution(a, b, c) << "\n";
}