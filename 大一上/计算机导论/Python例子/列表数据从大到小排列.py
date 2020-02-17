a=[1,3,5,2,4];
for i in range(0,4):
    for j in range(i+1,5):
        if(a[i]<a[j]):
            t=a[i]
            a[i]=a[j]
            a[j]=t
print(a)
