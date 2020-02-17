def F(a):
    if len(a)==1:
        return(a[0])
    else:
        return(F(a[1:])-a[0])
a=[1,4,9,16]
print(F(a))
