data=airquality
print(data)
data[,c("Solar.R")]=NULL
data[,c("Wind")]=NULL
print(data)
