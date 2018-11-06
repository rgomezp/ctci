#include <iostream>

using namespace std;

void doubleArray(string& str){
  string newArray = "zzzzzzzzzzzzzzz";
  for(int i=0; i<str.size(); i++){
    newArray[i] = str[i];
  }
  str = newArray;
}

void shift(int start, string& str){
  cout<<"shifting"<<endl;
  for(int i=str.length(); i>=start+2; i--){
    str[i] = str[i-2];
  }
}

void URLify(string& str){
  for(int i=0; i<str.size(); i++){
    if(str[i] == ' '){
      shift(i, str);
      str[i] = '%';
      str[i+1] = '2';
      str[i+2] = '0';
    }
  }
}

int main()
{
    string str = "my name is jonas      ";
    URLify(str);
    cout<<str<<endl;
    return 0;
}
