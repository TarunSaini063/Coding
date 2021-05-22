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
	int n;
	cin >> n;
	vector<ll> arr(n), gcd(n);
	for (auto &i : arr) cin >> i;
	ll gd = 0;
	gcd[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		gcd[i] = __gcd(arr[i], gcd[i + 1]);
	}
	for (int i = 0; i < n - 1; i++)
	{
		gd = __gcd(gd, arr[i] * gcd[i + 1] / __gcd(arr[i], gcd[i + 1]));
	}
	cout << gd << "\n";
	return 0;
}