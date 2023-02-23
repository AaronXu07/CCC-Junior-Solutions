C = int(input())

TotalBlackTriangles = 0

FirstRow = input().split()
SecondRow = input().split()

LocationsF = []
LocationsS = []

Beside = 0

for i in range(C):
  if FirstRow[i] == "1":
    TotalBlackTriangles+=1
    LocationsF.append(i)

for i in range(C):
  if SecondRow[i] == "1":
    TotalBlackTriangles+=1
    LocationsS.append(i)
    
for i in range(len(LocationsF)-1):
  if LocationsF[i] == LocationsF[i+1]+1:
    Beside+=1
  if LocationsF[i] == LocationsF[i+1]-1:
    Beside+=1

for i in range(len(LocationsS)-1):
  if LocationsS[i] == LocationsS[i+1]+1:
    Beside+=1
  if LocationsS[i] == LocationsS[i+1]-1:
    Beside+=1

for i in range(C):
  if i%2 == 0:
    if FirstRow[i] == "1" and SecondRow[i] == "1":
      Beside+=1

print(TotalBlackTriangles*3 - Beside*2)
  
