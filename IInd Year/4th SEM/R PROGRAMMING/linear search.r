n<-as.integer(readline("Enter the number of elements in vector"))
b<-c()
for(i in c(1:n))
{
  b[i]<-as.integer(readline())
}
linear_search<-function(b)
{
  len<-length(b)
  search<-as.integer(readline("Enter the number to be search in array"))
  for(i in c(1:len))
  {
    if(b[i]==search)
    {
      return(i)
    }
  }
  return(0)
}
ele<-linear_search(b)
if(ele>0){
  print(paste("Element found at ",ele," index"))
} else{ 
  print(paste("Element not present "))}