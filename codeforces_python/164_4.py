import math
n=int(input());
arr=[]
j=2
while j*j<=n:
	cnt=0
	while n%j==0:
		cnt=cnt+1
		n=n/j
	if cnt!=0:
		arr.append(cnt)
	j=j+1
if n>1:
	arr.append(1)
ans=int(0)
for i in arr:
	ans=ans+int((math.sqrt(1+8*i)-1)/2)
print(ans)