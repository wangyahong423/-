x=int(input("请输入个数："))
L=[]
for i in range (x):
        print("第",i+1,"个元素：")
        s=int(input())
        L.append(s)
print =("当前列表：",L)

print("请输入要删除的：")
y=int(input())
while y in L:
    L.remove(y)
print =("最新列表：",L)
