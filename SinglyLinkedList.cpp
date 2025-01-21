#include<iostream>
using namespace std;

template< typename T>
class List
{
public:
	List() {
		head = 0;
		count = 0;
	}
	~List() {
		for (Node* temp = head; temp != 0;)
		{
			Node* temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
	}
	void insertAtHead(T d) {
		if (1) {
			Node* temp = new Node(d, head);
			head = temp;
		}
	}
	void Print() {
		cout << "list:\t";
		for (Node* temp = head; temp != 0; temp = temp->next)
		{
			cout << temp->data << " ";

		}
		cout << endl;
	}
	bool SearchElement(T key) {
		if (isEmpty())
			return false;
		for (Node* temp = head; temp != 0; temp = temp->next)
		{
			if (temp->data == key)
			{
				cout << "\n found:" << key << endl;
				return 1;
			}
		}
		return 0;
	}
	void DeleteAtStart() {
		if (head) {
			Node* temp = head->next;
			delete head;
			head = temp;
		}
	}
	void insertAtend(T d) {

		Node* NewNode = new Node(d, 0);
		Node* i = head;
		for (; i->next != 0; i = i->next);

		i->next = NewNode;

	}
	bool isEmpty() {
		if (head == 0)
			return true;
		return false;
	}
	void deleteAll(T key) {
		if (head->data == key)
			DeleteAtStart();

		Node* i = head;
		for (; i->next != 0; i = i->next) {
			if (i->next->data == key) {
				DeleteAfter(i);
				if (i->next == 0)
					break;
			}
		}
	}

	void InsertBefore(T const v1, T const v2) {
		if (SearchElement(v2)) {
			if (head->data == v2) {
				Node* newNode = new Node(v1, head);
				head = newNode;
				return;
			}

			Node* i = head;
			for (; i->next->data != v2; i = i->next);

			Node* temp = i->next;
			i->next = new Node(v1, temp);

		}
	}
	List(List& rhs) {
		if (rhs.head==0) {
			head = 0;
			count = 0;
		}
		else {
			head = new Node(rhs.head->data,0);
			for (Node* i = rhs.head->next; i != 0; i = i->next) {
				insertAtend(i->data);
			}
		}

	}
	List& operator=(List& rhs) {
		if (head != 0) {
			//first delete
			for (Node* temp = rhs.head; temp != 0;)
			{
				Node* temp2 = temp->next;
				delete temp;
				temp = temp2;
			}
			//copy
			head = new Node(head->data, 0);
			for (Node* i = head->next; i->next != 0; i = i->next) {
				insertAtend(i->data);
			}
		}
		else {
			if (rhs.head == 0) {
				head = 0;
				count = 0;
			}
			else {
				rhs.head = new Node(head->data, 0);
				for (Node* i = head->next; i->next != 0; i = i->next) {
					insertAtend(i->data);
				}
			}
		}
		return *this;
	}

	class Node
	{
	public:
		Node(T d, Node* n = 0) {
			data = d;
			next = n;
		}
		~Node() {

		}
		T data;
		Node* next;

		

	};
		void DeleteAfter(Node* ptr) {
			if (ptr->next) {
				Node* temp = ptr->next;
				ptr->next = temp->next;
				delete temp;
			}
		}


	Node* head;
	int count;

};


int main() {
	List<int>li;

	li.insertAtHead(2);
	li.insertAtHead(6);
	li.insertAtHead(7);

	li.insertAtend(7);


	li.insertAtHead(9);
	li.insertAtHead(7);
	li.insertAtHead(4);
	li.Print();
	cout << "\nAfter DeletaALL(7)";
	li.deleteAll(7);
	li.Print();
	cout << "\nSearching 2\n";
	li.SearchElement(2);
	cout << "\nSearching 9\n";
	li.SearchElement(9);

	cout << "\nCommand Delete At start\n";

	li.DeleteAtStart();

	li.Print();

	cout << "\nCharector Arrays\n";

	List<char>mycharlist;

	mycharlist.insertAtHead('a');
	mycharlist.insertAtHead('b');
	mycharlist.insertAtHead('c');

	cout << "Copy Constructor Called for charector array";
	List<char>duplicatelist(mycharlist);

	mycharlist.Print();
	duplicatelist.Print();

}

