/*
	group : local
	name : B_String_Shifting.py
	srcPath : /home/aryan/Dropbox/Documents from PC/free/agastya/B_String_Shifting.py
	url : /home/aryan/Dropbox/Documents from PC/free/agastya/B_String_Shifting.py
*/
S = input()

l = []
n=len(S)

while(n>0):
	l.append(S)
	S = S[1:] + S[0]
	n-=1

print(min(l))
print(max(l))