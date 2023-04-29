str<-c()
str<-as.character(readline("Enter a string for palidrome :"))
Palindrome <- function(str){
  x<-strsplit(as.character(str), "")
  r <- rev(unlist(x))
  p <- as.character(paste(r, collapse=""))
  if(p==str)
    return(TRUE)
  print("not a palindrome")
}
q<-Palindrome(str)
if(q==TRUE)
  print(paste(q,", ",str," is a palindrome"))

