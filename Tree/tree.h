#include <math.h>
#include <queue>
using namespace std;

struct tree_node{
  tree_node(int id, int val, tree_node* left, tree_node* right):id(id),val(val),left(left),right(right){}
  int id;
  int val;
  tree_node* left;
  tree_node* right;
};

class tree{
protected:
  tree_node* root;
  int node_count;
public:
  tree(int val):node_count(1){
    root = new tree_node(1, val, NULL, NULL);
  }
  tree_node* get_root(){return root;}

  // traversals
  void iot(tree_node* node, void (*ptr)(tree_node* node));
  void preot(tree_node* node, void (*ptr)(tree_node* node));
  void postot(tree_node* node, void (*ptr)(tree_node* node));

  // miscellaneous functions
  tree_node* find_node_by_id(int id);
  void bfs_print();
  tree_node* find_ancestor(int id1, int id2);
};

string direction(int id, int node_id){
  // id is target id
  // node_id is current node id

  // is within one level
  if(id/2 == node_id){
    if(id%2==0) return "left";
    else return "right";
  }

  return direction(id/2, node_id);
}

tree_node* node_finder(int id, tree_node* node){
  if(node->id == id) return node;

  if(direction(id, node->id)=="right"){
    return node_finder(id, node->right);
  }
  if(direction(id, node->id)=="left"){
    return node_finder(id, node->left);
  }
  else cerr<<"Something went wrong"<<endl;
}

tree_node* tree::find_node_by_id(int id){
  return node_finder(id, root);
}

// --------- BFS PRINT ---------
void tree::bfs_print(){
  queue<tree_node*> node_queue; // queue to add nodes to
  node_queue.push(root);

  cout<<"------TREE--------"<<endl;
  while(!node_queue.empty()){
    // dequeue and enqueue children
    tree_node* node = node_queue.front();
    node_queue.pop();

    if(node->left) node_queue.push(node->left);
    if(node->right) node_queue.push(node->right);

    // print node
    cout <<node->val<<' ';
    if(node->id == 1 || node->id == 3 || node->id == 7) cout<<endl;
  }
  cout<<endl<<"------------------"<<endl;
  cout<<endl;
}

// --------- IN ORDER TRAVERSAL ---------
void tree::iot(tree_node* node, void (*ptr)(tree_node* node)){
  // base case
  if(node == NULL) return;

  // left
  iot(node->left, (*ptr));

  // root
  (*ptr)(node);

  // right
  iot(node->right, (*ptr));
}

// --------- PRE ORDER TRAVERSAL ---------
void tree::preot(tree_node* node, void (*ptr)(tree_node* node)){
  // base case
  if(node == NULL) return;

  // root
  (*ptr)(node);

  // left
  preot(node->left, (*ptr));

  // right
  preot(node->right, (*ptr));
}

// --------- POST ORDER TRAVERSAL ---------
void tree::postot(tree_node* node, void (*ptr)(tree_node* node)){
  // base case
  if(node == NULL) return;

  // left
  postot(node->left, (*ptr));

  // right
  postot(node->right, (*ptr));

  // root
  (*ptr)(node);
}

// --------- COMMON ANCESTOR ---------: TO DO
tree_node* tree::find_ancestor(int id1, int id2){
  tree_node* root = get_root();
  return root;
}
