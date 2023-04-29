 
toy <- read.csv(file.choose())
attach(toy)
 
View(toy)

x <- subset(toy, City=="New York City")
 
nrow(x)

y <- subset(toy, Income>mean(Income))
nrow(y)

z <- subset(toy, Gender=="Female")
fmax<- subset(z, Income==max(Income))

a <- order(Income, decreasing = TRUE)
b <- toy[a, ]
head(b)

toy[sample(nrow(toy),10), ]

detach(toy)