def text(score):
    if score>=90:
        print('Excellent',end='')
        if score>=95:
            print('*')
        else:
            print('')
    elif score>=80:
        print('Very Good',end='')
        if score>=85:
            print('*')
        else:
            print('')
    elif score>=70:
         print('Good',end='')
        if score>=75:
            print('*')
        else:
            print('')
    elif score>=60:
         print('Pass',end='')
        if score>=65:
            print('*')
        else:
            print('')
    elif score<=60:
         print('Fail')
text(score=int(input("请输入：")))
        
        
