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
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n;
		int n1 = 2 * n;
		map<int, vector<pair<int, int>>> mp;
		for (int i = 1; i <= n1; i++)
		{
			cin >> x;
			mp[x % 2].pb(mk(x, i));
		}
		vector<pair<int, int>> even = mp[0];
		vector<pair<int, int>> odd = mp[1];
		int cnt = 0;
		// for (auto i : even) cout << i.ff << " " << i.ss << "\n";
		// for (auto i : odd) cout << i.ff << " " << i.ss << "\n";

		for (int j = 0; j < (int)even.size() - 1; j++)
		{
			cout << even[j].ss << " " << even[j + 1].ss << '\n';
			j ++;
			cnt++;
			if (cnt == n - 1) break;
		}
		for (int j = 0; j < (int)odd.size() - 1; j++)
		{
			if (cnt == n - 1) break;
			cout << odd[j].ss << " " << odd[j + 1].ss << '\n';
			j ++;
			cnt++;

		}
		// cout << "end\n";
	}
	return 0;
}