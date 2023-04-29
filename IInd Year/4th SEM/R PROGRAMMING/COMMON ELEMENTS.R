x=c()
numA<-as.integer(readline("Enter total number of element in vector 1 : "))
for(i in c(1:numA)){
  x[i]<-as.integer(readline("Enter the  number : "))
}

y=c()
numB<-as.integer(readline("Enter total number of element in vector 2 : "))
for(i in c(1:numB)){
  y[i]<-as.integer(readline("Enter  the number : "))
}

print("Common element are : ")
print(intersect(x,y))