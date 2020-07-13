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
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, k1, k2, x;
		cin >> n >> k1 >> k2;
		int arr[n + 1];
		for (int i = 0; i < k1; i++) {
			cin >> x;
			arr[x] = 1;
		}
		for (int i = 0; i < k2; i++) {
			cin >> x;
			arr[x] = 2;
		}
		if (arr[n] == 1)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}