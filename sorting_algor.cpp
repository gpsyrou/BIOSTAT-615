
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;


void merge_sort_array(int* v, int l, int r) {
  
  if (l > r-2) return;/* the end of the recursive call*/
  else {
    int mid = (l+r)/2;
    if (l < mid) { 
      merge_sort_array(v, l, mid); /*here we have the two recursive calls*/
    }
    if (mid < r) { 
      merge_sort_array(v, mid, r); /* for the two splitted parts*/
    }
    
    if (l < mid) {
      /* we are using new so i have to delete it
      * at the end
      */
      int* tmp = new int[l+r]; /*new allocates a storage space (here is equal to l+r)*/
      /*copy will allow us to specify a range that we want from V
      * and copy it and make it the range of tmp that we created above
      */
      copy(v+l,v+mid,tmp); /*we can't use .begin() here*,but v+l and v+mid is fine to define the range*/
      
      int j=mid; /*initialize some variable that we will use*/
      int i=0;
      int itt =l;
      
      while((mid > i+l) || (r > j)) {
        if ( i+l == mid )
          v[itt++] = v[j++];
        else if (( j == r) || ( tmp[i] < v[j]))
          v[itt++] = tmp[i++];
        else
          v[itt++] = v[j++];
        
        
      } 
      delete[] tmp; /* we are deleting the temporary tmp variable*/
    }
    
  }
  
  
}



vector<int> merge_sort_value(vector<int> v){
  /*its not a void function, so i have to return something
  * at the end ( it will be the sorted)
  */
  
  if(v.size() == 1)  /* this is our termination condition*/
  {  
    return v;  
  }  
  
  /*now we are finding the mid element of the vector(mid)*/
  vector<int>::iterator mid = v.begin() + (v.size() / 2);
  vector<int> l(v.begin(), mid);  /*we relevant-copy from the vector 'v' */
  vector<int> r(mid, v.end());
  
  /*recursion calls for l and r*/
  l = merge_sort_value(l);  
  r = merge_sort_value(r); /*thus we performing merge sort to these two smaller vectors*/
  
  vector<int> sort_perm_V;  
  unsigned it_l = 0, it_r = 0;  
  /*now we are going to push the data to the proper vectors
  * so we can end up to the sorted version of the vector
  * that we want
  */
  while(it_l < l.size() && it_r < r.size())  
  {  
    
    if(l[it_l] < r[it_r])  
    {  
      sort_perm_V.push_back(l[it_l]);  
      it_l++;  
    }  
    else  
    {  
      sort_perm_V.push_back(r[it_r]);  
      it_r++;  
    }  
  }  
  
  while(it_l < l.size())  
  {  
    sort_perm_V.push_back(l[it_l]);  
    it_l++;  
  }  
  
  while(it_r < r.size())  
  {  
    sort_perm_V.push_back(r[it_r]);  
    it_r++;  
  }  
  
  return sort_perm_V; /* we return the sorted version*/
  
}


void merge_sort_ref(vector<int>& v, int l, int r) {
  /*this version is pretty similar to the one 
  * that we used for homework 1-Here we are sorting vector
  * by passing with reference
  */
  
  /*end of recursion*/
  if (l > r-2) return;
  else {
    
    int mid = (l+r)/2; /*split the vector in two halves / this will help us*/
  
  /*recursive calls following:*/
  if (l < mid) { 
    merge_sort_ref(v, l, mid); 
  }
  if (mid < r) { 
    merge_sort_ref(v, mid, r); 
  }
  
  
  if (l < mid) {
    /*the only difference with homework 1 is in this line
    * we define a vector<int>  instead of NumericVector.Note
    * that we define every time a new vector.
    */
    vector<int> tmp(v.begin()+l, v.begin()+mid);/* similar logic with hw1,we
    just specify the range that we want*/
    
    int j=mid; /* initialization of variables*/
    int i=0;
    int itt =l;
    
    while((mid > i+l) || (r > j)) {
      if ( i+l == mid )
        v[itt++] = v[j++];
      else if (( j == r ) || (tmp[i] < v[j]))
        v[itt++] = tmp[i++];
      else
        v[itt++] = v[j++];
      
      
    }
  }
  }
  /* in this one we didnt use temporary memory*/
}




void merge_sort_ref_tmp(vector<int>& v, int l, int r, vector<int>& tmp) {
  /*here we have two vectors passed by reference, and l,r */
  
  if (l > r-2) return; /*end of recursion*/
  else {
    int mid = (l+r)/2; /*we find the mid again so we can spit the vector*/
  if (l < mid) { 
    merge_sort_ref_tmp(v, l, mid,tmp); 
  }
  if (mid < r) { 
    merge_sort_ref_tmp(v, mid, r,tmp); 
  }
  
  if (l < mid) {
    /*now i am selecting a specific range for "tmp" coming from "v"
    * we want from the begining of v to the mid
    */
    vector<int> tmp(&v[l],&v[mid]);/* a small trick to split the data as we said
    we use a vector constructor as above*/
    
  
    int j=mid; /*initialize variables as before*/
    int i=0;
    int itt = l;
    
    while(( mid > i+l) || (r > j )) {
      if ( i+l == mid )
        v[itt++] = v[j++];
      else if (( j == r ) || ( tmp[i] < v[j]))
        v[itt++] = tmp[i++];
      else
        v[itt++] = v[j++];
      
      
    } /*Merge_sort_ref_tmp has the same logic as the merge_sort_ref one BUT this 
     one will run faster as we are using a reference for tmp
    which is a little more useful in terms of memory usage.*/
  }
  }
}





int main(int argc, char** argv) {
  // setting a random seed (details will be covered later in class)
  srand(time(NULL)); 
  
  // print out headers
  cout << "Size\tMethod\tMin\tMax\tTicks\tSecs" << endl;
  
  for(int argi = 1; argi < argc; ++argi) {
    // parse the first input argument as a decimal number
    int sz = strtol(argv[argi],NULL,10);
    
    
    int* v1 = new int[sz]; // array for merge_sort_array
    vector<int> v2(sz);    // vector for merge_sort_value
    vector<int> v3(sz);    // vector for merge_sort_ref
    vector<int> v4(sz);    // vector for merge_sort_ref_tmp
    vector<int> tmp(sz);
    // assign same values for all arrays/vectors    
    for(int i=0; i < sz; ++i)
      v1[i] = v2[i] = v3[i] = v4[i] = rand();
    
    // sorting int* array    
    clock_t t = clock();          // store current clock
    merge_sort_array(v1, 0, sz);
    t = clock() - t;              // evaluate the number of clocks spent
    cout << sz << "\tArray\t" << v1[0] << "\t" << v1[sz-1] << "\t" << t << "\t" << (double)t/CLOCKS_PER_SEC << endl;
    
    // sorting vector<int> using pass-by-value    
    t = clock();
    v2 = merge_sort_value(v2);  // beware that no extra arguments exist, and it returns a vector (because it is call by value) 
    t = clock() - t;
    cout << sz << "\tValue\t"<< v2[0] << "\t" << v2[sz-1] << "\t" << t << "\t" << (double)t/CLOCKS_PER_SEC << endl;
    
    // sorting vector<int> using pass-by-reference    
    t = clock();
    merge_sort_ref(v3, 0, sz);
    t = clock() - t;
    cout << sz << "\tRef\t"<< v3[0] << "\t" << v3[sz-1] << "\t" << t << "\t" << (double)t/CLOCKS_PER_SEC << endl;
    
    // sorting vector<int> using pass-by-reference + temporary space    
    t = clock();
    merge_sort_ref_tmp(v4, 0, sz, tmp);
    t = clock() - t;
    cout << sz << "\tRef+Tmp\t" << v4[0] << "\t" << v4[sz-1] << "\t" << t << "\t" << (double)t/CLOCKS_PER_SEC << endl;
  }
  
  return 0;
}
