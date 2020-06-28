n,m=map(int,input().split())
arr=list(map(int,input().split()))
ans=0
s=[0]*m
arr.sort()
for i in range(n):
	s[i%m]+=arr[i]
	ans+=s[i%m]
	print(ans,end=' ')