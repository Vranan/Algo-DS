// Dijkstra's Algorithm

#include <iostream>
#include<limits>
#include<vector>
#include<utility>
#include<stack>

#define INF numeric_limits<int>::max()

void addEdge(vector <pair<int, int> > graph[], int u, int v, int wt) {
	graph[u].push_back(make_pair(v, wt));
}

void printGraph(vector <pair<int, int> > graph[],int V) {
	for (int i = 0; i < V; i++) {
		cout << "vertex: " << i;
		for (auto it = graph[i].begin(); it != graph[i].end(); it++) {
			int e = it->first;
			int w = it->second;
			cout << " ----(" << w << ")---->" << e;
		}
		cout << endl;
	}
}

void dijkstra(vector <pair<int, int> > graph, int n) {
	vector<int> dV[n];
	vector<int> pV[n];
	for (int i = 0; i < n; i++)
		dV.push_back(INF);
		pV.push_back(NULL);
	}
	dV[0] = 0;
	stack <vector <pair<int, int> >> s;
	s.push(graph[0]);
	while (!s.empty()) {
		vector<pair>
		s.pop();
	}
	
	
	
	
	
}

int main() {
 
}