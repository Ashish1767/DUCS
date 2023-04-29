a<-c(1,3,5,9,11,56,34,88,34,0)
b<-as.integer(readline(prompt = "Enter the element to be search : "))
if(is.element(b,a))
{
  print("Element is  present")
}else{
  print("Element is  not present")
}