View(airquality)
print(paste("Ozone ", airquality$Ozone))
print(paste("Solar.R ", airquality$Solar.R))
print(paste("Wind ", airquality$Wind))
print(paste("Temp ", airquality$Temp))
print(paste("Month ", airquality$Month))
print(paste("Day ", airquality$Day))

print(paste("Structure of airquality ", str(airquality)))
print(paste("Numbers of row ", nrow(airquality)))
print(paste("Length ", length(airquality)))

print(paste("Mean of Ozone ", mean(airquality$Ozone)))
print(paste("Mean of Solar.R ", mean(airquality$Solar.R)))
print(paste("Mean of Wind ", mean(airquality$Wind)))
print(paste("Mean of Temp ", mean(airquality$Temp)))
print(paste("Mean of Month ", mean(airquality$Month)))
print(paste("Mean of Day ", mean(airquality$Day)))

print(paste("Median of Ozone ", median(airquality$Ozone)))
print(paste("Median of Solar.R ", median(airquality$Solar.R)))
print(paste("Median of Wind ", median(airquality$Wind)))
print(paste("Median of Temp ", median(airquality$Temp)))
print(paste("Median of Month ", median(airquality$Month)))
print(paste("Median of Day ", median(airquality$Day)))

print(paste("Summary of Ozone ", summary(airquality$Ozone)))
print(paste("Summary of Solar.R ", summary(airquality$Solar.R)))
print(paste("Summary of Wind ", summary(airquality$Wind)))
print(paste("Summary of Temp ", summary(airquality$Temp)))
print(paste("Summary of Month ", summary(airquality$Month)))
print(paste("Summary of Day ", summary(airquality$Day)))

attach(airquality)

print(paste("Head ", head(airquality)))
print(paste("Tail ", tail(airquality)))

print(paste("Sorting Ozone ", sort(Ozone)))
print(paste("Sorting Solar.R ", sort(Solar.R)))
print(paste("Sorting Wind ", sort(Wind)))
print(paste("Sorting Temp ", sort(Temp)))
print(paste("Sorting Month ", sort(Month)))
print(paste("Sorting Day ", sort(Day)))


plot(Ozone)
plot(Solar.R)
plot(Wind)
plot(Temp)
plot(Month)
plot(Day)

barplot(Ozone)
barplot(Solar.R)
barplot(Wind)
barplot(Temp)
barplot(Month)
barplot(Day)

boxplot(Ozone)
boxplot(Solar.R)
boxplot(Wind)
boxplot(Temp)
boxplot(Month)
boxplot(Day)

quantile(Wind)
quantile(Temp)
quantile(Month)
quantile(Day)
