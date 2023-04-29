def compute(list1):
    cube=lambda x:x**3
    y=map(cube,list1)
    print(list(y))
list1=eval(input("Enter the list element : "))
compute(list1)

