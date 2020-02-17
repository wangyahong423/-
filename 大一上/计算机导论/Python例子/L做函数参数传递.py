def F1(L):
    L=[2,1]
    return(L)
def F2(L):
    L.append(1)
    L[0]=0#让列表中的2变成0
L=[3,2,1]#初始L，回到上面程序之后L变成[2,1]，之后进行下面的程序
L=F1(L);print("L=",L)
F2(L);print("L=",L)
    
