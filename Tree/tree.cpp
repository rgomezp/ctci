#include <iostream>
#include <string>
#include "heap.h"

using namespace std;

int main(){
  min_heap* my_heap = new min_heap(1);
  int tree_vals[] = {3,2,4,6,5,4,7,9,10,13,25,27,17,4};
  for(int i=0; i<14; i++){
    cout<<"inserting "<<tree_vals[i]<<endl;
    my_heap->insert(tree_vals[i]);
    my_heap->bfs_print();
  }

  return 0;
}
