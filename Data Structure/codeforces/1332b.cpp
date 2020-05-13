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
int gtmin(int x)
{
	int i = 2;
	for (i = 2; i * i <= x; i++)
		if (x % i == 0) break;
	return i;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, dif = 0; cin >> n;
		map<int, vector<int>> mp;
		set<int> s;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			mp[gtmin(x)].pb(i);
		}
		vector<int> ans(n);
		for (auto i : mp)
		{
			dif++;
			for (auto j : i.ss) ans[j] = dif;
		}
		cout << dif << "\n";
		for (auto i : ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}