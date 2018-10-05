// Graph with Weight

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void addEdge(vector<pair<int, int> > graph[], int u, int v, int wt) {
	graph[u].push_back(make_pair(v, wt));
	//graph[v].push_back(make_pair(u, wt));
}

void printGraph(vector<pair<int, int> > graph[], int V) {
	for (int i = 0; i < V; i++) {
		cout << "vertex: " << i;
		for (auto it = graph[i].begin(); it != graph[i].end(); it++) {
			int e = it->first;
			int w = it->second;
			cout << " ----" << w << "---->" << e;
		}
		cout << endl;
	}
}


int main() {
	int V = 5;
	vector<pair<int, int> > graph[V];
	addEdge(graph, 0, 1, 5);
	addEdge(graph, 1, 4, 7);
	addEdge(graph, 2, 0, 6);
	addEdge(graph, 3, 0, 10);
	addEdge(graph, 4, 2, 8);
	addEdge(graph, 4, 3, 9);
	printGraph(graph, V);
	return 0;
}

