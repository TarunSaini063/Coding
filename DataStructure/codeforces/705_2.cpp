#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define sz(s) (int)s.size()
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
vector < int > go = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
int inf = 1e9 + 7;
int get(int x) {
    string s = to_string(x);
    if ((int)s.size() == 1) s = "0" + s;
    string answ = "";
    for (int i = 1; i >= 0; --i) {
        if (go[s[i] - '0'] == -1) return inf;
        answ += char(go[s[i] - '0'] + '0');
    }
    return stoi(answ);
}
string good(int x) {
    string ans = to_string(x);
    if (x < 10) {
        ans = "0" + ans;
    }
    return ans;
}

int main(void)
{
	FIO	
	int t, h, m, H, M;
	string s;
	cin>>t;
	while(t--){
		cin >> h >> m;
        cin >> s;
        H = (s[0] - '0') * 10 + s[1] - '0';
        M = (s[3] - '0') * 10 + s[4] - '0';
        while (1) {
            if (M == m) {
                H++, M = 0;
            }
            if (H == h) {
                H = 0;
            }
            if (get(M) < h && get(H) < m) {
                cout << good(H) << ":" << good(M) << '\n';
                break;
            }
            M++;
        }
	}
	
	return 0;
}