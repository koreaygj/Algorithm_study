#include<bits/stdc++.h>
using namespace std;
class ex{
    public:
        int V;
        int E;
        double arr[5];
        void example();
        double right_sol();
        double wrong_sol();
};
void ex::example(){
    srand(time(NULL));
    for(int i = 0; i < 4; i++){
        arr[i] = rand() % 1000;
    } 
}
//맞는 해설
double ex::right_sol(){
    cout << fixed;
    cout.precision(9);
    double x, y, d, t, ans;
    x = arr[0];
    y = arr[1];
    d = arr[2];
    t = arr[3];
    double dist = sqrt(x * x + y * y);
    if(d < t){
        //cout << dist << "\n";
        return dist;
    }
    else{
        ans = dist;
        int cnt = dist / d;
        dist -= cnt * d;
        if(cnt == 0)
            ans = min(ans, min(t + d - dist, 2.0 * t));
        else
            ans = min(ans, min(cnt * t + dist, (cnt + 1.0) * t));
        //cout << ans << "\n";
        return ans;
    }
    return ans;
}
//틀린 답
double ex::wrong_sol(){
	cout << fixed;
	cout.precision(9);
    double X, Y, D, T, ans;
    X = arr[0];
    Y = arr[1];
    D = arr[2];
    T = arr[3];
	double d = sqrt(pow(X, 2) + pow(Y, 2));
	if (D < T) // 점프하는것보다 걷는게 더 빠를 때
	{
		//cout << d << '\n';
        return d;
	}
	else
	{
		ans = d;

		int jump = d / D; // 점프 횟수
		d -= jump * D; // 남은 거리

		if (jump == 0) ans = min(ans, min(T + D - d, 2.0 * T));
		else ans = min(ans, min(jump * T + d, (jump + 1.0) * T));
		return ans;
		//cout << ans << '\n';
	}
    return ans;
}
int main(void){
    ex tc;
    int cnt = 0;
    while(cnt <= 100){
        tc.example();
        cnt++;
        double right = tc.right_sol();
        double wrong = tc.wrong_sol();
        if(right != wrong){
            for(int i = 0; i < 4; i++){
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
}