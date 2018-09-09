# BIOSTAT-615
## Statistical Computing Projects

1) <strong>Changing money problem,using Divide and Conquer</strong>  (coin change problem.py)

    Thefirst line of our output should containthe total number of possible combinations. If the number is positive, starting from the second line, we list all the specific combinations, where the number of bills or coins of each values are printed.

2) <strong>Unscrambler game</strong> (gspyrou_unscrambler.py)

This .py file takes an arbitrary .txt file containing as the input argument and :

    •Ask users to specify the length of words that will be picked at random
    •If the specified word length is invalid, an error message must appear before prompting for a new input.
    •If no word length is specified, a random word should be chosen from the whole list.
    •All list of correct answers are displayed after informing correctness of the user’s input. 

3) <strong>Comparison of 4 different versions of Merge Sort Algorithm </strong> (sorting_algor.cpp)

    Task: Construct 4 different versions of the merge sort algorithm, given some predefined functions (or more accurately, given the arguments).
    <br><br/>
    At first, we implemented the version in which we were passing the array, which we wanted to sort, by using a pointer. Secondly, we implemented a merge sort algorithm by passing a value (in our homework program specifically was a vector).Our third function was about merge sort by passing a vector via reference. Finally, the last one was pretty much in the same logic as the third, with only difference that we were also passing by reference a second vector (that helped us to perform the task a little better and faster as we will see later in this discussion).
<br><br/>
    After we built these four functions, we tried to run them given a predefined C++ code  and include the testing of these four algorithms in 12 different cases (where each case was testing the algorithms on a different size each time-the sizes were ranged from 10000 to 50000000.)
   
Time Complexity Plot after the simulations:

![alt text](https://github.com/gpsyrou/BIOSTAT-615/blob/master/alg_pc.png)
<br><br/>
By looking at the graph provided, we can separate the algorithms into two “groups” of time complexities.
At first is the group that seems to run in Θ(n^2) time which consists of the algorithms Insertion Sort and Bubble Sort, as they both appear to run in a quadratic complexity time – i.e. quadratic form ( we can easily infer by looking at the graph that their time complexity to run the algorithm increases a  lot  as the size of the data is getting bigger).They are both considered bad algorithms for huge amounts of data-although they might be useful for certain small amounts.
<br><br/>
The second group consists of the algorithms that run in Θ(n*log n) time and are the algorithms Merge Sort, Std Sort and Sort. Merge sort is splitting the data in halves and that is the reason that we are having ‘logn’ for this algorithm, while the ‘n’ is coming from the fact that the sorted halves have to merge eventually. Further, std sort and sort are using a hybrid type of algorithm (we will discuss it in more detail later is this report), which is using the techniques and advantages of divide and conquer (by splitting in halves the arrays, etc) but in a more optimized way than the merge sort algorithm. We have to note that for these two algorithms, the reasons we have ‘logn’ and ‘n’ are a bit different than in merge sort, as as we said they are hybrid algorithms. Nevertheless this is true, we won’t say much about them as we didn’t focus on them in the lectures-but we can underline that they are different in construction compared to merge sort as they are using alternative methods like pivot to partition their lists (although they might split in halves like the merge sort but not always). Thus, if we consider all these we can understand why they look like this in the graph (they don’t increase their complexity rapidly like the n^2 algorithms do-we can say they are “smoother’’ compared to the first group of n^2 algorithms).Informally, we can say that they follow logarithmic form, but as they are multiplied with ‘n’ we end up with the lines as they appear in the graph).
<br><br/>
 Finally we have to compare the computational time of these algorithms but this time it terms of the group in which they belong and how different they are from algorithms in the same group.
Θ (n^2 ) – group:
 	We can see that the bubble sort algorithm is performing worse than the insertion sort algorithm. Except the very first case (the smallest data) in which they both performed at the same time, after that the insertion sort algorithm performed faster in all the rest of the cases. Interesting fact also, is that the bubble sort operated 7 times out of 12 and insertion sort performed 8 times out of 12.This happened because we had a threshold at 10 seconds- and so if the previous attempt was more than these 10 seconds then we were terminating our task for this specific algorithm. Therefore, insertion sort stayed under the threshold for one more simulation than the bubble sort. This worse performance for bubble sort can be accounted to the fact that this algorithm performs by “swapping” the elements, while insertion sort not.
    <br><br/>
	Θ (n*logn) - group:
For this group we can see that all three of them perform the same for small amounts of data. While the data is getting larger we see that Merge sort is starting to perform slower(approximately at the 5th-6th iteration) than the other two algorithms (std sort and sort).This is happening due to the fact that merge sort is a divide and conquer algorithm which is using recursion that makes it slower, while the algorithms std_sort and sort don’t have a specific algorithm type , as they are predefined in the build-in libraries of C++(std::sort) and R(sort).Specifically, std sort and sort are usually using a hybrid type of algorithms(for example in C++ std::sort is using introsort which is a hybrid of quicksort and heapsort) in order to perform the sorting , with only requirement to perform at Θ(n*logn), but they are still performing better than merge sort for the aforementioned reason. Finally, between std sort and sort, we are comparing between two build in functions for sorting and their differences are small but significant. We can see from the plot and the data that we received from our analysis,that std sort performs better in general than the sort algorithm for all of the iterations that we performed, and as the data was getting bigger we observed that fact by looking at the computational time for each of them.Specifically, from the 5th iteration of the sort algorithm, the time complexity started having big differences(it started performing slower), compared to the time that std sort was performing for the respective amounts of data.



4) <strong> Comparison of 3 famous sorting algorithms: Bubble Sort, Merge Sort, Insertion Sort  and test them against some predefined c++ sorting algorithms </strong> (sort_.cpp)
