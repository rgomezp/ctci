#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* GOAL: find quadruplet in vector that sums to given number
 */

vector<int> arrquad(vector<int>& arr, int s){
  // brute force
  vector<int> ret;
  // sliding window
  for(int i=0; i<arr.size()-3; i++){
    if(arr[i]+arr[i+1]+arr[i+2]+arr[i+3] == s){
      ret.push_back(arr[i]);
      ret.push_back(arr[i+1]);
      ret.push_back(arr[i+2]);
      ret.push_back(arr[i+3]);
      return ret;
    }
  }
  int size = ret.size();
  if(size == 0){
    for(int i=0; i<=arr.size()-4; i++){
      for(int j=i+1; j<=arr.size()-4+i; j++){
        for(int x=j+1; x<=arr.size()-4+j; x++){
          for(int y=x+1; y<=arr.size()-4+x; y++){
            int sum = arr[i]+arr[j]+arr[x]+arr[y];
            if(sum == s){
              ret.push_back(arr[i]);
              ret.push_back(arr[j]);
              ret.push_back(arr[x]);
              ret.push_back(arr[y]);
              return ret;
            }
          }
        }
      }
    }
  }
  return ret;
}

int main(){
  vector<int> input;
  input.push_back(5);
  input.push_back(4);
  input.push_back(3);
  input.push_back(2);
  input.push_back(3);
  input.push_back(1);

  vector<int> ret = arrquad(input, 10);
  for(int i=0; i<ret.size(); i++){
    cout<<ret[i]<<',';
  }
  return 0;
}
