def countSum(*args):
    sum=0
    for i in args:
        if i>5:
            break
        sum+=i
    return sum
print(countSum(1,2,3,4,5,6,7,8,9))
