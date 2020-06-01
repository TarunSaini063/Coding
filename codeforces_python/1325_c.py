n=int(input())
freq=[0]*(n+1)
adj=[]
for i in range(n-1):
 	a,b=map(int,input().split())
 	a-=1
 	b-=1
 	freq[a]+=1
 	freq[b]+=1
 	adj.append([a,b])
cnt=0
mx=n-2
for a,b in adj:
 	if freq[a]==1 or freq[b]==1:
 		print(cnt)
 		cnt+=1
 	else :
 		print(mx)
 		mx-=1;