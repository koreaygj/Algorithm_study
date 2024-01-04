#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    double x, y, d, t, ans;
    cin >> x >> y >> d >> t;
    double dist = sqrt(x * x + y * y);
    cout << fixed;
    cout.precision(9);
    if(dist < t){
        cout << dist << "\n";
    }
    else{
        ans = dist;
        int cnt = dist / d;
        dist -= cnt * d;
        if(cnt == 0)
            ans = min(ans, min(t + d - dist, 2.0 * t));
        else
            ans = min(ans, min(cnt * t + dist, (cnt + 1.0) * t));
        cout << ans << "\n";
    }
    return 0;
}