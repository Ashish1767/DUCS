l1=eval(input("Enter the list elements:"))
print(l1)

flag=1
for i in l1:
    if(type(i)!=int):
        flag=0
        break
    

def odd(l1):
    count=0
    even_count=0
    for i in range(0,len(l1)):
        if l1[i]%2!=0:
            count=count+1
        else:
            even_count=even_count+1
    print("odd values are :",count)
    print("even values are:",even_count)



if flag==1:
    print("given list is numeric")
    odd(l1)

else:
    print("Given list is not numeric")
    print("Largest string is:",max(l1))
    print("Longest string is:",max(l1,key=len))

print("The list in reverse form is:")
l1.reverse()
print(l1)


l1.sort(reverse=True)
print("List in descending order is:",l1)


l=eval(input("Enter alist:"))


e=eval(input("Enter the element to search:"))
print(l.index(e))


l2=eval(input("Enter another list:"))

l=set(l)
l2=set(l2)
print("Common elements:",l&l2)

