def solution(l):
    coded = []
    for x in l:
        y = [-1,-1,-1]
        y = map(int, x.split("."))
        coded.append(y)

    coded.sort()
    coded.reverse()
    sortedList = []

    for x in coded:
        index = 0
        for y in sortedList:
            if x[0] < y[0]:
                sortedList.insert(index,x)
                break
            elif x[0] == y[0]:
                try:
                    if x[1] < y[1]:
                        sortedList.insert(index,x)
                        break
                    elif x[1] == y[1]:
                        try:
                            if x[2] <= y[2]:
                                sortedList.insert(index,x)
                                break
                        except IndexError:
                            sortedList.insert(index,x)
                            break
                except IndexError:
                    sortedList.insert(index,x)
                    break
            index+=1
        if x not in sortedList:
            sortedList.append(x)

    final = []
    for x in sortedList:
          final.append('.'.join(map(str,x)))      


    
    #for x in sortedList:
        #x=map(str,x)
        #x=".".join(str(x))
        #final+=x+","
    #final = final[:-1]
    #for x in sortedList:
        #'.'.join(x)
    #Debugging Print Code
    print(final)
    print(l)

#l= ["2.0.1","3","1.0","1.11.2","2.6","2.6.0"]
l = ["1.11","2.0.0","1.2","2","0.1","1.2.1","1.1.1","2.0"]
solution(l)
