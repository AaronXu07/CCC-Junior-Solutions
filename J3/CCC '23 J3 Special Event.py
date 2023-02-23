N = int(input())

max = 0
maxday = 0
multiplemax = [0]
people = []

for i in range(N):
  TempP = input()
  people.append(TempP)

x = 0

for i in range(5):
  current = 0

  for j in range(N):
    temporary = people[j]
    if temporary[i] == "Y":
      current += 1

  if current > max:
    multiplemax.clear()
    max = current
    maxday = i+1
    multiplemax.append(maxday)

  elif current == max:
    maxday = i+1
    multiplemax.append(maxday)


for i in range(len(multiplemax)):
  if i > 0:
    print(",", end="")
  print(multiplemax[i], end="")

