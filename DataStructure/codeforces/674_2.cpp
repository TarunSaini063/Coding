#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
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
		int n, m, fl = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int arr[2][2];
			cin >> arr[0][0] >> arr[0][1] >> arr[1][0] >> arr[1][1];
			if (arr[1][0] == arr[0][1]) fl = 1;
		}
		if (m % 2 || fl == 0) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}