

def sub(s):
      p=input("Which string position do you want? : ")

      print("Index : ",s.find(p))

def repl(s):
      print("After replacing 'good' with 'best' : ",s.replace("good","best"))
    

def find_substr(s):
       print("Substrings : ")
       print(s.split(";"))

def convert_text(s):
       print("Text to title form : ",s.title())

def rep(s):
    new=""
    for i in range(0,len(s)):
        if(i%2==0):
            new += s[i]
        else:
            new += "#"

    print(new)

def rev(s):
      print("Reverse of string : ",s[-1: :-1])
    

def find_num(s):
       r=s.split(" ")
       print("Length : ",len(r))


    




ch='y'
while(ch=='y'):
    print('press 1 for  finding substring and its position')
    print('press 2 for  replacing substring good with best ')
    print('press 3 for  finding  all substring separated by delimeter')
    print('press 4 for  converting given text into tittle form')
    print('press 5 for  replace every alternate characcter with #')
    print('press 6 for  printing reverse of substring')
    print('press 7 for  finding no of words in given string.')
    ch=int(input('enter your choice:'))
    num= (input("enter the string:"))

    if ch==1:
       sub(num)

    elif(ch==2):
      repl(num)

    elif(ch==3):
     find_substr(num)
    elif(ch==4):
      convert_text(num)
    elif(ch==5):
     rep(num)
    elif(ch==6):
       rev(num)

    elif(ch==7):
     find_num(num)
else:
    print("wrong choice")
    ch=input("dp you want to continue:(y/n)")







