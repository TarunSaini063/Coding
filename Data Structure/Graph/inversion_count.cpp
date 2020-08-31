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
int solve(vector<int> &arr, int l, int mid, int r) {
	int cnt = 0;
	int tmp[r - l + 1];
	int i = l, j = mid + 1, k = 0;
	// cout << "l= " << l << " mid= " << mid << " r=" << r << '\n';
	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
		}
		else {
			// cout << mid << " " << i << '\n';
			cnt += mid - i + 1;
			tmp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		tmp[k++] = arr[i++];
	}
	while (j <= r) {
		tmp[k++] = arr[j++];
	}
	k = 0;
	while (l <= r) {
		cout << tmp[k] << " ";
		arr[l++] = tmp[k++];
	}
	cout << "\n";
	return cnt;
}
int get(vector<int> &arr, int l, int r) {
	int inv = 0;
	if (l < r) {
		// cout << l << " " << r << '\n';
		int mid = (l + r) / 2;
		inv += get(arr, l, mid);
		inv += get(arr, mid + 1, r);
		inv += solve(arr, l, mid, r);
	}
	return inv;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int &i : arr) cin >> i;
		cout << get(arr, 0, n - 1) << '\n';
		// for (int i : arr) cout << i << " ";
		cout << "\n";
	}
	return 0;
}