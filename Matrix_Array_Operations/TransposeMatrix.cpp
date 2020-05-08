// Jonathan Riso ID:40131059
// Q1.cpp
// ---
#include<iostream>
#include<array>
#include<cstddef>
#include<cstdlib>
using namespace std;

const size_t N{3};

void transposeMatrix(array<array<int, N>,N>& ar);
void swapColumns(array <array<int, N>, N>& ar);
void showArray(array<array<int,N>,N>& ar);
void fillArray(array<array<int,N>,N>& ar);

int main(){
  srand(5); //set seed for random numbers in matrix
  array <array<int, N>, N> test; //create test
  fillArray(test); //fill the matrix and display it
  cout<<"=========================\n"; //seperator
  transposeMatrix(test); // first transpose
  swapColumns(test); // then swap the swap columns
  showArray(test); // output new array

  return 0;
}

void transposeMatrix(array <array<int, N>, N>& ar){

  //Halftime is the var that ensures the matrix does not transpose a variable twice
  size_t halftime{0};
  for(size_t r{0}; r<N; r++){
    for(int c{N-1}; c>=0; c--){ //we increment backwards so that our if-break state doesn't always occur
      //escape c-loop if we must not transpose the next variables
      if(c==halftime && halftime!=0) break;
      if(r!=c){
        int hold = ar[r][c]; //store one of the vars
        ar[r][c] = ar[c][r]; // swap 1
        ar[c][r] = hold; // swap 2
      }// end of if
    }// end of c-loop
    halftime +=1; // in order to prevent doing the same swap twice,
  }// end of r-loop
}

void swapColumns(array <array<int, N>, N>& ar){
  for(int c{0}; c<N/2; c++){ //do only for half N so we do not swap twice
    for(int r{0}; r<N; r++){
      int hold = ar[r][c];
      ar[r][c] = ar[r][N-1-c];
      ar[r][N-1-c] = hold;
    }
  }
}



// not part of the question but this accepts an array and fills it with random numbers
void fillArray(array<array<int,N>,N>& ar){

  for(size_t j=0; j<N; j++){
    for(size_t i=0; i< N; i++){
      ar[j][i]= (1+rand()%15);
      cout<<ar[j][i]<<"\t";
    }
    cout<<"\n\n\n";
  }
}

//displays the passed array
void showArray(array<array<int,N>,N>& ar){

  for(size_t j=0; j<N; j++){
    for(size_t i=0; i< N; i++){
      cout<<ar[j][i]<<"\t";
    }
    cout<<"\n\n\n";
  }
}
