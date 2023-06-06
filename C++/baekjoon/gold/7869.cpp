#include <bits/stdc++.h>
using namespace std;
struct circle{
    double x, y, r;
};
double Distance(circle a, circle b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double theta(double a, double b, double c){
    return acos((a * a + b * b - c * c) / (2 * a * b));
}
double cal(circle first, circle second){
    double dis = Distance(first, second);
    if(dis > first.r){
        double degreeA = 0, degreeB = 0;
        double ans = 0;
        degreeA = theta(first.r, dis, second.r) * 2 * 180 / M_PI;
        ans += first.r * first.r * M_PI * degreeA / 360;
        ans -= first.r * first.r * sin(degreeA * M_PI / 180) / 2;
        degreeB = theta(second.r, dis, first.r) * 2  * 180 / M_PI;
        ans += second.r * second.r * M_PI * degreeB / 360;
        ans -= second.r * second.r * sin(degreeB * M_PI / 180) / 2;       
        return ans;
    }
    else{
        double degreeA, degreeB;
        double ans = 0;
        degreeA = (theta(first.r, dis, second.r) * 2 ) * 180 / M_PI;
        degreeB = (theta(dis, second.r, first.r) * 2 ) * 180 / M_PI;
        ans += second.r * second.r * M_PI * degreeB / 360;
        ans += first.r * first.r * M_PI * degreeA / 360;
        ans -= sin(degreeA * M_PI / 360) * first.r * dis;
        return ans;
    }
    return 1;
}
double solution(circle first, circle second){
    double dis = Distance(first, second);
    double ans = 0;
    if(first.r < second.r)
        swap(first.r, second.r);
    if(dis >= first.r + second.r)
        return 0;
    else if(dis <= first.r - second.r)
        return second.r * second.r * M_PI;
    else if(first.r - second.r < dis && dis < first.r + second.r)
        return ans = cal(first, second);
    return ans;
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    circle first, second;
    cin >> first.x >> first.y >> first.r >> second.x >> second.y >> second.r;
	cout << fixed;
	cout.precision(3);
    cout << solution(first, second) << "\n";
}