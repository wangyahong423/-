N=int(input())
i=0
for i in range(0,N):
    i=i+1
    if i%6==0:
        print("HelloWorld")
    elif i%2==0:
        print("Hello")
    elif i%3==0:
        print("World")
    elif i%2!=0 and i%3!=0:
        print(i)

