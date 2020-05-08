//  Created by Jonathan Riso on 20/11/2019.


#include<iostream>
#include<string>
using namespace std;

/*
  A program that counts the total number of vowels in a sentence.
  Output the frequency of each vowel.

  NOTE: This program does not count y as a vowel.
*/

void vowels(string str){
  //intialising iterator and variables
  string::const_iterator vowelCheck(str.begin());
  size_t pos{0};
  unsigned int Acnt{0},Ecnt{0},Icnt{0},Ocnt{0},Ucnt{0},vowelCnt{0};

  while(pos != string::npos){ // will never be done as function will break before the check.

    pos = str.find_first_of("AEIOUaeiou", pos);
    if (pos == string::npos) {break;} //break is done here to prevent weird errors
    else {vowelCnt++;}

    switch(str.at(pos)){ //Check character at position
      case 'A':
      case 'a':
        ++Acnt;
        break;
      case'E':
      case'e':
        Ecnt++;
        break;
      case'I':
      case'i':
        Icnt++;
        break;
      case'O':
      case'o':
        Ocnt++;
        break;
      case'U':
      case'u':
        Ucnt++;
        break;
      default:
        break;
    }//end of case-switch
    pos++;
  }
  cout<<"String: "<<str<<endl
      <<"Total number of vowels: "<<vowelCnt<<endl
      <<"A: "<<Acnt<<"\tE: "<<Ecnt<<"\tI: "<<Icnt<<endl
      <<"\tO: "<<Ocnt<<"\tU: "<<Ucnt;
}


int main(){
  string str;
  cout<<"Input a string.\n";
  getline(cin,str);
  vowels(str);
  return 0;
}
