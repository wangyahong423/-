def f(a):
    s=0
    for i in a:
        if i<=0:
            continue
        else:
            s+=1
    return(s)
a=[15,9,-9,8,-1]
print(f(a))
