def g(ll):
    m=0
    for i in range(0,len(ll)):
        if ll[i]>ll[m]:
            m=i
    ll[0],ll[m]=ll[m],ll[0]
ll=[4,5,1,2,0]
g(ll)
print(ll)
