// Dijikstra Problem

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector < pii > vii;
#define INF  0x3f3f3f
vi D;   
vii *G;

void dijikstra(int source, int N) {
	D.assign(N, INF);
	D[source] = 0;
	set< pii > Q;
	set< pii >::iterator it;
	Q.insert({0,source});
	while(!Q.empty()) {
		auto top = Q.begin();
		int u = top->second;
		Q.erase(top);
		for (auto next: G[u]) {
			int v = next.first, w = next.second;
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