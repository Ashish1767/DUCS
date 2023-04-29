
a<-as.integer(readline("Enter the no. of elements in a vector: "))
b<-c()
total_fun<-function(a)
{
  for(i in (1:a))
  {
    b[i]<-as.integer(readline())
    
  }
  print(sum(b))
}
total_fun(a)