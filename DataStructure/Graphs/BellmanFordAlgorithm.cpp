// Bellman Ford Algorithm.

#include <iostream>
#include<vector>
#include<utility>
#include<limits>
using namespace std;

void addEdge(vector <pair<int, int> > graph[], int u, int v, int wt) {
	graph[u].push_back(make_pair(v, wt));
}

void printGraph(vector <pair<int, int> > graph[], int V) {
	for (int i = 0; i < V; i++) {
		cout << "vertex:  " << i;
		for (auto it = graph[i].begin(); it != graph[i].end(); it++) {
			int e = it->first;
			int w = it->second;
			cout << " ----(" << w << ")---->" << e;
		}
		cout << endl;
	}
}

void bellmanFord(vector<pair<int, int> > graph[], int V){
	vector<int> dV[V];
	vector<int> pV[V];
	for (int i = 0; i < V; i++) {
		dV.push_back(numeric_limits<int>::max());    // Setting the value to Infinity
		pV.push_back(NULL);
	}
	dV[0] = 0;
	for (int i = 1; i < V; i++) {
		
	}
	
}

int main() {
	int V = 5;
	vector<pair<int, int> > graph[V];
	addEdge(graph, 0, 1, 4);
	addEdge(graph, 0, 2, 2);
	addEdge(graph, 1, 2, 3);
	addEdge(graph, 1, 3, 2);
	addEdge(graph, 1, 4, 3);
	addEdge(graph, 2, 1, 1);
	addEdge(graph, 2, 3, 4);
	addEdge(graph, 2, 4, 5);
	addEdge(graph, 4, 3, -5);
	printGraph(graph, V);
	return 0;
}
