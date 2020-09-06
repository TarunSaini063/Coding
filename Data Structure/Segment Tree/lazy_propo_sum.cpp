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
vector<int> tree, lazy, arr;
void push(int l, int r, int node) {
	if (lazy[node]) {
		tree[node] += (r - l + 1) * lazy[node];
		if (l != r) {
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void build(int l, int r, int node) {
	if (l == r) {
		tree[node] = arr[l];
		return;
	}
	int mid = l + (r - l) / 2;
	build(l, mid, 2 * node + 1);
	build(mid + 1, r, 2 * node + 2);
	tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}
void update(int l, int r, int node, int s, int e, int val) {
	push(l, r, node);
	if (s > e || s > r || e < l) return ;
	if (l == s && e == r) {
		lazy[node] += val;
		push(l, r, node);
		return;
	}
	int mid = l + (r - l) / 2;
	update(l, mid, 2 * node + 1, s, min(e, mid), val);
	update(mid + 1, r, 2 * node + 2, max(mid + 1, s), e, val);
}

int query(int l, int r, int s, int e, int node)
{
	if (s > e || s > r || e < l) return 0;
	push(l, r, node);
	if (e == l && s == r) return tree[node];
	int mid = l + (r - l) / 2;
	return query(l, mid, s, min(e, mid), 2 * node + 1) + query(mid + 1, r, max(mid + 1, s), e, 2 * node + 2);

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
		tree.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
		arr.assign(n, 0);
		for (int &i : arr) cin >> i;
		build(0, n - 1, 0);
		cin >> q;
		while (q--) {
			cin >> c ;
			if (c) {
				cin >> s >> e;
				cout << query(0, n - 1, s, e, 0) << "\n";
			}
			else {
				cin >> c >> s >> e;
				update(0, n - 1, 0, c, s, e);
			}
		}
		// cout << "\n\n";
		// cout << tree[7] << " " << lazy[7] << "\n";
		// cout << tree[8] << " " << lazy[8] << "\n";
		// cout << tree[4] << " " << lazy[4] << "\n";
		// cout << tree[3] << " " << lazy[3] << "\n";
		// cout << tree[6] << " " << lazy[6] << "\n";
		// cout << query(0, n - 1, 0, 2, 0) << "\n";
	}
	return 0;
}