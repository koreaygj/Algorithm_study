#include <bits/stdc++.h>
using namespace std;
vector<int> trunk[501];
int bfs(int n, int m){
    bool visited[501] = {false,};
    int parent[501] = {0};
    queue<int> pu;
	int answer=0;
	bool istree=true;
	for(int i = 1; i <= n;i ++){
		if(!visited[i]){
			istree=true;
			visited[i]=true;
			pu.push(i);
		    while(!pu.empty()){
			    int now=pu.front();
			    pu.pop();
			    for(int j=0;j<trunk[now].size();j++){
                    int next = trunk[now][j];
			    	if(visited[next] && parent[now]!=next){
			    		istree=false;
			    	}
			    	else if(visited[next]){
			    		continue;
			    	}
			    	else{
			    		visited[next]=true;
			    		parent[next]=now;
			    		pu.push(next);
			    	}
			    }
			}
			if(istree) answer++;
		}
	}
	return answer;
}

int main(){
    int cs = 1;
    int n, m, cnt;
	while(1){
		cin >> n >> m;
		if(n==0 && m==0)
            break;
		for(int i=1;i<=n;i++)
			trunk[i].clear();
		for(int i=0;i<m;i++){
			int a, b;
			cin >> a >> b;
			trunk[a].push_back(b);
			trunk[b].push_back(a);
		}
		cnt = bfs(n, m);
        cout << "Case " << cs++ << ": ";
        if(cnt == 0)
            cout << "No trees.\n";
        else if(cnt == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << cnt << " trees.\n";
	}
}