
#include <iostream>
#include <cassert>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <vector>

using namespace std;



template <typename T>
void insertionsort(T values,int size){
    for( int p = 1; p < size; ++p ){
        int tmp = values[ p ] ;
        int j;
        for( j = p; j > 0 && tmp < values[ j - 1 ]; --j )
        values[ j ] =  values[ j - 1 ] ;
        values[ j ] = tmp ;
    }
}

int Partition(int arr[], int left, int right){
    int pivot = arr[left];
    int L = left;
    for(int i = left+1; i < right ; i++){
        if(arr[i] < pivot){
            L = L+1;
            std::swap(arr[i],arr[L]);
        }
    } 
    std::swap(arr[L],arr[left]);
    return L;
}
void quicksort(int intvector[],int L, int R){
    if (L < R){
       int q = Partition(intvector,L,R);
        quicksort(intvector,L,q);
        quicksort(intvector,q+1,R);
    }
}

 
// short integer random number generator from stdlib
int rand(void); 


int main()
{ 
  int test1[]= {5,3,4,1,6,7,8,9,10,100,200,300,5,6};
  int test2[] = {5,3,4,1,6,7,8,9,10,100,200,300,5,6};
  int size;
  //hrtime_t start, total;  // defined in sys/time.h  long long int
  timeval start, end; // type defined in sys/time.h.
  double start_sec, end_sec, t_sec;

  //double t_sec;

  cout << endl << " ----- insertion/quicksort comparison ----- " << endl;
  cout << endl << "How many elements to sort: - ";  cin >> size;
  int* dataArray = new int [size];   // get array of right size
  int* copyArray = new int [size];   // to hold a copy of random ints
  assert ( (dataArray != NULL) && (copyArray != NULL) );

  //  ============ insertion sort random integers  ===================

  for (int k=0; k< size ; k++)  dataArray[k] = rand();

  // copy the array for later use by quicksort
  for (int k=0; k< size ; k++)  copyArray[k] = dataArray[k];

  cout << endl << "Insertion sort of Integer data initially in random order" << endl;

  //start = gethrtime();   // hi_resolution time nanoseconds

  gettimeofday(&start, NULL);  // get time at start of function


  // implement your insertionSort here or call it as a function
  //   =====================InsertionSort===============
  
    insertionsort(dataArray,size);
  //   You can refer Mark Allan Weiss Third Edition Figure 7.2 page 263. 4th Edition Figure 7.2 page 293

  gettimeofday(&end, NULL);  // get time at end of function
  // convert to seconds and print out
  start_sec = double(start.tv_sec) + double(start.tv_usec) * 1e-6;
  end_sec = double(end.tv_sec) + double(end.tv_usec) * 1e-6;
  t_sec = end_sec - start_sec;

  //total = gethrtime() - start;
  //t_sec = double(total) * 1.0e-9;  // convert to seconds
  cout << "For N = " << size << " # seconds = " << t_sec << "\n";

  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << dataArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << dataArray[size-k] << ", " ;
  cout << endl << endl;

  //  ============ quicksort random integers  ===================

  cout << endl << "quicksort of Integer data initially in random order" << endl;

  //start = gethrtime();   // hi_resolution time nanoseconds
  gettimeofday(&start, NULL);  // get time at start of function


  // implement your quicksort here or call it as a function
  // =====================Quicksort ======================
   quicksort(copyArray, 0 ,size);
  // you can refer Mark Allan Weiss Third Edition Figure 7.16 page 286; 4th Edition Figure 7.17 on page 317. Note that this piece 
  // of code only use quick sort when the input has size at least 10. Please only implement 
  // the quicksort part no matter how large the input is. 


  gettimeofday(&end, NULL);  // get time at end of function
  // convert to seconds and print out
  start_sec = double(start.tv_sec) + double(start.tv_usec) * 1e-6;
  end_sec = double(end.tv_sec) + double(end.tv_usec) * 1e-6;
  t_sec = end_sec - start_sec;

  //total = gethrtime() - start;
  //t_sec = double(total) * 1.0e-9;  // convert to seconds
  cout << "For N = " << size << " # seconds = " << t_sec << "\n";

  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << copyArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << copyArray[size-k] << ", " ;
  cout << endl << endl;

//    insertionsort(test1,14);
//    
//  for (int i= 0; i<=13 ;i++ ){
//      cout<<test1[i]<<",";
//  }
//    
//    
//cout<<endl;
//
//    quicksort(test2,0,14);
//  for (int i= 0; i<=13 ;i++ ){
//      cout<<test2[i]<<",";
//  }
//    
//    
}







