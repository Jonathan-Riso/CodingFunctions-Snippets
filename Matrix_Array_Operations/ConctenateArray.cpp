// Jonathan Riso ID:40131059
// Q3.cpp
// ---
#include<iostream>
#include<vector>
#include <array>
#include<cstddef>
#include<cstdlib>
#include <ctime>
using namespace std;

unsigned int seed{static_cast<unsigned int>(time(0))};
const size_t n{3},m{5};
const size_t D = 2*m;

int* concatenate(vector<int> v1,vector<int> v2);
array<array<int,2*m>,n> horizontalConcatenation(array<array<int,m>,n> A, array<array<int,m>,n> B);
void showArray(array<array<int,2*m>,n>& ar);
void showArray(array<array<int,m>,n>& ar);
void fillArray(array<array<int,m>,n>& ar);

int main(){
  srand(seed);
  array<array<int,m>,n> A;
  array<array<int,m>,n> B;
  array<array<int,D>,n> C;

  //Fill the matrix with random values
  fillArray(A);
  fillArray(B);
  /////////////////////////////////////

  cout<<"//--------------Matrix A--------------//\n";
  showArray(A);
  cout<<"//--------------Matrix B--------------//\n";
  showArray(B);
  C = horizontalConcatenation(A,B);
  cout<<"//--------------New Matrix--------------//\n";
  showArray(C);

  cout<<endl;
  return 0;
}


/*
  The following function accepts 2 vectors
  and the outputs a pointer to a new array
  that contains the two vectors concatenated
*/
int* concatenate(vector<int> v1,vector<int> v2){
  int arraySize = v1.size()+v2.size(); //the new size of array
  int A[arraySize]; //create built in array
  for(size_t i{0};i<v1.size();i++) A[i] = v1.at(i); //fill the first half with v1
  for(size_t i{0};i<v2.size();i++) A[i+v1.size()] = v2.at(i); //then seccond half with v2
  int* APtr = A; //create the pointer and set it to point at A[0]
  return APtr;
}

/*
  The following function accepts 2 object arrays
  and the outputs a new array that contains the
  arrays concatenated
*/
array<array<int,2*m>,n> horizontalConcatenation(array<array<int,m>,n> A, array<array<int,m>,n> B){

  //Create the nArray that will contain the horizontal concatenation
  array<array<int,2*m>,n> nArray;

  for(size_t i{0}; i<n; i++){ //loop for n rows
    //intialise vectors
    vector<int> v1(m);
    vector<int> v2(m);

    for(size_t j{0}; j<m; j++){
      //fill vectors with the i-th row of array A & B
      v1.at(j) = A[i][j];
      v2.at(j) = B[i][j];
    }//end of first j-loop

    //Now using the vectors above
    for(size_t j{0}; j<2*m; j++){
        //fill the i-th row with the concatenate of v1 & v2
        nArray[i][j] = *(concatenate(v1,v2)+j);//take value at a[j]
      }//end of 2nd j-loop
    }// end of i-loop
    return nArray;
  }

//Following functions are not part of the assignment
//output an array into the console
void showArray(array<array<int,D>,n>& ar){

  for(size_t j=0; j<n; j++){
    for(size_t i=0; i< D; i++){
      cout<<ar[j][i]<<"\t";
    }
    cout<<"\n";
  }
}


void showArray(array<array<int,m>,n>& ar){

  for(size_t j=0; j<n; j++){
    for(size_t i=0; i< m; i++){
      cout<<ar[j][i]<<"\t";
    }
    cout<<"\n";
  }
}

//fill the array with random variables
void fillArray(array<array<int,m>,n>& ar){

  for(size_t j=0; j<n; j++){
    for(size_t i=0; i< m; i++){
      ar[j][i]= (1+rand()%15);
    }
  }
}
