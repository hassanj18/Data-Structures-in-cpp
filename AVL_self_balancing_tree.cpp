#include<iostream>
using namespace std;

template <class  T, class v>
class BST
{
public:
	BST() {
		root = nullptr;
	}
	~BST() {
		deleteTree(root);
	}

private:
	class Node
	{
	public:
		Node() {
			right = left = 0;
			height = 0;
		}
		~Node() {

		}
		
	public:
		T data;
		v value;
		Node* left;
		Node* right;
		int height;
		Node(T d, v valu, Node* l = 0, Node* r = 0,int h=0) {
			data = d;
			left = l;
			right = r;
			value = valu;
			height = h;
		}
	};
	Node* root;


public:
	int balanceFactor(Node* r) {
		/*if (left == 0 && right == 0)
			return 0;
		else if (left == 0)
			return 0-(right->height);*/

		return getHeight(r->left) - getHeight(r->right);
	}
	void RotateLeft(Node*& x) {
		Node* y = x->right;
		x->right = y->left;
		y->left = x;
		y->height = getHeight(y);
		x->height = getHeight(x);
		x = y;

	}
	void RotateRight(Node*& x) {
		Node* y = x->left;
		x->left = y->right;
		y->right = x;
		y->height = getHeight(y);
		x->height = getHeight(x);
		x=y;
	}
	void Rotate_RightLeft(Node*& x) {//DoubleRight
		RotateRight(x->right);
		RotateLeft(x);
	}
	void Rotate_LeftRight(Node*& x) {//DoubleLeft
		RotateLeft(x->left);
		RotateRight(x);
	}
	int  getHeight(Node* r) {
		if (r == 0)
			return -1;
		else
			return 1 + max(getHeight(r->left),getHeight(r->right));

	}
	void insert(T d, v val) {
		insertrec(d, val, root);
	}
	void insertrec(T d, v val, Node*& r) {
		if (r != 0 && r->data == d) {
			r->value = val;
		}
		if (r == 0) {
			r = new Node(d, val, 0, 0);
				r->height = getHeight(r);
			
		}
		else {
			if (d < r->data) {
				insertrec(d, val, r->left);
				if (balanceFactor(r) == 2) {
					if (d < r->left->data)
						RotateRight(r);
					else
						Rotate_LeftRight(r);
				}
			}
			else if (d > r->data) {
				insertrec(d, val, r->right);
				if (balanceFactor(r) == -2) {
					if (d > r->right->data)
						RotateLeft(r);
					else
						Rotate_RightLeft(r);
				}
			}

			r->height = getHeight(r);
		}
	}
	
	void printrec(Node* r) {
		if (r == nullptr)
			return;
		printrec(r->left);
		cout << r->data << " ";
		printrec(r->right);
	}
	void print() {
		printrec(root);
		cout << endl;
	}
	v* Search(Node* r, T& d) {
		if (r == nullptr) {
			return 0;
		}
		if (r->data == d) {
			cout << "\nNode with data member " << r->value << " found in tree.\n";
			return &r->value;
		}
		if (d < r->data) {
			return Search(r->left, d);
			//return true;
		}
		else
			return Search(r->right, d);



	}
	v* Search(T d) {

		return Search(root, d);

	}

	T ReturnMax(Node* r) {
		if (r->right == 0)
			return r->data;
		else
			ReturnMax(r->right);
	}

	void Remove(Node*& r, T d) {
		if (r != 0) {
			if (r->data == d)
			{

				if (r->left == 0 && r->right == 0) {
					delete r;
					r = 0;
				}
				else if (r->left != 0 && r->right == 0) {
					Node* temp = r->right;
					delete r;
					r = temp;
				}
				else if (r->left == 0 && r->right != 0) {
					Node* temp = r->left;
					delete r;
					r = temp;
				}
				else if (r->left != 0 && r->right != 0) {
					T m = ReturnMax(r->left);
					r->data = m;
					Remove(r->left, m);
				}

			}
			else if (r->data < d)
				Remove(r->right, d);
			else
				Remove(r->left, d);

		}
	}
	void Remove(T k) {
		Remove(root, k);
	}

	int giveLenght() {
		int count = 0;
		lenght(root, count);
		return count;
	}
	int lenght(Node* r, int& count) {
		if (r == 0)
			return 0;
		else {
			count++;
			lenght(r->left, count);
			lenght(r->right, count);
		}
	}
	BST(const BST& obj) {

		copyBST(obj.root, root);
	}
	void copyBST(Node* r, Node*& c) {
		if (r == 0)
			return;
		else {
			c = new Node(r->data, r->value, 0, 0);
			copyBST(r->left, c->left);
			copyBST(r->right, c->right);
		}
	}
	void deleteTree(Node*& r) {
		if (r != 0) {
			deleteTree(r->left);
			deleteTree(r->right);
			delete r;
		}
	}
	int GiveHeightOfTree() {
		return getHeight(root);
	}

};
void main() {/*
	BST<int,int> tree;
	tree.insert(6,1);
	tree.insert(1,8);
	tree.insert(8,1);
	tree.insert(4,5);
	tree.insert(-3,6);
	tree.insert(7,1);
	tree.insert(4,1);
	tree.Remove(7);

	BST<int,int> tree2(tree);
	tree2.print();
	cout << tree.giveLenght();
	tree.Search(4);*/
	BST<int, int> tree; //the key and value both are of type int

	tree.insert(500, 500);
	tree.insert(1000, 1000);
	tree.insert(1, 1);
	tree.insert(600, 600);
	tree.insert(700, 700);
	tree.insert(10, 10);
	tree.insert(30, 30);
	tree.insert(9000, 9000);
	tree.insert(50000, 50000);
	tree.insert(20, 20);

	BST<int, int> tree1(tree);

	tree1.Remove(20);
	tree1.Remove(500);
	tree1.Remove(1000);
	tree.print();
	tree1.print();

	cout << endl << endl;
	cout << "Tree1 Height: " << tree1.GiveHeightOfTree() << endl;

	int* val = tree1.Search(9000);

	if (val != nullptr)
	{
		cout << "1 found" << endl;
	}

	val = tree1.Search(123);
	if (val == nullptr)
	{
		cout << "123 not found" << endl;
	}
	


}
