matrix1<-matrix(c(12:17),nrow=3,byrow=TRUE)
matrix2<-matrix(c(21:28),nrow=4,byrow=TRUE)
cat("Concatenation of two matrices ","\n")
print(rbind(matrix1,matrix2))