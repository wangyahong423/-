import random

num=3
a=0
b=0
n=0

dict1={
    1:"剪刀",
    2:"石头",
    3:"布",
}
print("---------猜拳小游戏----------")
print("************************")
print("1.开始新游戏")
print("2.退出")
change=input("请选择：")
if change=='1':
    while num>0:
        rand=random.randint(1,3)
        while True:
            i=input('请输入手势【剪刀、石头、布】：')
            k=i.strip()   #移除前后空格
            if k in dict1.values():   #判断用户输入的值是否在字典中
                break
            else:
                print("Error：‘%s’是一个错误手势"%(i))
        if rand==1:
            if k=="剪刀":
               result=("平局")
               b+=1
            elif k=="石头":
                result=("恭喜！你赢了！")
                n+=1

            else:
                result=("电脑胜")
                a+=1

        elif rand==2:
            if k=="剪刀":
                result=("电脑胜")  
                a+=1
            elif k=="石头":
                result=("平局")
                b+=1
            else:
                result=("恭喜!你赢了！")
                n+=1
        else:
            if k=="剪刀":
               result=("恭喜！你赢了！")
               n+=1
            elif k=="石头":
                result=("电脑胜")
                a+=1
            else:
                result=("平局")
                b+=1

        print("电脑出的是：%s/n你出的是:%s/n结果是：%s"%(dict1[rand],k,result))
        num-=1
        g=a+b+n
        if num==0:
            print("本次猜拳的结果是：(平局：%s局、获胜：%s局、失败：%s局)"%(b,n,a))
            if n>a:
                print("经过%s个回合你赢了！"%(g))
                j=input("经过%s个回合后你赢了，是否继续[y/n]:"%(g))
                if j=="y" or j=="Y"or j=="是":
                    num=3
                elif j=="n" or j=="N" or j=="否":
                    print("经过%s个回合你赢了！"%(g))
            if n<a:
                print("经过%s个回合你输了！"%(g))
                j=input("经过%s个回合后你输了是否继续[y/n]:"%(g))
                if j=="y" or j=="Y"or j=="是":
                    num=3
                elif j=="n" or j=="N" or j=="否":
                    print("经过%s个回合你赢了！"%(g))
            elif n==a:
                j=input("经过%s个回合后未能分出胜负是否继续[y/n]:"%(g))
                if j=="y" or j=="Y"or j=="是":
                    num=3
    else:
        exit()
print("游戏结束.")
  
            
