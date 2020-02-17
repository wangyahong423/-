import random:
n=random.randit(1,100)
a=int(input())
b=int(input())
if a%b==0:
    print(b)
elif b%a==0:
    print(a)
elif a%n==0 and b%n==0:
    print(n)
