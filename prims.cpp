#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > G[100005];
bool visited[100005];
int mst;

int main(){
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}

	priority_queue<pair<int, int> > q;
	q.push({0,1});
	
	while (!q.empty()){
		int a = q.top().second, weight = q.top().first;
		q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		mst -= weight;
		for (auto u : G[a]){
			int b = u.first, w = u.second;
			q.push({-w, b});
		}
	}
	
	cout << "MST: " << mst << '\n';
}
