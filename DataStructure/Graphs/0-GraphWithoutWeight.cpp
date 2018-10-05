// Creating A Graph
// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void printGraph(vector<int> graph[], int V) {
	for (int i = 0; i < V; ++i) {
		cout << "Vertex: " << i;
		for (auto x : graph[i]) 
			cout << " --> " << x;
		cout << endl;
	}
}

int main() {
	int V = 5;
	vector<int> graph[V];
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 4);
	printGraph(graph, V);
	return 0;
}