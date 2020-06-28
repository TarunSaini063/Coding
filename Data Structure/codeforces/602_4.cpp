#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
bool cmp(const pair<int, ll> p1, const pair<int, ll> p2)
{
	if (p1.ss != p2.ss) return p1.ss > p2.ss;
	return p1.ff < p2.ff;
}
bool cmp1(const pair<int, ll> p1, const pair<int, ll> p2)
{
	return p1.ff < p2.ff;
}
int main(void)
{
	FIO
	int n, m, p;
	ll q;
	cin >> n;
	vector<pair<int, ll>> v, arr;
	for (int i = 1; i <= n; i++)
	{
		cin >> q;
		v.pb(mk(i, q));
	}
	sort(all(v), cmp);
	cin >> m;
	while (m--)
	{
		cin >> p >> q;
		for (int i = 0; i < p; i++)
		{
			arr.pb(v[i]);
		}
		sort(all(arr), cmp1);
		// for (auto i : arr) cout << i.ss << " ";
		// cout << "\n";
		cout << arr[q - 1].ss << '\n';
		arr.clear();
	}
	return 0;
}