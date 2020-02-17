for k in range(1,10):
    if k%2==0:
        continue
    s=''
    for v in range(1,k+1):
        s=s+str(v)+'*'+str(k)+'='+str(k*v)+'\t'
    print(s)
