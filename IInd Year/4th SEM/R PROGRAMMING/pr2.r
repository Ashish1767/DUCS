y=data("iris")
glimpse(iris)
y=iris
y
library(janitor)
data2<-clean_names(y)
data2z
data3<-remove_empty(data2,which=c("rows","cols"),quiet=FALSE)
library(dplyr)
data_cleaned<-distinct(data3)
str(data_cleaned)
data_cleaned2<-distinct(data_cleaned.petal_length, .keep_all=TRUE)
data_cleaned2
write.csv(iris)


