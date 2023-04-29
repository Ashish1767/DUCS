thismatrixa<-matrix(data=9:16,nrow=4,ncol=2)
thismatrixa
thismatrixb<-matrix(data=1:8,nrow=4,ncol=2)
thismatrixb
thismatrixc<-(thismatrixa+thismatrixb)
print("sum is")
thismatrixc
print("subtract  is")
thismatrixd<-thismatrixa-thismatrixb
thismatrixd
thismatrixa<-matrix(data=1:8,nrow=4,ncol=2)
thismatrixa
thismatrixb<-matrix(data=9:16,nrow=2,ncol=4)
thismatrixb
print("multiply is")
thismatrixe<-thismatrixa%*%thismatrixb
thismatrixe
