from __future__ import print_function

# proper file reading into the terminal with the args
import sys
#read the argumets i.e the amount of money we want to divide and the denominations
input_amount = float(sys.argv[1]) # will be the amount we want to set as our goal
denomination_amounts = sys.argv[2:] # the denominations we will use
denomination_amounts = list(map(float,denomination_amounts[0:]))

coins_n_bills = [] # empty list we will use
itter_c = 0 # it will count some of our itteration/useful for total possible ways
blank_list = [] # list - combinations of coins/bills 
checking_ = True # it will check if we used float numbers

# first we do a check if any of the inserted values is coins / i.e. float numbers
# and thus if any is float we "transform" them to int like below
if  all(type(item)==int for item in denomination_amounts) == False:
    denomination_amounts = [i * 100 for i in denomination_amounts]
    input_amount = input_amount * 100
    checking_ = False # so we can use the proper method

# now we define  two functions that will execute our recursion method
# after this we will have all the combos for the sum of money we want to examine
def coin_bill_recursion(coins_n_bills, denomination_amounts, 
                        the_max, sum, input_amount):
    # recursion goal / we are checking if we are okay 
    if sum == input_amount:
        show_and_count(coins_n_bills, denomination_amounts)
        return

    if sum > input_amount:
        return

    for value in denomination_amounts:
        if value >= the_max:
            #  we append the current value to our "copy" list
            copy = coins_n_bills[:]
            copy.append(value)
           
            # and using recursion we are adding more coins/bills
            coin_bill_recursion(copy, denomination_amounts, value, 
                                sum + value, input_amount)
            
# the second function will be used for display purposes as well as to
# count the total amount of different combinations
def show_and_count(coins_n_bills, denomination_amounts):
    for amount in denomination_amounts:
         count = coins_n_bills.count(amount)
         global itter_c
         itter_c += 1 # help to calculate final # of combos
         blank_list.append((amount,count))


# our initial recursive call  / generates the rest of the functions
coin_bill_recursion(coins_n_bills, denomination_amounts, 0,0,input_amount)

# finally now that we have our data,lists etc, we are able to print the
# results that the homework is asking 

# this will operate only if we didnt have any coins 
#as our initial denomination values i.e. only if all the denominations we
#asked from the program as inputs were  integers
if checking_ == True:
    print("There are " + str(itter_c/len(denomination_amounts))+
          " possible ways to make " + str(input_amount))

    for i in range(len(blank_list)):
        print('{"%s"'%blank_list[i][0], ": "+ str(blank_list[i][1])+" times}",end = "")
        if (blank_list[i][0] == denomination_amounts[-1]):
            print("")
# on the other hand this will give us the results 
#if we can float values as inputs /  i.e we used coins ( like 0.25,0.10 etc)
if checking_ == False:
    print("There are " + str(itter_c/len(denomination_amounts))+
          " possible ways to make " + str(input_amount/100))
    
    for i in range(len(blank_list)):
        print('{"%s"'%(blank_list[i][0]/100), ": " + str(blank_list[i][1])+" times}",end ="")
        if (blank_list[i][0] == denomination_amounts[-1]):
            print("")

