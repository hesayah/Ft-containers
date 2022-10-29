#include "map.hpp"
int main()
{
	ft::map<int, int> 	bst;
	bst.insert(std::pair<int,int>(1,100));
  	bst.insert(std::pair<int,int>(2,100));
	bst.insert(std::pair<int,int>(3,100));
	bst.insert(std::pair<int,int>(6,100));
	bst.insert(std::pair<int,int>(7,100));
	bst.insert(std::pair<int,int>(5,100));

  	bst.printTree();
  /*cout << endl
     << "After deleting" << endl;
  bst.deleteNode(40);
  bst.printTree();*/
}
