data=letters
a=sample(data,size=100,replace=TRUE)
print(a)
b=factor(a)
print(b)
print('printing 5 levels')
print(table(a[1:5]))
