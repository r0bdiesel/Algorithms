//   test driver for heap, ignores index 0

#include <iostream>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <vector>

using namespace std;

// short integer random number generator from stdlib
int rand(void); 

void Heapify(vector <int>& vec,int i){
   int smallest;
   int l=i*2;
   int r= i*2+1;
   if (l <= vec.size()-1 and vec[l] < vec[i]){
       smallest =l;
   }
   else{
       smallest =i;
   }
   if (r <= vec.size()-1 and vec[r] < vec[smallest]){
       smallest =r;
   }
   if (smallest != i){
       swap(vec[i],vec[smallest]);
       Heapify(vec,smallest);
   }
}

void buildheap(vector <int>& vec){
    for(int i=floor(vec.size()/2);i>=1;i--){
        Heapify(vec,i);
    }
}
void Heapinsert(vector <int>& vec,int key){
    vec.push_back(key);
    int i = vec.size();
    int parenti = floor(i/2);
    while( (i>1) and (vec[parenti] > key) ){
        vec[i] = vec[parenti];
        i = parenti;
    }
    vec[i] = key ;
}

int main()
{ 
  int size;
  cout << endl << "How many elements in the input array ";  cin >> size;
  int* dataArray = new int [size + 1];   // get array of right size (with invisible 0th element)
  
  // fill array -- fill 0th element but don't show it.
  for (int k=0; k< size+1 ; k++)  dataArray[k] = rand();
  cout<<"Input array:\n";
  for (int k=1; k<size+1; k++)
    cout<<dataArray[k]<<" ";
  cout<<endl;

  // ============= implement your code here or call it as a function======
  // you may assume that the variable size is the correct size of the array
  // (even though it's not) for heap-building purposes
  // build a heap for dataArray
  vector<int> vec;
//  vector<int> vec1;///correct order of test vec1 should be 124356
//  vec1.push_back(100);
//  vec1.push_back(6);
//  vec1.push_back(5);
//  vec1.push_back(4);
//  vec1.push_back(3);
//  vec1.push_back(2);
//  vec1.push_back(1);
//  
  for (int k=0; k<size+1; k++){
      vec.push_back(dataArray[k]);
  }
  buildheap(vec);
  
  //show heap (but not ignored 0th element)
  cout<<"Heap built from the input array:\n";
  for (int k=1; k<size+1; k++)
    cout<<vec[k]<<" ";
  cout<<endl;

  
}


