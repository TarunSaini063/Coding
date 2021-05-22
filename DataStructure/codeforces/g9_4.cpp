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
		for (auto &i : arr)cin >> i;
		int freq[n + 1];
		vector<int> ans;
		while (n) {
			for (int i = 0; i <= n; i++) freq[i] = 0;
			for (int i = 0; i < n; i++)freq[arr[i]]++;
			int x = 0;
			while (freq[x])x++;
			if (x == n)
			{	ans.pb(n - 1);
				arr[n - 1] = x;
				n--;
			}
			else {
				ans.pb(x);
				arr[x] = x;
			}
		}
		// reverse(all(ans));
		cout << sz(ans) << "\n";
		for (auto i : ans)cout << i + 1 << " ";
		cout << "\n";
	}
	return 0;
}