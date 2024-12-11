a=int(input("enter the number: "))
flag=True
for i in range(2,a//2):
    if a%(i)==0:
        flag=False
        break
    
if(flag==True):
    print(a,"is a prime number")
else:
    print("the number is not prime")