def fil(l):
    x=[y.upper() for y in l if len(y)<=3 ]
    
    print(x)

def cr(l):
    x={len(y) for y in l }
    print(x)

def use_map(l):
    x=map(cr(l),l)
    print(x)


print("Press 1 for Use list comprehension to  filter out the strings with length 3 or less and also convert them to uppercase. ")
print("Press 2 for Use set comprehension to create a set containing just the lengths of the strings contained in  list_strings ")
print("Press 3 for Use map function(instead of set comprehension) for part b ")

l=["a", "an", "bat", "car", "python", "programming"]
ch='y'

while(ch=='y'):
 c=int(input("Enter your choice : "))
 if c==1:
    fil(l)

 elif c==2:
    cr(l)

 elif c==3:
    use_map(l)

 else:
    print("Wrong choice")
 c=input('do you want to continue(y/n')