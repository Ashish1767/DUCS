
library(learningr)
print(english_monarchs)
a<- str_detect(english_monarchs$domain,fixed(","))
print(a)
c<-str_split(english_monarchs$name,(",/and"))
print(c)
 


