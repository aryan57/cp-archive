/*
	group : local
	name : B_Caesar_Cipher.py
	srcPath : /home/aryan/Dropbox/Documents from PC/free/agastya/B_Caesar_Cipher.py
	url : /home/aryan/Dropbox/Documents from PC/free/agastya/B_Caesar_Cipher.py
*/
'''
n <= 10^5 ~ 10 ^6
O(n) O(logn) O(nlogn)

n <= 1000
O(n^2) O(n) O(logn) O(nlogn)

if n = 10^5
log10(n) = 5

rule of thumb is in 
1 sec atmost 10^8 operations can be done
'''

l = [1, 2, 356, 45]
'''
	my goal is to find the sum
	of all elements of array

	for i in range(len(l)):
		total+=l[i]

	O(n)

	for i in range(len(l)):
		total+=l[i]
		for j in range(len(l)):
			total+=l[j]

	O(n + n+ ... ntimes)  = O(n^2)

	O(26*n)
	
'''

def shift(c:str, K:int):
	pos = (ord(c)-ord('a') + K)%26
	return chr(ord('a')+pos)


def main():
    S = input()
    T = input()

    for K in range(26):
        A = ""
        for i in range(len(S)):
            A += shift(S[i], K)

        if(A == T):
            print("Yes")
            return

    print("No")


main()


#	parsed : 12-February-2022 15:03:43 IST
