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
vector<int> tree, arr;
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
void update(int l, int r, int node, int id, int val) {
	if (l == r) {
		tree[node] = val;
		return;
	}
	int mid = l + (r - l) / 2;
	if (id <= mid) update(l, mid, 2 * node + 1, id, val);
	else update(mid + 1, r, 2 * node + 2, id, val);
	tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

int query(int l, int r, int s, int e, int node)
{
	if (s > e || s > r || e < l) return 0;
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
		arr.assign(n, 0);
		for (int &i : arr) cin >> i;
		build(0, n - 1, 0);
		cin >> q;
		while (q--) {
			cin >> c >> s >> e;
			if (c) {
				cout << query(0, n - 1, s, e, 0) << "\n";
			}
			else {
				update(0, n - 1, 0, s, e);
			}
		}
	}
	return 0;
}