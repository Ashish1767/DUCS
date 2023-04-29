read("janitor")
library(janitor)
data2<-clean_names("iris")
data3<-remove_empty(data2,which=c("rows","cols")
                    quiet=FALSE)
air=airquality
air$Ozone=ifelse(is.na(air$Ozone),median(air$Ozone,na.rm=TRUE),air$Ozone)
print(air)
print(air$Ozone)
write.csv(air,"C:/Users/pc/OneDrive/Documents/ashi/ashi1.csv", row.names = FALSE)

