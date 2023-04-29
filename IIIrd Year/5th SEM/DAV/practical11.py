n=int(input("Enter a number : "))
def outp(n):
    
    result=[[i*j for j in range(1,6)] for i in range(1,n+1)]
    print(result)
outp(n)

