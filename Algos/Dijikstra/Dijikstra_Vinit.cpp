// Dijikstra Problem

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector < pii > vii;
#define INF  0x3f3f3f
vector<int> D;   
vector<pair<int, int>> *G;

void dijikstra(int source, int N) {
	D.assign(N, INF);
	D[source] = 0;
	set<pair<int, int>> Q;
	set<pair<int, int>>::iterator it;
	Q.insert({0,source});
	while(!Q.empty()) {
		auto top = Q.begin();
		int u = top->second;     		// Gives the vertex from which the distance of the other neighbour vertices  distance is to be updated.
		Q.erase(top);
		for (auto next: G[u]) {
			int v = next.first;			// From the graph obtain the nieghbours of vertex u.
			int w = next.second;  		// Obtain the weight associated with the edge (u,v).
			if (D[v] > D[u]+w) {
				it = Q.find({D[v],v});
				Q.erase(it);
				D[v] = D[u]+w;
				Q.insert({D[v],v});
			}
		}
	}
}

int main() {

}
