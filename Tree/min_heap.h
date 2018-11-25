#include "tree.h"

using namespace std;

class min_heap : public tree{
public:
  min_heap(int val) : tree(val){}
  void insert(int val);
  void remove(int val);
  int get_min(){return root->val;}
  void bubble_up(tree_node * node, tree_node * parent);
};

/*
    2    replace 1 with 4

  4 |
 / \
5   1
*/

void min_heap::bubble_up(tree_node * new_node, tree_node* parent){

}

void min_heap::insert(int val){
  node_count++;

  // get parent
  tree_node* parent = find_node_by_id(node_count/2);

  // new node
  tree_node* new_node = new tree_node(node_count, val, NULL, NULL, parent);

  // make sure it is larger
  if(val >= parent->val){
    // add to left
    if(node_count%2 == 0) parent->left = new_node;
    // add to right
    else parent->right = new_node;

  }// rotate
  else{
    // bubble up
    bubble_up(new_node, parent);
    return;
  }
};

void min_heap::remove(int val){
  node_count--;
};
