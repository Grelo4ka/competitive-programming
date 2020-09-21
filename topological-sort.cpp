#include <bits/stdc++.h>
using namespace std;

vector<int> G[100005];
short int visited[100005];
vector<int> topo;

void dfs(int a){
	visited[a] = 1;
	
	for (auto u : G[a]){
		if (visited[u] == 1) cout << "Cycle detected!\n";
		if (visited[u] == 0) dfs(u);
	}
	
	visited[a] = 2;
	topo.push_back(a);
}

int main(){
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	
	for (int i = 1; i <= n; i++) 
		if (!visited[i]) dfs(i);

	for (auto u : topo) cout << u << ' ';
}
