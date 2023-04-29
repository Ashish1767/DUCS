a=airquality
print(a)
tapply(a$Ozone,a$Temp,max)
sapply(a$Solar.R,max)
lapply(a$Month,min)
