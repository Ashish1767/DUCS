num=int(input( 'enter the no for finding the sum of odd terms'))
 
def oddsum(n):
  sum=0
  odd=1
  for i in range(1, n+1):
   sum+=odd
   odd+=2
  print('the sum  of',n,'is',sum)

oddsum(num)




num=int(input( 'enter the no for  finding sum of even terms'))
 
def evensum(n):
  sum=0
  even=2
  for i in range(1, n+1):
   sum+=even
   even+=2
  print('the sum  of',n,'is',sum)

evensum(num)