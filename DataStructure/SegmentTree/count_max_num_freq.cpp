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
vector<pair<int, int>> tree;
vector<int> arr;
pair<int, int> combine(pair<int, int>p1, pair<int, int>p2) {
	if (p1.ff > p2.ff) return p1;
	if (p1.ff < p2.ff) return p2;
	return mk(p1.ff, p1.ss + p2.ss);
}

void build(int l, int r, int node) {
	if (l == r) {
		tree[node] = mk(arr[l], 1);
		return;
	}
	int mid = l + (r - l) / 2;
	build(l, mid, 2 * node + 1);
	build(mid + 1, r, 2 * node + 2);
	tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
}

pair<int, int> query(int l, int r, int s, int e, int node) {
	if (s > e || s > r || e < l) return mk(INT_MIN, 0);
	if (s == l && e == r) {
		return tree[node];
	}
	int mid = l + (r - l) / 2;
	pair<int, int> left, right;
	left = query(l, mid, s, min(e, mid), 2 * node + 1);
	right = query(mid + 1, r, max(mid + 1, s), e, 2 * node + 2);
	return combine(left, right);
}

void update(int l, int r, int node, int id, int val) {
	if (l == r) {
		tree[node] = mk(val, 1);
		return;
	}
	int mid = l + (r - l) / 2;
	if (id <= mid) update(l, mid, 2 * node + 1, id, val);
	else update(mid + 1, r, 2 * node + 2, id, val);
	tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
}

int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, q, c, s, e;
		cin >> n;
		arr.assign(n, 0);
		tree.assign(4 * n, mk(INT_MIN, 0));
		for (int &i : arr)cin >> i;
		build(0, n - 1, 0);
		cin >> q;
		while (q--) {
			cin >> c >> s >> e;
			if (c) {
				auto p = query(0, n - 1, s, e, 0);
				cout << p.ff << " " << p.ss << "\n";
			}
			else {
				// assert(s < n);
				update(0, n - 1, 0, s, e);
				arr[s] = e;
			}
		}
	}
	return 0;
}