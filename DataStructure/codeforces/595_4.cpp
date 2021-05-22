#include<bits/stdc++.h>
using namespace std;
#define  ll long long

string ternary(ll n) {
	if (n == 0) return "0";
	string s = "";
	while (n) {
		s += to_string((n % 3));
		n /= 3;
	}
	reverse(s.begin(), s.end());
	return s;
}
void print(string s) {
	// cout << s << "\n";
	ll ans = 0, pw = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		ans += (s[i] - '0') * pw;
		pw *= 3;
	}
	cout << ans << '\n';
}
int main(void) {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		string s = ternary(n);
		// cout << s << "\n";
		int fl = -2;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '2') {
				fl = i - 1;
				while (i < s.size()) s[i++] = '0';
				break;
			}
		}
		if (fl == -2) {
			print(s);
			continue;
		}
		//  10210 11000
		if (fl == -1)
		{
			print("1" + s);
			continue;
		}
		// fl = 0;
		// cout << s << " " << fl << "\n";
		int tmp = 0;
		for (int i = fl; i >= 0; i--) {
			if (s[i] == '0') {
				s[i] = '1';
				tmp = 1;
				for (int j = i + 1; j < s.size(); j++) s[j] = '0';
				print(s);
				break;
			}
		}
		if (tmp == 0) {
			for (int j = 0; j < s.size(); j++) s[j] = '0';
			print("1" + s);
		}
		// cout << s << "\n";

	}
}