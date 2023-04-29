a<-c()
num<-as.integer(readline("Enter the number of elements in vector"))
for(i in c(1:num))
{
  a[i]<-as.integer(readline())
}
binary_search<-function(b)
{
  len<-length(b)
  first<-1
  last<-len
  search<-as.integer(readline("Enter the number to be search"))
  while(first<=last)
  {
    mid<-(first+last)%/%2
    if(b[mid]==search)
    {
      return(mid)
    } else if(b[mid]>search){
      last<-mid-1
    } else {
      first<-mid+1 
    }
  }
  return(0)
}
element<-binary_search(a)
if(element>0){
  cat("Element found at ",element," index")
} else{ 
  cat("Element not present ")}