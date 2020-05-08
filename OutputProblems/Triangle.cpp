//  Hollow triangle Stars(For n=<40)
//  Created by Jonathan Riso on 30/09/2019.

#include <iostream>
using namespace std;

int main(){

  // ask user to input the number of Rows
  cout<<"Input the number of rows (Positive Intergers Only): ";
  int n{0};
  cin>>n;

  for (int i=1;i<=n; i++){ //Loop untill i>n, so that n rows are filled out.
    if (i<3 || i == n){    // do not add spaces at line 1,2 and the final line
      for (int j=1; j<=i; j++){
          cout<<"* ";
        } // end of for loop
      } //end of IF

      else{ //Add 1 start at the beginning and end and spaces in between
          cout<<"* ";
          for (int j=1; j<=i-2; j++)
              cout<<"  ";
          cout<<"*";
        }// end of second for loop

      cout<<endl; //before new loop go to new line

    }// end of first for loop
  return 0;
}
