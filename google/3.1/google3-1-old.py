def solution(m):
    # Your code here
    
    size = len(m)
    probability = [0]
    for n in m:
        probability.append(0)
    terminal = list()
    i=0
    # search for all terminal states, store their indexes
    while i < size:
        if sum(m[i]) == 0:
            terminal.append(i)
        else:
            terminal.append(-1)
        i+=1

    i=0
    row_sum = sum(m[0])
    if row_sum == 0: # check for terminal beginning
        return [0,0]
    while i < size:
        probability[i] = m[0][i]
        i+=1
    i=0
    j=0
    probability[-1] = row_sum
    
    while i < size: #check each column in row 0, find anything that isnt zero
    
       
        if m[j][i] != 0: #finding anything thats not zero
            
            if i in terminal: #does this probability lead to a dead end immediately
                probability[i] += m[0][i] * probability[-1]
                probability[-1] += m[0][i]
                i+=1
                continue
            else:
                while sum(m[j]) != 0:
                    
        i+=1
    
    i = size - 1
    while i >= 0:
        if terminal[i] == -1:
            probability.pop(i)
            terminal.pop(i)
        i-=1
    return probability
#BUFFER

def main():
    x = solution([[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]])
    for n in x:
        print(n)
main()
