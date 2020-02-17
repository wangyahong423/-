import random
def caishu():
    i=0
    key=random.randint(1,10)
    while i<5:
        guss=int(input("enter: "))
        if key==guss:
            print ('good guess!')
            break
        elif guss>key:
            print('guss>key  try again')
        else:
            print('guss<key  try again')
        i+=1
    else:
        print("game over")
        print("The key is: ",key)
caishu()
