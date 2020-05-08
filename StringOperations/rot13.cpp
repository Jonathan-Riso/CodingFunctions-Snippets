//  Rot 13
//  Code
//
//  Created by Jonathan Riso on 20/11/2019.


#include<iostream>
#include<string>
using namespace std;


// The following function will accept a string of characters
// and then return the string rot13 encrypted
// if it receives a rot13 encrypted string it will return
// the Dencrypted string.
string rot13(string name){
  string::iterator rot13{name.begin()};
  while(rot13 != name.end()){
  // 96 & 123 indicate the asccii values for the values right After
  // and before a & z
  if(*rot13>96 && *rot13<123){
      if(*rot13+13<122)  {*rot13 += 13;}
      else  {*rot13-=13;}
    }
  // 64 & 91 indicate the asccii values for the values right After
  // and before A & Z
  else if(*rot13>64 && *rot13<91){
    if(*rot13+13<90)  {*rot13 += 13;}
    else  {*rot13-=13;}
  }
    rot13++;
  }
  return name;
}


int main(){
  string rotted {"Orange, Red, Green, Yellow, Black::TV'1234, TV"}; //testing
  cout<<"Intial String:\t\t\t"<<rotted<<endl;
  rotted=rot13(rotted);
  cout<<"After Rot13 encryption:\t\t"<<rotted<<endl;
  rotted=rot13(rotted);
  cout<<"After Rot13 Dencryption:\t"<<rotted<<endl;
  return 0;
}
