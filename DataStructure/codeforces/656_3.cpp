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
		int arr[n], lmx[n];
		for (auto &i : arr) cin >> i;
		lmx[n - 1] = arr[n - 1];
		priority_queue<int> q;
		q.push(arr[0]);
		for (int i = n - 2; i >= 0; i--) {
			lmx[i] = max(arr[i], lmx[i + 1]);
		}
		int st = 0;
		for (int i = 1; i < n - 1; i++) {
			if (lmx[i + 1] > arr[i] && q.top() > arr[i]) {
				st = i;
				q = priority_queue<int>();
				q.push(arr[i]);
			}
			else q.push(arr[i]);
		}
		cout << st << '\n';

	}
	return 0;
}