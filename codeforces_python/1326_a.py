t=int(input())
for _ in range(t):
	n=int(input())
	if n==1:
		print(-1)
	else:
		for _ in range(n-1):
			print(5,end="")
		if ((n-1)*5+3)%3!=0:
			print(3)
		else: print(4)