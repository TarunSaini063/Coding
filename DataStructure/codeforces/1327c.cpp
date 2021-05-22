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
	int n, m;
	cin >> n >> m;
	cout << n + m + n*m - 2 << endl;
	for (int i = 2; i <= n; ++i)cout << 'U';
	for (int i = 2; i <= m; ++i)cout << 'L';
	for (int i = 1; i <= m; ++i, cout << 'R')
		for (int j = 2; j <= n; ++j)if (i % 2)
						cout << 'D'; else cout << 'U';
	return 0;
}