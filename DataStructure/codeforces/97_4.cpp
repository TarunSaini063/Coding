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
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		int ans = 0, curr = 1, i = 1;
		vector<int> v;
		while (i < n) {
			int j = i, cnt = 1;
			while (j < n && arr[j] < arr[j + 1])j++, cnt++;
			v.pb(cnt);
			i = j + 1;
		}
		i = 0;
		n = sz(v);
		while (i < n) {
			int prev = 0;
			while (i < n && curr--) {
				prev += v[i++];
			}
			curr = prev;
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}