import itertools
def solution(l):
    largest_number = 0
    number_of_digits = len(l)
    l.sort()
    l.reverse()
    possible_numbers = list()
    while number_of_digits > 0:
        all_numbers = list(itertools.permutations(l,number_of_digits))
        
        for x in all_numbers:
                if number_of_digits > 1:
                    x = int(''.join(str(y) for y in x))
                else:
                    x = x[0]
                if x % 3 == 0:
                    possible_numbers.append(x)
        possible_numbers.sort()
        possible_numbers.reverse()
        if not possible_numbers:
            number_of_digits-=1
        if possible_numbers:
            largest_number=possible_numbers[0]
            break
    return largest_number
l = []
print(solution(l))
