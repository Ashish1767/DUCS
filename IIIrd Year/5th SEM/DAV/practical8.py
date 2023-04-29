def pri(t1):
    t=tuple()
    for i in t1:
        if i%2==0:
            t+=(i,)
            print("even no in tuple",t)
def max_min(t1):
    a=max(t1)
    b=min(t1)
    return a,b
def con(t1):
   t2=(11,13,15)
   print(t1+t2)

print(" press 1 for another tuple whose values are even numbers in the given tuple ")
print(" press 2 for return the maximum and minimum value from this tuple ") 
print(" press 3 for concatenate tuple t2=(11,13,15) with t1 ")

c=int(input("enter your choice"))
t1=(1,3,5,7,9,2,4,6,8,10)
if c==1:
    pri(t1)

elif c==2:
    a,b=max_min(t1)
    print("max=",a)
    print("min=",b)

elif c==3:
    con(t1)
   
else:
     print("wrong choice")
