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
		int m, n, a, b;
		cin >> n >> m >> a >> b;
		if (n * a != m * b)
		{
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		int c = 0;
		vector< vector<int> > v(n, vector<int> (m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < a; j++)
			{
				v[i][c % m] = 1;
				c++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << v[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}