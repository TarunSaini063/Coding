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
	int t = 1;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v, arr(n + 1);
		set<int> s;
		for (int i = 1; i <= n; i++)s.insert(i);
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] == 0) v.pb(i);
			else s.erase(arr[i]);
		}
		sort(all(v), greater<int>());
		vector<int> eq;
		for (int i = 0; i < sz(v); i++) {
			arr[v[i]] = *s.begin();
			if (v[i] == arr[v[i]]) {
				eq.pb(i);
			}
			s.erase(s.begin());
		}
		if (sz(eq)) {
			for (auto num : eq) {
				int j = (num + 1) % sz(v);
				swap(arr[v[num]], arr[v[j]]);
			}
		}
		for (int i = 1; i <= n; i++)cout << arr[i] << " ";
		cout << "\n";

	}
	return 0;
}