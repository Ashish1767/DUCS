def count():
    d=input("Enter a sentence:")
    dct={}
    for i in d:
        dct[i]=dct.get(i,0)+1
    print(dct)

count()
