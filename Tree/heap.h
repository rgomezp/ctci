#include "tree.h"

using namespace std;

class min_heap : public tree{
public:
  min_heap(int val) : tree(val){}
  void insert(int val);
  void remove(int val);
  int get_min(){return root->val;}

};

void min_heap::insert(int val){
  node_count++;

  // get parent
  tree_node* parent = find_node_by_id(node_count/2);

  // new node
  tree_node* new_node = new tree_node(node_count, val, NULL, NULL);

  // make sure it is larger
  if(val >= parent->val){
    // add to left
    if(node_count%2 == 0) parent->left = new_node;
    // add to right
    else parent->right = new_node;

  }// rotate
  else{
    
    return;
  }
  cout<<"inserted "<<val<<endl;
};

void min_heap::remove(int val){
  node_count--;
};
