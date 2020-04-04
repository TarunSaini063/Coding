#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int gcd(int a,int b)
{
if (b==0)
return a;
else
return gcd(b,a%b);
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		int a,c,d=0;
		string b;
		cin>>a>>b;
		if(a==0) cout<<b<<endl;
		else{ 
		for(int i=0;i<b.size();i++)
		{
			c=d*10+(b[i]-'0');
			d=c%a;
		}
		cout<<gcd(a,d)<<endl;}
	}
	return 0;
}