x = list(c(0,2), matrix(c(1:9),nrow=3,byrow=TRUE), list(5,6))
names(x)<-c("first","second","third")
print("First and Second element of list = ")
print(x[1])
print(x[2])
print("Original list = ")
print(x)
print("Second element of the list = ")
print(x$second[2])
print("Update the last element of the list = ")
x[4] =  "R programming"
print(x)
print("After removing second element of the list = ")
x[2]<-NULL
print(x)