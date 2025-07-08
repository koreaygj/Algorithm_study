#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0) -> cin.tie(0)

using namespace std;
int main(){
	int n;
	cin >> n;
	string map;
	cin >> map;
	int ans = 0;
	for(int i = 0;i < n; i++){
		if(map[i] == 'E' && map[i + 1] == 'W')
			ans++;
	}
	cout << ans << "\n";
}
