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
		int n, m;
		cin >> n >> m;
		int arr[n][m], r = n, c = m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) cin >> arr[i][j];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1) {
					r--;
					break;
				}
			}
		}
		for (int j = 0; j < m; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (arr[i][j] == 1) {
					c--;
					break;
				}
			}
		}
		r = min(r, c);
		if (r % 2 == 0)cout << "Vivek\n";
		else cout << "Ashish\n";
	}
	return 0;
}