# BIOSTAT-615
## Statistical Computing Projects

1) <strong>Changing money problem,using Divide and Conquer</strong>

Thefirst line of our output should containthe total number of possible combinations. If the number is positive, starting from the second line, we list all the specific combinations, where the number of bills or coins of each values are printed.

2) <strong>Unscrambler game</strong>

This .py file takes an arbitrary .txt file containing as the input argument and :

•Ask users to specify the length of words that will be picked at random•If the specified word length is invalid, an error message must appear before prompting for a new input.•If no word length is specified, a random word should be chosen from the whole list.•The clue should be a randomly shuffled version of the chosen word, but any valid word that is a permutation of the clue string can be correct answer•All list of correct answers must be displayed after informing correctness of the user’s input. 

3) <strong>Comparison of 4 different versions of Merge Sort Algorithm </strong>

    Task: Construct 4 different versions of the merge sort algorithm, given some predefined functions (or more accurately, given the arguments).
    <br><br/>
    At first, we implemented the version in which we were passing the array, which we wanted to sort, by using a pointer. Secondly, we implemented a merge sort algorithm by passing a value (in our homework program specifically was a vector).Our third function was about merge sort by passing a vector via reference. Finally, the last one was pretty much in the same logic as the third, with only difference that we were also passing by reference a second vector (that helped us to perform the task a little better and faster as we will see later in this discussion).
<br><br/>
    After we built these four functions, we tried to run them given a predefined C++ code  and include the testing of these four algorithms in 12 different cases (where each case was testing the algorithms on a different size each time-the sizes were ranged from 10000 to 50000000.)
