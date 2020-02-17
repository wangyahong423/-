L=[1,1,2,3,5,8,13,21,34,55,89,144]
for n in L:
    def fab(n):
        if n==1:
            return 1
        if n==0:
            return 0
        else:
            return fab(n-1)+fab(n-2)
print(fab(4))
    
