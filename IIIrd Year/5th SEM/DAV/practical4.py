print("Menu Driven Program")

ch='yes'
while(ch=='yes'):
    print("press 1 for square")
    print("press 2 for triangle")
    print("press 3 for circle")
    print("press 4 for rectangle")
    choice=int(input("Enter choice: "))

    if(choice==1):
        a=int(input("Enter side of square: "))
        area=a*a
        print("Area of square: ",area)
    elif(choice==2):
        b=int(input("Enter base of the triangle: "))
        h=int(input("Enter height of the triangle: "))
        area=0.5*b*h
        print("Area of triangle: ",area)
    elif(choice==3):
        r=int(input("Enter radius of the circle: "))
        area=3.14*r*r
        print("Area of Circle: ",area)
    elif(choice==4):
        l=int(input("Enter length of the rectangle: "))
        b=int(input("Enter breadth of the rectangle: "))
        area=l*b
        print("Area of Rectangle: ",area)
    else:
        print("WRONG CHOICE!!!")
    ch=input("Do u want to continue?(y/n): ")
    