#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr auto inf = int{ 987654321 };

using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using qi = queue<int>;

void solve(int n, const vvi& adj, int k, int x) {
	auto d = vi(n, inf);
	d[x - 1] = 0;

	auto q = qi{};
	q.push(x);

	while (!q.empty()) {
		auto y = q.front();
		q.pop();

		for (const auto& z : adj[y - 1]) {
			const auto& newDist = d[y - 1] + 1;
			if (newDist < d[z - 1]) {
				d[z - 1] = newDist;
				q.push(z);
			}
		}
	}

	auto ans = vi{};
	for (auto i = 0; i < n; ++i) {
		if (k == d[i]) {
			ans.push_back(i + 1);
		}
	}

	if (0 == ans.size()) {
		cout << -1;
		return;
	}

	sort(ans.begin(), ans.end());
	for (const auto& y : ans) {
		cout << y << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, k, x;
	cin >> n >> m >> k >> x;

	auto adj = vvi(n, vi{});
	for (auto j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].push_back(b);
	}

	solve(n, adj, k, x);

	return 0;
}