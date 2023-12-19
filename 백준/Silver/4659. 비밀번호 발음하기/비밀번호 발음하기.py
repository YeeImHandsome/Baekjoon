import sys

vowels=['a','e','i','o','u']

while True:
  s=str(input())
  if s=="end" : break

  cnt=0
  result="acceptable"

  cont=0 
  test=0 
  for i in range(len(s)):
    if test==1 and s[i] in vowels:cont+=1 
    elif test==0 and s[i] not in vowels:cont+=1
    else:
      if s[i] in vowels:test=1
      else:test=0
      cont=1
    if cont==3:
      result="not acceptable"
      break
    if s[i] in vowels:cnt+=1 
    if i>0 and s[i]==s[i-1]: 
      if s[i]=='e' or s[i]=='o': continue
      result="not acceptable"
    
  if cnt==0:result="not acceptable"
  print("<%s> is %s."%(s,result))