#include<iostream>
using namespace std;



template <class T>
class List
{
public:

	class Node
	{
	public:
		Node() {
			next = 0;
			prev = 0;
		}
		Node(T d, Node* n = 0, Node* p = 0) {
			next = n;
			prev = p;
			data = d;
		}
		~Node() {

		}

	public:
		Node* next;
		Node* prev;
		T data;
	};

public:
	class Iterator
	{
	public:
		bool operator!() {
			if (curr == 0)
				return true;
			return false;
		}
		Iterator(Node* c = 0) {
			curr = c;
		}
		~Iterator() {

		}
		Iterator(Iterator& rhs) {
			curr = rhs.curr;

		}
		Iterator& operator=(const Iterator& rhs) {
			curr = rhs.curr;
			return *this;
		}
		Iterator& operator++() {
			curr = curr->next;
			return *this;
		}
		Iterator& operator--() {
			curr = curr->prev;
			return *this;
		}
		Iterator& operator++(int t) {
			Iterator it(*this);
			curr = curr->next;
			return it;
		}
		Iterator& operator--(int t) {
			Iterator it(*this);
			curr = curr->prev;
			return it;
		}
		T& operator*() {
			return curr->data;
		}
		bool operator==(Iterator& rhs) {
			if (curr == rhs.curr)
				return true;
			return false;
		}
		bool operator!=(Iterator& rhs) {
			if (curr != rhs.curr)
				return true;
			return false;
		}

	private:
		Node* curr;
		friend class List;
	};


	Iterator InsertBefore(Iterator iter, T d) {
		Node* p = iter.curr;
		Node* t = new Node;
		t->data = d;
		t->next = p;
		t->prev = p->prev;
		(t->prev)->next = t;
		p->prev = t;
		Iterator ret(t);
		return ret;

	}
	Iterator Delete(Iterator& itr)
	{
		Node* ptr = itr.curr;
		if (ptr) {

			ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
			Iterator ret(ptr->prev);
			itr.curr = ptr->prev;
			delete ptr;

			return ret;
		}
	}
	List();
	~List();
	void insertAthead(T d);
	void insertAtTail(T d);
	void RemoveFromStart();
	void RemoveFromEnd();
	void Print();
	void removeValue(T value) {
		Iterator itr;
		itr = Begin();
		while(itr.curr!= End().curr)
		{
		//	cout << *itr;
			if (*itr == value) {
				Delete(itr);
			}
			itr++;
		}

	}
	void removeDuplicates() {
		Iterator itr = Begin();

		while (itr != End())
		{
			Iterator j = itr;
			for (++j; j != End(); ++j)
			{
				if (*j == *itr)
					Delete(j);
			}
			++itr;

		}
	}
	List(List& rhs);
	List& operator=(List& rhs);
	Iterator& Begin() {
		Iterator iter(Head->next);
		return iter;
	}
	Iterator& End() {
		Iterator iter(Tail);
		return iter;
	}

private:
	Node* Head;
	Node* Tail;
};

#pragma region List Functions


template <class T>
List<T>::List()
{
	Head = new Node;
	Tail = new Node;
	Head->next = Tail;
	Tail->prev = Head;
}

template <class T>
List<T>::~List()
{
	while (Head->next != Tail) {
		RemoveFromStart();
	}

	if (Head) delete Head;
	if (Tail)delete Tail;
}

template<class T>
void List<T>::insertAthead(T d)
{
	Iterator iter(Head->next);
	InsertBefore(iter, d);
}

template<class T>
void List<T>::insertAtTail(T d)
{
	Iterator iter(Tail);
	InsertBefore(iter, d);
}

template<class T>
void List<T>::RemoveFromStart()
{
	Iterator iter(Head->next);
	Delete(iter);

}

template<class T>
void List<T>::RemoveFromEnd()
{

	Iterator iter(Tail->prev);
	Delete(iter);
}

template<class T>
void List<T>::Print()
{
	Iterator iter;
	iter.curr = Begin().curr;
	for (; iter.curr != End().curr; iter++)
	{

		cout << *iter << " ";
	}
}

template<class T>
List<T>::List(List& rhs)
{
	for (Iterator itr = rhs.Begin(); itr != rhs.End(); itr++)
	{
		insertAthead(*itr);
	}
}

template<class T>
List<T>& List<T>::operator=(List<T>& rhs)
{
	if (Head->next == Tail) {
		for (Iterator i = Begin(); i.curr != End().curr; i++)
		{
			Delete(i);
		}
	}

	for (Iterator itr = rhs.Begin(); itr.curr != rhs.End().curr; itr++)
	{
		insertAthead(*itr);
	}
	return *this;
}


int main() {

	List<int> mylist;
	mylist.insertAthead(4);
	mylist.insertAthead(5);
	mylist.insertAthead(4);
	mylist.insertAthead(5);
	mylist.insertAthead(4);
	mylist.insertAthead(6);
	mylist.insertAthead(4);
	mylist.Print();
	cout << endl<<"Remove value(4) called:\n";
	cout << "5  5 6\n";
	mylist.removeValue(4);
	cout << "\nAfter removing Duplicates\n";
	mylist.removeDuplicates();
	mylist.Print();

	system("pause");

	return 0;


}
