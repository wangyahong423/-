x,y,z=14,5,61
if x<y and y<z:
    print(x,y,z)
elif x<y and z<x:
    print(z,x,y)
elif x<z and z<y:
    print(x,z,y)
elif y<x and x<z:
    print(y,x,z)
elif y<z and z<x:
    print(y,z,x)
elif z<y and y<x:
    print(z,y,x)
