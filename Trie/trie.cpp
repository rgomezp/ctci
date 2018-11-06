#include <iostream>
#include <vector>

using namespace std;

// -------- trie_node class --------
// ---------------------------------
class trie_node{
private:
  char val;
  vector<trie_node*> children;

public:
  trie_node(char val) : val(val){}
  char get_val(){return val;}
  void insert(string new_string, int idx);
  void remove(char val);
  trie_node* find_child(char c);
};

// -------- find_child  --------
trie_node* trie_node::find_child(char c){
  for(int i=0; i<children.size(); i++){
    if(children[i]->get_val() == c){
        return children[i];
    }
  }
  return NULL;
}

// -------- insert --------
void trie_node::insert(string new_string, int idx){
  // base case
  if(new_string.length() == idx) return;

  // find child node with char
  trie_node* node = find_child(new_string[idx]);

  if(node!=NULL){
    node->insert(new_string, ++idx);
  }else{
    // create new child
    trie_node* new_node = new trie_node(new_string[idx]);
    children.push_back(new_node);
    new_node->insert(new_string, ++idx);
  }
};

// -------- remove --------
void trie_node::remove(char val){
  for(int i=0; i<children.size(); i++){
    if(children[i]->get_val()==val){
      for(int j=i; j<children.size(); j++){
        children[j]=children[j+1];
      }
    }
  }
}


// -------- trie class --------
// ---------------------------------
class trie{
private:
  trie_node* root;
public:
  trie(){
    trie_node* node = new trie_node(' ');
    root = node;
  }
  void insert(string str);
  bool has_word(string str);
};

void trie::insert(string str){
  root->insert(str, 0);
}

bool trie::has_word(string str){
  trie_node* curr = root;

  for(int i=0; i<str.size(); i++){
    curr = curr->find_child(str[i]);
    if(curr == NULL) return false;
  }
  return true;
}

int main(){
  trie* my_trie = new trie();
  my_trie->insert("hello");
  my_trie->insert("helterskelter");
  cout<<my_trie->has_word("helter");
  delete my_trie;
  return 0;
}
