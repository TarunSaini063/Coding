#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(v) (int)v.size();
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
int main(void)
{
	FIO	
	int n;
	vector<int>prime;
	for(int i =2;i<=100;i++){
		int fl = 1;
		for(int j = 2;j<i;j++){
			if(i%j==0){
				fl = 0;
				break;
			}
		}
		if(fl) prime.pb(i);
	}
	cin>>n;
	int arr[n];
	for(int &i : arr) cin>>i;
	int p = sz(prime);
	for(int i = 1 ;i<(1<<p);i++){
		int j = i,cnt=0,res=1;
		while(j!=0){
			if(j&1){
				res *= prime[cnt];
				cnt++;
				j>>=1;
			}
		}
	}
	return 0;
}