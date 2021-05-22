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
bool notprime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return true;
	}
	return false;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n == 1) {
			cout << "FastestFinger\n";
		}
		else if (n % 2 == 1 || n == 2)cout << "Ashishgup\n";
		else {
			int y = 1;
			while (n % 2 == 0)
			{
				n /= 2;
				y *= 2;
			}
			if (n == 1 ) cout << "FastestFinger\n";
			else {
				if (y == 2)
				{
					if (notprime(n)) cout << "Ashishgup\n";
					else cout << "FastestFinger\n";
				}
				else
				{
					cout << "Ashishgup\n";
				}
			}
		}
	}
	return 0;
}