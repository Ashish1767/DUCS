
data<-airquality

a<-function(x)
{
  (x-min(x))/(max(x)-min(x))
}
b<-as.data.frame(lapply(data$Solar.R,a)

z_score<-function(x)
{
 (x-mean(x))/sd(x)
}
c<-as.data.frame(lapply(data$Wind,z_score))

print(a)
print(b)
print(z_score)
print(c)
    
