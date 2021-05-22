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
		int n;
		cin >> n;
		int arr[n];
		for (auto &i : arr) cin >> i;
		int cnt = 0;
		for (auto i : arr) {
			if (i == 1) cnt++;
			else break;
		}
		if (cnt == n) {
			if (n & 1) cout << "First\n";
			else cout << "Second\n";
		}
		else {
			if (cnt & 1)cout << "Second\n";
			else cout << "First\n";
		}
	}
	return 0;
}