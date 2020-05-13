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
int freq[200005][26];
int solve(int u, int v)
{
	int res = 0;
	int mx = 0;
	for (int i = 0; i < 26; i++)
	{
		res += freq[u][i] + freq[v][i];
		mx = max(mx, freq[u][i] + freq[v][i]);
	}
	return res - mx;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, ans = 0;
		cin >> n >> k;
		string s;
		cin >> s;
		for (int i = 0; i < k; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				freq[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			freq[i % k][s[i] - 'a']++;
		}
		for (int i = 0; i < k; i++)
		{
			ans += solve(i, k - i - 1);
		}
		cout << ans / 2 << "\n";
	}
	return 0;
}