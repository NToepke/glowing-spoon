def solution(l):

    coded = {}
    for x in l:
        y = {-1,-1,-1}
        if "." not in x:
            y[0]=int(x)
        else:
            minorIndex = x.find('.')
            revisionIndex=x.find('.',minorIndex)
            if revisionIndex == -1:
                y[0] = x[:minorIndex]
                y[1] = x[minorIndex+1:]
            else:
                y[0] = x[:minorIndex]
                y[1] = x[minorIndex+1:revisionIndex]
                y[2] = x[revisionIndex+1:]
        coded.append(y)
    coded.sort()

    for x in coded:
        print(x[0]+"."+x[1]+"."+x[2])



l= {"2.0.1","3","1.0","1.11.2","2.6","2.6.0"}
solution(l)
        #make string comparable
        #find where it fits in the list
        #put in in the list
