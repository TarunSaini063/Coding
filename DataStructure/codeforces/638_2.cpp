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
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt","r",stdin);
// 	freopen("output1.txt","w",stdout);
// #endif
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for (auto &j : arr) cin >> j;
		map<int, int> mp;
		// int freq[n + 1] = {0};
		int fl = 1;
		set<int> s, s1;
		for (auto i : arr) s.insert(i);
		if ((int)s.size() > k)
		{
			cout << -1 << "\n";
			continue;
		}
		while ((int)s.size() != k && fl <= n)
		{
			if (s.find(fl) == s.end()) s.insert(fl);
			fl++;
		}
		vector<int> ans;
		int p = -1;
		// for (auto it : s) ans.pb(s);
		// for (int i = 0; i < k; i++) s1.pb(arr[i]);
		for (int i = 0; i < k; i++)
		{
			mp[arr[i]]++;
			if (mp[arr[i]] > 1)
			{
				for (auto it : s)
				{
					if (mp.find(it) == mp.end()) ans.pb(it);
				}
				p = i;
				break;
			}
			ans.pb(arr[i]);
			p = i + 1;

		}
		int z = 0;
		// cout << "p= " << p << '\n';
		for (int i = p; i < n; i++)
		{

			if (arr[i] == ans[z])
			{

				// cout << ans[z] << " " << z << " " << arr[i] << " " << i << " if\n";
				ans.pb(arr[i]);
			}
			else
			{
				// cout << ans[z] << " " << z << " " << arr[i] << " " << i << " ese \n";
				ans.pb(ans[z]);
				i--;
			}
			// cout << "\n" << ans.back() << "\n";
			z++;

		}
		cout << ans.size() << "\n";
		for (auto i : ans) cout << i << " ";
		cout << "\n";
	}
	return 0;
}