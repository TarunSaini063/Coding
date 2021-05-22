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
		for (int &i : arr) cin >> i;
		vector<int> tmp;
		int i = 0, j = n - 1;
		while (i < n && arr[i] == 0) i++;
		while (j >= i && arr[j] == 0)j--;
		while (i <= j) {
			int k = i + 1;
			while (arr[i] == 1 && k <= j && arr[k] == arr[i]) k++;
			int cnt = 0;
			while (k <= j && arr[k] == 0)k++, cnt++;
			if (cnt) tmp.pb(cnt);
			i = k;
		}
		int ans = 0;
		for (int i : tmp) ans += i;
		cout << ans << "\n";
	}
	return 0;
}