#include <iostream>
#include <string>
#include "min_heap.h"

using namespace std;

void foo(tree_node* node){
  cout<<node->val<<',';
}

int main(){
  min_heap* my_heap = new min_heap(1);
  int tree_vals[] = {3,2,4,6,5,4,7,9,10,13,25,27,17,1};
  for(int i=0; i<14; i++){
    my_heap->insert(tree_vals[i]);
    //my_heap->bfs_print();
  }
  tree_node* root = my_heap->get_root();
  my_heap->iot(root, *foo);
  cout<<endl;
  my_heap->preot(root, *foo);
  cout<<endl;
  my_heap->postot(root, *foo);
  my_heap->bfs_print();
  cout<<"ancestor:"<<my_heap->find_ancestor(8,9)->id<<endl;

  return 0;
}
