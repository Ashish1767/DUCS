#take input from user
n=as.integer(readline("enter a number"))
if(n<0)
  {
  print("enter a positive number")
  }else{
  sum=(n*(n+1))/2;
  print(paste("the sum is:",sum))
}
              