recurse <- function(n) {
  if (n <= 1){
    return(n)
  } else {
    return(recurse(n-1) + recurse(n-2))
  }
}
n <- as.integer(readline("Enter the number: "))
if(n< 0) {
  print("please enter a positive integer")
} else {
  print("Fibonacci Sequence: ")
  for(i in 0:(n)){
    print(recurse(i))
  }
}