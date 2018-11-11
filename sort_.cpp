#include <Rcpp.h>
#include <iostream>
#include <algorithm>
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]

NumericVector insertion_sort(NumericVector x) {
  
    int n = x.size();
    int tmp_c;
      for(int i = 1; i < n; i++){
        for(int k = i; k>0 ; k--){
          if(x[k-1]>x[k]){
            tmp_c = x[k];
            x[k] = x[k-1];
            x[k-1] = tmp_c;}
          else{
            break;
          }
        }
      }
    return x;
    /* end of the insertion sort algorithm
    * x will return our sorted elements
    */
}


// [[Rcpp::export]]
NumericVector bubble_sort(NumericVector x) {
  int n = x.size();
  bool swapped = true;
  int j = 0;
  int tmp_c;
  while (swapped){
    swapped = false;
    j++;
    for (int i =0; i < n-j ; i++){
      if(x[i] > x[i+1]){
        tmp_c = x[i];
        x[i] = x[i+1];
        x[i+1] = tmp_c;
        swapped = true;
      }
    }
    
  }
  return x;
}


void merge_sort(NumericVector x, int l, int r) {
  if (r - l <= 1){
    return;
  }else{
    
    int mid = ((r + l) / 2 );
    merge_sort(x,l,mid);
    merge_sort(x,mid,r);
    
    NumericVector tmp(x.begin()+l,x.begin()+mid);
    
    int i=0;
    int j=mid;
    int k=l;
    
    while ((i < mid-l) || (j < r)){
      if(i == mid-l){
        x[k] = x[j];
        j+=1;
      }else if( (j==r) || (tmp[i] < x[j])){
        x[k] = tmp[i];
        i+=1;
      }else{
        x[k] = x[j];
        j+=1;
        
      }
      k+=1;
    }
  }
}

  /*one is calling the merge sort algorithm ,while the other one is calling
* the standard case of "Sort"
*/
  
  // [[Rcpp::export]]
NumericVector merge_sort(NumericVector x) {
  // Do not modify this function.
  // This function simply calls the merge_sort function above
  // that uses divide-and-conquer algorithm
  merge_sort(x, 0, (int)x.size());
  return x;
}

// [[Rcpp::export]]
NumericVector std_sort(NumericVector x) {
  // Do not modify this function.
  // This function uses std::sort() function to perform sorting
  sort(x.begin(), x.end());
  return x;
}


  
