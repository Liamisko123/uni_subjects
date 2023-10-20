import random

def roundCounter(number: int, sum=0):
    if number == 1:
        return sum
    round = number // 2
    leftover = number - round*2
    sum += round + roundCounter(round+leftover, sum)
    return  sum

def doorsMain(doIt=False):
    doors = [1,2,3]
    pick = random.choice(doors)
    random.shuffle(doors)
    car = doors[0]
    if doIt:
        doors.remove(pick)
        pick = random.choice(doors)
        if pick == car:
            return True
    elif pick == car:
        return True
     
    return False

count_find = 0
count_iteration = 10000
for i in range(count_iteration):
    if(doorsMain(True)):
        count_find += 1
print("You chose to open the door, percentage {}" .format(count_find/count_iteration))
print("You chose not to open the door, percentage")

