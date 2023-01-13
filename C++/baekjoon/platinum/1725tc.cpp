#include <iostream>
#include <stack>
#include <stdlib.h>
#include <time.h>
using namespace std;
class ex{
    public:
        int n;
        int arr[100010];
        void example();
        int right_sol();
        int wrong_sol();
};
void ex::example(){
    srand(time(NULL));
    n = rand() % 100000 + 1;
    for(int i = 1; i <= n; i++){
        arr[i] = rand() % 1000000001;
    } 
}
//맞는 해설
int ex::right_sol(){
    stack<int> s;
    int ans = 0;
    s.push(0);
    for (int i = 1; i <= n + 1; i++){
        while (!s.empty() && arr[s.top()] > arr[i]){
	        int check = s.top();
	        s.pop();
	        ans = max(ans, arr[check]*(i - s.top() - 1));
        }
    s.push(i);
    }
    return ans;
}
//틀린 답
int ex::wrong_sol(){
    int ans = 0;
    stack<int> st;
    st.push(0);
    for(int i = 1; i <= n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            int index = st.top();
            st.pop();
            ans = max(ans, arr[index] * (i - st.top() - 1));
        }
        st.push(i);
    }
    return ans;
}
int main(void){
    ex tc;
    tc.example();
    int cnt = 0;
    while(cnt <= 100){
        cnt++;
        int right = tc.right_sol();
        int wrong = tc.wrong_sol();
        if(right != wrong){
            cout << tc.n << endl;
            for(int i = 0; i < tc.n; i++){
                cout << tc.arr[i] << " ";
            }
            cout << endl;
            cout << "ans: " << right << endl;
            cout << "wrong: " << wrong << endl;
            return 0;
        }
        else
        {
            tc.example();
        }
    }
    cout << "maybe correct! " << endl;
}