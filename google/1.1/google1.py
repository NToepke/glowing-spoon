def solution(s):
    braille = "" # string to be returned
    guide_list = [100000,110000,100100,100110,100010,110100,110110,110010,10100,10110]
    # the guide list has 10 sepcific template setups of the top four dots of braille. All letters
    # except w follow this template and are sequenced in order through the list.
    for x in s:
        x_unicode = ord(x) # create unicode variable for evaluating each number logically
        temp_braille = 000000

        if x_unicode == 32: # check for a space character
            braille += "000000"
            continue
        
        if x_unicode in range(65,91): # identify if letter is a capital
            braille += "000001"
            x_unicode += 32  #update unicode value to reflect lower case letter
            
        if x_unicode == 119: # if x is a w, rules do not apply to it
            braille += "010111" # w is special and therefore must be added separately
            continue
        if x_unicode > 119: # because of w, move x,y,z unicodes to fit pattern of braille
            x_unicode -= 1
        
        if x_unicode in range(107,123): # if the letter is after j, it gets the bottom left dot
            temp_braille+=1000
            
        if x_unicode in range(117,123): # if the letter is after t, it gets the bottom right dot
            temp_braille+=1
        temp_braille += guide_list[(x_unicode-97)%10] 
        # elements in guide list contain templates for top four dots of braille
        # letters 0, 10 and 20 share the same four dots, and therefore we can index the list
        # as such, where the unicode - 97, unicode for a, modulus 10 will result in the index
        # of the correct top four dots of braille
        if temp_braille<100000: 
            # there is two occurances in guide list of a zero in the top left spot,
            # so this is accounted for here.
            braille+="0"
        #concatenate the number, which is converted into string, onto the full string of braille encoding
        braille+=str(temp_braille)
    return braille

#braille = solution("u")
braille = solution("The quick brown fox jumps over the lazy dog")

print(braille)

