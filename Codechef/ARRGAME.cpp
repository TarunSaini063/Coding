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
		for (int &I : arr) cin >> I;
		int ans = 0, i = 0;
		vector<int> len;
		while (i < n) {
			if (arr[i] == 0) {
				int j = i + 1;
				while (j < n && arr[j] == 0)j++;
				len.pb(j - i);
				i = j;
			}
			else i++;
		}
		sort(all(len), greater<int>());
		if (sz(len) <= 1) {
			if (sz(len) != 0) ans = len[0];
			if (ans % 2 == 0) cout << "No\n";
			else cout << "Yes\n";
		}
		else if ((len[0] + 1) / 2 > len[1] && len[0] % 2 == 1) cout << "Yes\n";
		else cout << "No\n";

	}
	return 0;
}