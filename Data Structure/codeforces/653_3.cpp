#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int arr[n];
		for (int i = 0; i < n; i++) {
			arr[i] = s[i] == ')' ? -1 : 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0)arr[i] += arr[i - 1];
			if (arr[i] < 0) {
				cnt++;
				arr[i] = 0;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}