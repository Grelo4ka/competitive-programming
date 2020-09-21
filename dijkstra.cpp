#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > G[100005];
bool visited[100005];
int dist[100005];

int main(){
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}

	for (int i = 2; i <= n; i++) dist[i] = INT_MAX;
	
	priority_queue <pair<int, int> > q;
	q.push({0,1});
	
	while (!q.empty()){
		int a = q.top().second;
		q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto u : G[a]){
			int b = u.first, w = u.second;
			if (dist[a] + w < dist[b]){
				dist[b] = dist[a] + w;
				q.push({-dist[b],b});
			}
		}
	}

	for (int i = 1; i <= n; i++) cout << "The distance to node " << i << " is " << dist[i] << '\n';
}
