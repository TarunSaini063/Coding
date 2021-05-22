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
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int &i : arr)cin >> i;
		sort(arr, arr + n);
		vector<int> ans(n);
		int x = n / 2, y = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) ans[i] = arr[x++];
			else ans[i] = arr[y++];
		}
		int k = 0;
		for (int i = 1; i < n - 1; i++) {
			if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) k++;
		}
		cout << k << "\n";
		for (int k : ans)cout << k << " ";
	}
	return 0;
}