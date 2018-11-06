#include <map>
#include <string>
#include <iostream>

using namespace std;

bool palPerm(string& str){
  map<char,int> char_map;
  for(int i=0; i<str.length(); i++){
    if(char_map[str[i]]) char_map[str[i]]++;
    else char_map[str[i]] = 1;
  }

  // iterate through all keys
  int odd_count = 0;
  for(map<char, int>::iterator it=char_map.begin(); it!= char_map.end(); ++it){
    // odd counts > 1, not palindrome
    if(it->second%2 != 0) odd_count++;
  }
  if(odd_count > 1) return false;
  else return true;
}

bool test(bool& test, bool& val){
  return test == val;
}

int main(){
  string test_strings[7] = {"a", "aa", "aab", "aabb", "aacb", "cbacb", "cbdefg"};
  bool test_results[7] = {true, true, true, true, false, true, false};
  for(int i=0; i<7; i++){
    bool res = palPerm(test_strings[i]);
    cout<<(bool)test(res, test_results[i])<<endl;
  }
  return 0;
}
