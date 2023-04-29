a<-as.integer(readline("Enter the number of elements ia a vector: "))
b<-c()
largest_element<-function(a)
{
  print("Elements are:")
  for(i in c(1:a))
  {
    b[i]<-as.integer(readline())
    
  }
  return(max(b))
}
large<-largest_element(a)
print(paste("Largest element  is :",large))