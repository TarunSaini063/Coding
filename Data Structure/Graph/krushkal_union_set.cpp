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
vector<int> id, size;
int root(int x)
{
	return x == id[x] ? x : id[x] = root(id[x]);
}

void uni(int x, int y) {
	x = root(x);
	y = root(y);
	if (x != y) {
		if (size[x] > size[y]) swap(x, y);
		id[y] = id[x];
		size[x] += size[y];
	}
}
struct edge {
	int u, v, w;
	bool operator<(edge const& other) {
		return w < other.w;
	}
};
int main(void)
{
	FIO
	int n, cost = 0;
	cin >> n;
	id.resize(n + 1);
	size.assign(n + 1, 0);
	for (int i = 0; i <= n; i++) id[i] = i;
	vector<edge> arr(n), res;
	for (int i = 0; i < n - 1; i++) {
		cin >> arr[i].w >> arr[i].v >> arr[i].u;
	}
	sort(all(arr));
	for (auto i : arr) {
		if (root(i.u) != root(i.v)) {
			cost += i.w;
			uni(i.u, i.v);
			res.pb(i);
		}
	}
	cout << "cost= " << cost << "\n";
	for (auto i : res)cout << i.u << " " << i.v << "\n";
	return 0;
}