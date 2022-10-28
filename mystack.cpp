#include "map.hpp"
 
int main() {
ft::map<int, int> bst;
  bst.insert(55, 55);
  bst.insert(40, 50);
  bst.insert(65, 40);
  bst.insert(60, 97);
  bst.insert(75, 70);
  bst.insert(57, 56);

  /*bst.printTree();
  cout << endl
     << "After deleting" << endl;
  bst.deleteNode(40);
  bst.printTree();*/
}
