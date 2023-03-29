#include<bits/stdc++.h>
using namespace std;
void Postorder(int st, int end, int *node){
	if (st >= end) {
		return;
	}
	if (st == end - 1) {
		cout << node[st] << '\n';
		return;
	}
	int idx = st + 1;
	for(int i = st + 1; i < end; i++){
        if(node[st] < node[i]){
            idx = i;
            break;
        }
    }
	Postorder(st+1, idx, node);
	Postorder(idx, end, node);
	cout << node[st] << '\n';
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int node[10002];
    int i = 0;
    int num;
    while(cin >> num){
        node[i++] = num;
    }
    Postorder(0, i, node);
}