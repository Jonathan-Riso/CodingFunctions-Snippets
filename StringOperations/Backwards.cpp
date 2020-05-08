//  Rewrites a string of characters backwards
// and switches lower case to upper case and vice versa
//  Created by Jonathan Riso on 20/11/2019.


#include<iostream>
#include<string>
using namespace std;


string backwards(string name){
  string newString{""};
  string::iterator swapper{name.end()};//create iterator with inital location at end of String
  while(swapper >= name.begin()){ //loop until the beginning of the string
    char ch;
    if(char(tolower(*swapper))==*swapper) {ch=char(toupper(*swapper));} //if lower case switch to upper case
    else  {ch=char(tolower(*swapper));} //if upper case switch to lower case
    newString.push_back(ch); //at that char to the new string at the end
    swapper--; //update position
  }
  return newString; //return new string
}


int main(){
  cout<<"Input a string.\n";
  string str;
  getline(cin,str);
  cout<<backwards(str);

  return 0;
}
