// Jonathan Riso
/*
  accepts a built in array, the size of the build in array
  and a threshold value, it will then return thea pointer to
  the location of the array of a new size that has values below
  the threshold in ascending and then descending order.
*/
// ---

#include<iostream>
#include<cstddef>
#include<cstdlib>
#include<iterator>
using namespace std;

long* thresholdAscDes(long A[],long N,long threshold);

int main(){

  //ask user to input the size of the array
  long N{0};
  do{
      cout<<"Please input the size of the array\n(decimals will be rounded down): ";
      cin>>N;
      if(N<=0) cout<<"The Array size cannot be less than or equal to zero.\n\n";
  }while(N<=0);

  long A[N]; // create the array and intialise it.
  for(long i{0};i<N;i++) A[i] = 0;

  //Ask user to input the values of the Array
  cout<<"Input all "<<N<<" interger values.\n";
  for(long j{0}; j<N; j++){
    cout<<"A["<<j<<"]= ";
    cin>>A[j];
    cout<<endl;
  }

  //Ask user to input the threshold value
  cout<<"Input the threshold value?\n"
      <<"Numbers above the threshold value will be removed from the array.\n"
      <<"Threshold Value = ";
  long threshold{0};
  cin >> threshold;

  //determins size of new array
  long cnt{0};
  for(long i{0}; i<N; i++){
    if(A[i]<=threshold) cnt+=2;
  }

  //loop through the pointer to the new array to get te values.
  for(int i{0};i<cnt;i++) cout<<*(thresholdAscDes(A,N,threshold)+i)<<" ";
  cout<<endl;
  return 0;
}

/*
  accepts a built in array, the size of the build in array
  and a threshold value, it will then return thea pointer to
  the location of the array of a new size that has values below
  the threshold in ascending and then descending order.
*/
long* thresholdAscDes(long Array[],long N,long threshold){

  //1. determin size of new array
  long cnt{0};
  for(long i{0}; i<N; i++){
    if(Array[i]<=threshold) cnt+=2;
  }

  //Create New array of new size and intialise
  long Arr[cnt];
  for(long i{0};i<cnt;i++) Arr[i] = 0;

//------------------------------------------------//

  //2.place all the values below the threshold
  // into the new Array
  long k{0};
  for(long i{0};i<N;i++){
    if (Array[i]<= threshold) Arr[k++] = Array[i];
    else continue;
  }

//--------------------------------------------------//

  //3. sort in ascending order
  for(long i{0};i<cnt/2;i++){
    for(long j{i+1}; j<cnt/2; j++){
      if(Arr[i]>Arr[j]){
        long hold = Arr[j];
        Arr[j] = Arr[i];
        Arr[i] = hold;
      }// end of if
    }// end of j-for
  }// end of i-for

//------------------------------------------------//

 //4.  input into Array in reverse order
 for(long i{0}; i<cnt/2; i++){
   Arr[(cnt/2) + i] = Arr[cnt/2-i-1];
 }

  /*
   //outputs the entire array.
   cout<<"New Array is: ";
   for(int i{0};i<cnt;i++) cout<<Arr[i]<<" ";
   cout<<endl;
  */

 //return the address the pointer is pointing at
 long* ArrPTR = &Arr[0];
 return ArrPTR;
}
