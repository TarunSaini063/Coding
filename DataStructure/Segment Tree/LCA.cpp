#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
vector<int>tree, height, last, nodes, visited;
vector<vector<int>>arr;

void dfs(int id, int h) {
	visited[id] = 1;
	nodes.pb(id);
	height[id] = h;
	last[id] = sz(nodes);
	for (int i : arr[id]) {
		if (visited[i] == 0) {
			dfs(i, h + 1);
			nodes.pb(id);
		}
	}
}

void build(int l, int r, int idx) {
	cout.flush();
	if (l == r) {
		tree[idx] = nodes[l];
		return;
	}
	int mid = l + (r - l) / 2;
	build(l, mid, 2 * idx + 1);
	build(mid + 1, r, 2 * idx + 2);
	int l1 = l, r1 = r;
	l = tree[2 * idx + 1], r = tree[2 * idx + 2];
	tree[idx] = height[l] < height[r] ? l : r;
}

int query(int l, int r, int s, int e, int idx) {
	if (l > e || r < s) return -1;
	if (l == s && r == e) {
		return tree[idx];
	}
	int mid = l + (r - l) / 2;
	int left = query(l, mid, s, min(e, mid), 2 * idx + 1);
	int right = query(mid + 1, r, max(mid + 1, s), e, 2 * idx + 2);
	if (left == -1) return right;
	if (right == -1) return left;
	return height[left] < height[right] ? left : right;

}

int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, u, v, q;
		cin >> n;
		arr.assign(n + 1, vector<int>());
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			arr[u].pb(v);
			arr[v].pb(u);
		}
		tree.resize(8 * n + 10);
		height.resize(n + 1);
		last.resize(n + 1);
		visited.assign(n + 1, 0);
		dfs(1, 1);
		// for (auto i : height) cout << i << " ";
		// cout << "\n";
		// for (int i : nodes) cout << i << " ";
		// cout << "\n";
		// for (int i : last) cout << i << " ";
		// cout << "\n\n";
		build(0, 2 * n - 2, 0);
		cin	>> q;
		while (q--) {
			cin >> u >> v;
			u = last[u];
			v = last[v];
			if (u > v) swap(u, v);
			cout << query(0, 2 * n - 2, u - 1 , v - 1 , 0) << "\n";
		}
	}
	return 0;
}