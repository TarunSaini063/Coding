#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
int dis[2010];
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, x, y;
		cin >> n >> x >> y;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (i <= x && j >= y) dis[x - i + j - y + 1]++;
				else if (i <= x && j <= x) dis[j - i]++;
				else if (i >= y && j >= y) dis[j - i]++;
				else if (i > x && j < y) dis[min(j - i, y - x + 1 - (j - i))]++;
				else if (i > x && j >= y) dis[min(j - i, j - y - x + i + 1)]++;
				else if (i <= x && j < y) dis[min(j - i, y  + 1 - j + x  - i)]++;
			}
		}
		for (int i = 1; i < n; i++) cout << dis[i] << "\n";
	}
	return 0;
}