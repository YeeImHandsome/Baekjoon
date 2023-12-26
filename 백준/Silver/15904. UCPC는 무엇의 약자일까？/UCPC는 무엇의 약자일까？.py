s = input()
data = ['U', 'C', 'P', 'C']
flag = True

for i in range(4) :
  if data[i] in s :
    flag = True
    index = s.find(data[i])
    s = s[index+1::]
  else :
    flag = False
    break

if flag == True :
  print('I love UCPC')
else :
  print('I hate UCPC')