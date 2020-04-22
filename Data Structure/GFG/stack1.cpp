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
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		string s1;
		cin>>s1;
		stack<char> s;
		int fl=1;
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]=='('||s1[i]=='['||s1[i]=='{') s.push(s1[i]);
			else {
				char c;
				fl=1;
				if(s1[i]==')') c='(';
				else if(s1[i]=='}') c='{';
				else c='[';
				if(s.empty()||s.top()!=c) {fl=0;break;}
				s.pop();
			}
		}
		if(fl==0||!s.empty()) cout<<"not balanced"<<"\n";
		else cout<<"balanced"<<"\n";
	}
	return 0;
}