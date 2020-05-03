// #include <bits/stdc++.h>
// using namespace std;
// #define ld double
// #define ll long long
// #define pb emplace_back
// #define mk make_pair
// #define mod 1000000007
// #define ff first
// #define ss second
// #define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define all(x) x.begin(),x.end()
// ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
// ll invmod(ll a) {return power(a, mod - 2);}
// int main(void)
// {
// // #ifndef ONLINE_JUDGE
// // 	freopen("input1.txt","r",stdin);
// // 	freopen("output1.txt","w",stdout);
// // #endif
// 	FIO
// 	int t;
// 	cin >> t;
// 	while (t--)
// 	{
// 		int n, k;
// 		cin >> n >> k;
// 		string s;
// 		cin >> s;
// 		sort(all(s));
// 		if (s[0] != s[k - 1]) {cout << s[k - 1];}
// 		else
// 		{
// 			cout << s[0];
// 			if (s[k] == s[n - 1])
// 			{
// 				int dif = n - k;
// 				for (int i = 0; i < (dif + k - 1) / k; i++) cout << s[k];
// 			}
// 			else
// 			{
// 				for (int i = k ; i < n; i++) cout << s[i];
// 			}
// 		}
// 		cout << "\n";
// 	}
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> vis;
int n, m;
int x[] = {0, 0, 1, -1};
int y[] = {1, -1, 0, 0};
int fun(vector<string>adj, int i, int j)
{
	vis[i][j] = 0;
	if (i == n - 1 || j == m - 1)
	{

		return 0;
	}
	int mx = 1;
	for (int k = 0; k < 4; k++)
	{
		int nx = i + x[k];
		int ny = j + y[k];
		if (nx < n && nx >= 0 && ny < m && ny >= 0 && adj[nx][ny] != '*')
		{
			if (vis[nx][ny] == -1)
			{
				vis[nx][ny] = 0;
				if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) vis[nx][ny] = 0;
				else mx = min(mx, fun(adj, nx, ny));
			}
		}
	}
	vis[i][j] = mx;
	return mx;
}
int main(void) {
	cin >> n >> m;
	vector<string> adj(n);
	for (auto &i : adj ) cin >> i;
	int ans = 0;
	vis = vector<vector<int>>(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (adj[i][j] == '.')
			{
				if (vis[i][j] == -1)	 fun(adj, i, j);
				else ans += vis[i][j];
				for (auto k : vis)
				{
					for (auto p : k) cout << p << " ";
					cout << "\n";
				}
				cout << "\n";
			}


		}
	}
	cout << ans << "\n";
}
