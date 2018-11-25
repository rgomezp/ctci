#include "ll.h"

int main(){
  sll list = sll(1);

  int arr[] = {2,3,4,5,6,7,8,9,10};

  for(int i=0; i<9; i++){
    list.insert(arr[i]);
  }

  list.print_list();
  return 0;
}
