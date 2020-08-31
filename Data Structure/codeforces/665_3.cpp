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
		int n, fl = 0;
		cin >> n;
		vector<int> arr(n), brr;
		for (int &i : arr) cin >> i;
		brr = arr;
		sort(all(brr));
		int mn = brr[0];
		for (int i = 0; i < n; i++) {
			if (arr[i] != brr[i] && arr[i] % mn != 0) {
				fl = 1;
				break;
			}
		}
		if (fl) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}