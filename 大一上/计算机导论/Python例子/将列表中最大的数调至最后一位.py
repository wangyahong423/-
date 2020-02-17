def g(ls):
    m=0
    for i in range(0,len(ls)):
        if ls[i]>ls[m]:
            m=i
            ls[0],ls[m]=ls[m],ls[0]
ll=[4,5,1,2,0]
g(ll)
print(ll)
