def f(L):
    if L==[]:
        return
    print("L=",L)
    f(L[0:len(L)-1])
    print("L:",L)
    return
X=[1,2,3]
f(X)
print("outside f,X=",X)
