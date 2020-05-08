// The following program searches for the two characters
// by and erases them from the string
//  Created by Jonathan Riso on 20/11/2019.
#include<iostream>
#include<string>
using namespace std;


void eraseBY(string & str){
  	// Erase all by by iterating through the string
    for(size_t pos{0};pos!=string::npos;){
        pos = str.find("by");
      	if (pos != string::npos) {
      		str.erase(pos, 2);
      	}
      }
      //now erase all BY(Upcase)
    for(size_t pos{0};pos!=string::npos;){
        pos = str.find("BY");
      	if (pos != string::npos) {
      		str.erase(pos, 2);
      	}
      }
}


int main(){
  string str;
  cout<<"Input a string.\n";
  getline(cin,str);
  eraseBY(str);
  cout<<str;

  return 0;
}
