//
//#include<iostream>
//using namespace std;
//
//
//template <class T>
//class List
//{
//public:
//
//	class Node
//	{
//	public:
//		Node() {
//			next = 0;
//			prev = 0;
//		}
//		Node(T d, Node* n = 0, Node* p = 0) {
//			next = n;
//			prev = p;
//			data = d;
//		}
//		~Node() {
//
//		}
//
//	public:
//		Node* next;
//		Node* prev;
//		T data;
//	};
//
//public:
//	
//	List();
//	~List();
//	void InsertatStart(T d) {
//
//		if (Head->next == Tail) {
//			Node* t = new Node(d, Tail, Head);
//			Head->next = t;
//			Tail->prev = t;
//		}
//		else {
//			Node* t = new Node(d, Head->next, Head);
//			Head->next = t;
//			t->next->prev = t;
//		}
//	}
//	void InsertatEnd(T d) {
//
//		if (Head->next == Tail) {
//			Node* t = new Node(d, Tail, Head);
//			Head->next = t;
//			Tail->prev = t;
//		}
//		else {
//			Node* t = new Node(d, Tail, Tail->prev);
//			Node* p = Tail->prev;
//			p->next = t;
//			Tail->prev = t;
//		}
//	}
//	void RemovefromEnd() {
//		if (Head-> next!= Tail) {
//			Node* temp = Tail->prev;
//			Tail->prev = temp->prev;
//			temp->prev->next = Tail;
//			delete temp;
//		}
//	}
//	void RemovefromStart() {
//		if (Head->next != Tail) {
//			Node* temp = Head->next;
//			Head->next = temp->next;
//			temp->next->prev = Head;
//			delete temp;
//		}
//	}
//	void Reverse() {
//
//		Node* curr = Head;
//
//		while (curr!= NULL) {
//			Node* nextAdd = curr->next;
//			//swap
//			Node* temp = curr->prev;
//			curr->prev = curr->next;
//			curr->next = temp;
//
//			curr = nextAdd;
//		}
//		Node* Swaptemp = Head;
//		Head = Tail;
//		Tail = Swaptemp;
//
//	}
//	void insertbefore(T const v1, T const v2) {
//		Node* curr = Head->next;
//		while (curr->data != v2) {
//			if (curr->next == NULL) {
//				cout << endl << v2 << " Not Found in list\n";
//				return;
//			}
//			curr = curr->next;
//		}
//		
//		Node* t = new Node(v1, curr, curr->prev);
//		curr->prev->next = t;
//		curr->prev = t;
//
//
//	}
//	
//	void Delete(Node*& ptr) {
//		ptr->next->prev = ptr->prev;
//		ptr->prev->next = ptr->next;
//		Node* temp = ptr->next;
//		delete ptr;
//		ptr = temp;
//	}
//
//	void print() {
//		for (Node* curr  = Head->next;curr!=Tail;curr=curr->next)
//		{
//			cout << curr->data<<" ";
//		}
//		cout << endl;
//	}
//	
//	void RemoveDuplicate() {
//
//		
//			for (Node* i = Head->next; i!= Tail; i = i->next)
//			{
//				for (Node* j = i->next; j != Tail;)
//				{
//					if (j->data == i->data) {
//						Delete(j);
//					}
//					else {
//						j = j->next;
//					}
//				}
//			}
//
//		
//	}
//	
//
//
//private:
//	Node* Head;
//	Node* Tail;
//};
//
//#pragma region List Functions
//
//
//template <class T>
//List<T>::List()
//{
//	Head = new Node;
//	Tail = new Node;
//	Head->next = Tail;
//	Head->prev = 0;
//	Tail->next = 0;
//	Tail->prev = Head;
//}
//
//template <class T>
//List<T>::~List()
//{
//	while (Head->next != Tail) {
//		RemovefromStart();
//	}
//
//	if (Head) delete Head;
//	if (Tail)delete Tail;
//}
//
//
//int main() {
//
//	/*List<int> mylist;
//	mylist.insertAthead(4);
//	mylist.insertAthead(5);
//	mylist.insertAthead(4);
//	mylist.insertAthead(5);
//	mylist.insertAthead(4);
//	mylist.insertAthead(6);
//	mylist.insertAthead(4);
//	mylist.Print();
//	cout << endl;
//	; mylist.removeValue(4);
//	cout << "After removing Duplicates";
//	mylist.removeDuplicates();
//
//
//	mylist.Print();
//
//	system("pause");
//
//	return 0;*/
//
//	List<int> l;
//	l.InsertatEnd(7);
//	l.InsertatEnd(9);
//	l.InsertatStart(9);
//	l.InsertatEnd(10);
//	l.InsertatEnd(9);
//	cout << "List:"; l.print();
//	l.RemoveDuplicate();
//	cout << "List After remove Duplicate:";
//	l.print();
//	cout << "List Insert  before 6 ";
//	l.insertbefore(6,11);
//	l.print();
//	cout << "Reversed:";
//	l.Reverse();
//	l.print();
//
//}
