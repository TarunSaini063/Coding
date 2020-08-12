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
int n;
vector<int> arr;
int solve(int sum)
{
	int i = 0, j = n - 1;
	int cnt = 0;
	while (i < j) {
		int sm = arr[i] + arr[j];
		if (sm == sum) {
			cnt++;
			i++, j--;
		}
		else if (sm > sum) {
			j--;
		}
		else i++;
	}
	return cnt;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		arr = vector<int>(n);
		for (int &i : arr) cin >> i;
		sort(all(arr));
		int mxsum = 2 * n, mx = 0;
		for (int i = 1; i <= mxsum + 1; i++) {
			mx = max(mx, solve(i));
		}
		cout << mx << '\n';
	}
	return 0;
}