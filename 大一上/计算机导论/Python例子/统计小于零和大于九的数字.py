def f(a):
    for i in a:
        if i<=9 and i>=0:
            continue
        else:
            return(False)
        return(True)
a=[-2,5,8,9,46,52]
print(f(a))
