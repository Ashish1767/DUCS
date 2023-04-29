num<-as.integer(readline(prompt = "Enter the number :"))
fibonacci_series<-function(num)
{
  a1=0
  a2=1
  if(num<0){
    print("Enter valid number")
  }else{
    print(a1)
    print(a2)
    for (x in 1:num) {
      a=a1+a2
      a1=a2
      a2=a
      print(a2)
    }
  }
}
fibonacci_series(num)
