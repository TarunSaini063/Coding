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
	while (t--) {
		int n, k;
		cin >> n >> k;
		int arr[n][n];
		memset(arr, 0, sizeof(arr));
		int cnt = 0;
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++)
			{
				if (cnt < k)
				{
					cnt++;
					arr[i][(i + j) % n] = 1;
				}
			}
		int f = 0;
		if (k % n != 0)
		{
			f = 2;
		}
		cout << f << "\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << arr[i][j];
			cout << "\n";
		}
	}
	return 0;
}