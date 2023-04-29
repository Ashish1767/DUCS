num=int(input("enter the no. to check whether it is prime or not?"))
def isprime(n):
    for i in range(2,int(n/2)+1):
        if n%i==0:
         return False
    return True
    
if(isprime(num)):
  print("this no is prime no.")
else:
    print("this is not a prime no.")


    n=int(input('enter the no upto which you want to print the prime nos.: '))
    for i in range(2, n+1):
        if(isprime(i)):
            print(i)
4