L=[2,3,2,3,2,5]
len=6
for i in range(0,len):
    for j in range(i+1,len):
        if L[i]==L[j]:
            for k in range(j,len-1):
                L[k]=L[k+1]
            len=len-1
print(L[0:len])
