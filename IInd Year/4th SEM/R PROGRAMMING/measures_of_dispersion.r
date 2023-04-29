
x=c(rep(95.5,5),rep(105.5,8),rep(115.5,22),rep(125.5,27),rep(135.5,17),
    rep(145.5,9),rep(155.5,5),rep(165.5,5),rep(175.5,2))

print(x)
print(paste("Variance  of x :",var(x)))
print(paste("standard deviation  of x:",sd(x)))
print(paste("Range of x:",range(x)))
print(paste("Mean of x:",mean(x)))
print(paste("Quartile of x:",quantile(x)))
print(paste("Median of x :",median(x)))