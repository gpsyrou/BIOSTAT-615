#### Author : Georgios Spyrou

import random
import sys
try: input = raw_input  ## for python 2 ( because 2.0 doesnt read the input)
except NameError: pass  ## for python 3 

# read the file / we have to store every word in a list
with open(sys.argv[1],'r') as f: # sys.argv[1] to replace the file name
    content = f.readlines()
    
content = [x.strip() for x in content] # so we can remove the /n
itt_is = True # some bool values that will help the control
whole_counter_of_games = 0  # will count the total amount of times the user played
bool_=True 

the_full_Diction = {} # dictionary that will hold something we explain in a bit
words_names = [] # names of the words / list that will hold the keys of the dict

# now we construct the the_full_Diction dictionary following the logic of the lectures
# keys will be the words and the values will be the sorted names
# thus we will have a map of true word --> sorted version of the word

for k in content:
    the_full_Diction[k] = str(sorted(k)) # i used the_full_Diction as in the lecture's example

words_names = list(the_full_Diction.keys()) # we defined it above

print("") # i ll use some of them so i can make the display easier to read
print("---------------------------------------------"+
      "\nWelcome, to gspyrou's word unscrambler game!!"+
      "\n---------------------------------------------")
      
# we ask the user for an input values which is going to be the length of
# the word

while itt_is == True:
    bool_ = True
    print("")
    len_person_wanted = input("First, pick the length of the word you want to be challenged:"+
                "\n(type q to quit or type Enter to pick a random word): ")
    #in case first input is ENTER then we have to pick randomly
    if len_person_wanted == "": # # the case of user giving no length
        random_content = random.choice(words_names) # random assignment of a word
        sorted_word = str(sorted(random_content))
        answers = list()
        for k, v in the_full_Diction.items():
            if sorted_word in v:
                answers.append(k) # we have all the possible answers
    
    elif len_person_wanted == 'q': # in case the user want to exit at the first pick
        itt_is = False
        break                      # case of 'q' ends here
    else:  # in case we take an integer as input we have to check if its valid or not
        while int(len_person_wanted) > max(len(w) for w in content):
            # now we are doing pretty much the same as before
            len_person_wanted = input(("There is no word with length ") +str(len_person_wanted) 
            +(" . Choose a different length :"))
            if len_person_wanted == "": # the case of user giving no length
                random_content = random.choice(words_names)
                sorted_word = str(sorted(random_content))
                answers = list()
                for k, v in the_full_Diction.items():
                    if sorted_word in v:
                        answers.append(k) # we get all the possible answers
                bool_ = False
                break 
            elif len_person_wanted == 'q': # case the user wants to quit
                itt_is = False
                break                   # case of 'q' ends here
        if itt_is==False:
            break
        
        while bool_ == True: # this will proceed only for a legit given length
                random_content = random.choice(words_names)
                len_person_wanted = int(len_person_wanted)
                if len(random_content) == len_person_wanted:
                    sorted_word = str(sorted(random_content))
                    answers = list()
                    for k, v in the_full_Diction.items():
                        if sorted_word in v:
                            answers.append(k) #we get all the possible answers
                    break
                    
    # get a random permuted word
    random_permuted_word = ''.join(random.sample(random_content,len(random_content)))
    
    # now we ask the user to unscrable a permuted word and try guess the answer
    persons_guess = str(input("Unscramble the word  " + 
                                  "'%s'"%str(random_permuted_word) + ": "))
    
        
    if  persons_guess in answers  :
        print("Correct!")
        print("Correct answer(s) were : " + str(answers))
        whole_counter_of_games += 1  # +1 every time we play
    else:
        print("Sorry.. incorrect")
        print("Correct answer(s) were : " + str(answers))
        whole_counter_of_games += 1  # +1 every time we play / even when we dont have the correct answer

#### now the game ended ,we can print some statistics
# like how many times the player played the game
# and also say goodbye to the user
print("")
print("---------------------------------------------------"
      +"\nThank you for playing gspyrou's unscramble game!!!")
print("The total times that you have played is: " 
      + str(whole_counter_of_games)
      +"\n---------------------------------------------------")
