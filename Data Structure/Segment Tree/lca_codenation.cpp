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
#define all(x) x.begin(),x.end()
vector<int>tree, height, first, nodes, visited, tim;
vector<vector<int>>arr;
const int mxn = 1e5 + 10;
int cnt = 0;
void dfs(int id, int h) {
	visited[id] = 1;
	nodes.pb(id);
	tim[id] = cnt++;
	height[id] = h;
	first[id] = sz(nodes);
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

vector<int> solve(vector<int> &A, vector<vector<int> > &B) {
	int n = A.size(), q, u, v, lca;
	arr.assign(mxn + 10, vector<int>());
	for (int i = 0; i < n; i++) {
		arr[A[i]].pb(i + 2);
		arr[i + 2].pb(A[i]);
	}
	tree.assign(4 * mxn + 10, 0);
	height.assign(mxn + 10, 0);
	first.assign(mxn + 10, 0);
	visited.assign(mxn + 10, 0);
	tim.assign(mxn + 10, 0);
	dfs(1, 1);
	build(0, sz(nodes) - 1, 0);
	q = B.size();
	vector<int> ans;
	int i = 0;
	while (i < q) {
		vector<pair<int, int>> tmp;
		tmp.pb(mk(tim[B[i][1]], B[i][1]));
		int j = i + 1;
		while (j < q && B[j][0] == B[i][0]) {
			tmp.pb(mk(tim[B[j][1]], B[j][1]));
			j++;
		}
		i = j;
		sort(all(tmp));
		// for (auto i : tmp) cout << i.ff << " " << i.ss << " " << height[i.ss] << "\n";
		// cout << '\n';
		u = first[ tmp[0].ss];
		v = first[ tmp.back().ss];
		if (u > v) swap(u, v);
		lca = query(0, sz(nodes) - 1, u - 1 , v - 1 , 0);
		int curr = height[ tmp[0].ss] - height[lca] + 1;
		// cout << lca << " " << curr << "\n";
		for (int i1 = 1; i1 < sz( tmp); i1++) {
			u = first[ tmp[i1 - 1].ss];
			v = first[ tmp[i1].ss];
			lca = query(0, sz(nodes) - 1, u - 1 , v - 1 , 0);
			curr += height[tmp[i1].ss] - height[lca];
			// cout << lca << " " << height[tmp[i1].ss] - height[lca] << "\n";
		}
		ans.pb(curr);
	}
	return ans;
}
int main(void) {
	int n, q;
	cin >> n;
	vector<int>A(n);
	for (int &i : A)cin >> i;
	cin >> q;
	vector<vector<int>> B(q);
	for (int i = 0; i < q; i++) {
		B[i] = vector<int>(2);
		cin >> B[i][0] >> B[i][1];
	}
	auto it = solve(A, B);
	for (int i : it) cout << i << " ";
	cout << "\n";
	return 0;
}