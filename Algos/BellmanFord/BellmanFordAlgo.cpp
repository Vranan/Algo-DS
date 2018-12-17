#include<bits/stdc++.h>
using namespace std;


struct Edge {
	int src;
	int des;
	int wt;
};

struct Graph {
	int V;
	int E;
	struct Edge *edge;
};

void BellmanFord(struct Graph *graph, int source) {
	
	int V = graph->V;   // number of Vertices.
	int E = graph->E;	// number of Edges.
	
	vector<int> dist(V);
	for (int i = 0; i < N; i++)
		dist[i] = INT_MAX;	
	dist[source] = 0;
	
	// relaxing for each node |V| - 1 times.
	// This is not fixed in Dijikstra, since
	// we expect only positive weights for the edges in it.
	for (int i = 0; i < V-1; i++) {
		for (int e = 0; e < E; e++) {
			
			int src = graph->edge[e].src;
			int des = graph->edge[e].des;
			int wt = graph->edge[e].wt;
			
			if (dist[des] > dist[src] + wt) {
				dist[des] = dist[src] + wt;
			}
			
		}
	}
	
	
	for (int i = 0; i < E; i++) {
		int src = graph->edge[i].src;
		int des = graph->edge[i].des;
		int wt = graph->edge[i].weight;
		
		if (dist[des] > dist[src] + w) {
			cout << "Negative Cycle" << endl;
			break;
		}
	}
	
	
	
		
		
	}
	
}


int main() {

	return 0;
}

