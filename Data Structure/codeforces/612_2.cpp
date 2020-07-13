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
string get(string a, string b) {
	string res = "";
	for (int i = 0; i < sz(a); i++) {
		if (a[i] == b[i]) res += a[i];
		else res += 'S' + 'T' + 'E' - a[i] - b[i];
	}
	return res;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		map<string, int> mp;
		vector<string> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			mp[arr[i]]++;
		}
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				string res = get(arr[i], arr[j]);
				ans += mp[res];
			}
		}
		cout << ans / 3 << "\n";
	}
	return 0;
}