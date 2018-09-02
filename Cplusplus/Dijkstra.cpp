#include <cstdio>
#include <queue>
#include <cstring>

bool *flag = nullptr;
int *mind = nullptr;
typedef std::pair<int, int> pii;
std::vector<pii> *graph;

int shorestPath(int V[], int U[], int W[], 
		int const &m, int const & s, int const & t) {

	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
	
	memset(mind, 127, sizeof(int) * m);
	memset(flag, 0, sizeof(bool) * m);
	for (int i = 0; i < m; ++i) {
		graph[U[i]].push_back(std::make_pair(V[i], W[i]));
		graph[V[i]].push_back(std::make_pair(U[i], W[i]));
	}

	mind[s] = 0;
	pq.push(std::make_pair(mind[s], s));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (!flag[u]) {
			flag[u] = true;
			for (auto const & it: graph[u]) {
				int v = it.first, w = it.second;
				if (w + mind[u] >= mind[v]) {
					continue;
				}
				mind[v] = w + mind[u];
				pq.push(std::make_pair(mind[v], v));
			}
		}
	}
	return mind[t];
}

int main() {
	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	auto v = new int[m];
	auto u = new int[m];
	auto w = new int[m];
	mind = new int[m];
	flag = new bool[m];
	graph = new std::vector<pii>[n+1];

	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &v[i], &u[i], &w[i]);
	}
	auto ans = shorestPath(v, u, w, m, s, t);
	printf("%d\n", ans);
	delete[]v; delete[]u; delete[]w; delete[] graph;
	return 0;
}

