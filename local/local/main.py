/*
	group : local
	name : main.py
	srcPath : /home/aryan/Dropbox/Documents from PC/free/agastya/main.py
	url : /home/aryan/Dropbox/Documents from PC/free/agastya/main.py
*/
n,a,b = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

maximum=0

for num in range(2**n):
	# 110
	taken_A =[]
	taken_B =[]

	for bit in range(n):
		if((num>>bit)&1): # this is true if the bit-th bit in num is 1
			taken_A.append(A[bit])
		else:
			taken_B.append(B[bit])

	if(len(taken_A)==a and len(taken_B)==b):
		maximum=max(maximum,sum(taken_A)+sum(taken_B))

print(maximum)