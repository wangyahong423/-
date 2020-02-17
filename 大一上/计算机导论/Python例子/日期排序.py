import random
Aa=random.randint(1,12)
Bb=random.randint(1,31)
C=random.randint(0,9)
c=random.randint(0,9)
D=random.randint(0,9)
d=random.randint(0,9)
CcDd=(str(C)+str(c)+str(D)+str(d))
N=int(input())
n=1
for n in range(1,N+1):
    n=n+1
    i=(str(Aa)+"/"+str(Bb)+"/"+str(CcDd) )
    print(i)
    
