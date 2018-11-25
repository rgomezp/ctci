#include <iostream>
using namespace std;

struct list_node{
  list_node(int val):val(val),next(NULL){};
  int val;
  list_node* next;
};

class sll{
private:
  list_node* head;
  list_node* tail;
public:
  sll(int val){
    head = new list_node(val);
    tail = head;
  }

  void insert(int val){
    // new node
    list_node* node = new list_node(val);
    tail->next = node;
    tail = node;
  }

  void print_list(){
    list_node* curr = head;
    while(curr!=NULL){
      cout<<curr->val<<',';
      curr = curr->next;
    }
  }
};
