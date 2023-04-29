num=int(input("Enter a number: "))

def IterativeFact(n):
    f=1
    for i in range(2,n+1):
        f*=i
    print("Iterative factorial of ",n,": ",f)

IterativeFact(num)

def RecursiveFact(n):
    if(n==1):
        return n
    else:
        return n*RecursiveFact(n-1)

print("Recursive factorial of",num,": ",RecursiveFact(num))

num1=int(input("Enter nth term: "))

def IterativeFibo(n):
    a=0
    b=1
    c=0
    for i in range(1,n):
        c=a+b
        a=b
        b=c
    print("Iterative ",n,"th term of fibonacci series: ",c)
IterativeFibo(num1)

def RecursiveFibo(n):
    if(n<=1):
        return n
    else:
        return(RecursiveFibo(n-1)+RecursiveFibo(n-2))

print("Recursive ",num1,"th term of fibonacci series: ",RecursiveFibo(num1))