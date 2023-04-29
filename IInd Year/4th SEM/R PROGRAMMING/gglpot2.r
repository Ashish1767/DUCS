View(iris)
hist<-ggplot(data=iris, aes(x=Sepal.Length))+ geom_histogram()
print(hist)


bar<-ggplot(data=iris, aes(x=Sepal.Length))+ geom_bar()
print(bar)


Scatter<-ggplot(data=iris, aes(x=Sepal.Length, y=Sepal.Width))+ geom_point()
print(Scatter)


box<-ggplot(data=iris, aes(x=Sepal.Length))+ geom_boxplot()
print(box)



line<-ggplot(data=iris, aes(x=Sepal.Length, y=Sepal.Width))+ geom_line()
print(line)


p=ggplot(mpg,aes(x=class))+ geom_bar()
p+labs(title = "Number of cars in each type" , X="Type of car", Y=" Number of cars")

