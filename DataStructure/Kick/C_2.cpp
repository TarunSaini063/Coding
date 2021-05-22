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
vector<int> arr[26];
string s[30];
int vis[26], act[26];
int m, n;
string ans;
int status;
void dfs(int id)
{
	vis[id] = 1;
	act[id] = 1;
	for (auto j : arr[id])
	{
		if (j != id && act[j])
		{
			status = 1;
		}
		else
		{
			if (!vis[j]) dfs(j);
		}
	}
	ans += char(id + 'A');
	act[id] = 0;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		cin >> n >> m;
		set<char> st;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			for (auto j : s[i]) st.insert(j);
			if (i)
			{
				for (int j = 0; j < m; j++)
				{
					arr[s[i - 1][j] - 'A'].pb(s[i][j] - 'A');
				}
			}
		}
		ans = "";
		status = 0;
		memset(vis, 0, sizeof(vis));
		memset(act, 0, sizeof(act));
		for (auto i : st)
		{
			if (!vis[i - 'A'])
			{
				dfs(i - 'A');
			}
		}
		if (status) cout << -1 << '\n';
		else cout << ans << "\n";
		for (int i = 0; i < 26; i++) arr[i].clear();


	}
	return 0;
}