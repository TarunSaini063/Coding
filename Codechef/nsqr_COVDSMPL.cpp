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
int mat[65][65];
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, p;
		cin >> n >> p;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mat[i][j] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << 1 << " " << i << ' ' << j << ' ' << i << ' ' << j << endl;;
				cout.flush();
				cin >> mat[i][j];
				if (mat[i][j] == -1) exit(0);
			}
		}
		cout << 2 << '\n';
		cout.flush();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) {
				cout << mat[i][j] << ' ';
				cout.flush();
			}
			cout << '\n';
		}
		cin >> p;
		if (p == -1) exit(0);
	}
	return 0;
}