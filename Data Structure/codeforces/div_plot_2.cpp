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
//#ifndef ONLINE_JUDGE
//	freopen("input1.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
//#endif
	FIO
	ld x;
	// xin >> x;
	// x = (181.7 - sqrt(181.7 * 181.7 - 5739.19 * 4 * 18.9 / 103.2)) / (2 * 18.9 / 103.2);
	// x = (-162.8 + sqrt(162.8 * 162.8 + 5815.19 * 4 * 9.45 / 103.2)) / (2 * 9.45 / 103.2);
	x = (180.59 - sqrt(180.59 * 180.598 - 5833.4 * 4 * 18.9 / 204.2)) / (2 * 18.9 / 204.2);
	cout << x << "\n";
	x = 32.83;
	ld y = x * 18.9 / 103.2; cout << y << "\n";
	cout << sqrt(x * x + y * y) << "\n";
	return 0;
}