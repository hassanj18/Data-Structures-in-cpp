#include<iostream>
using namespace std;

template< typename t>
class list
{
public:
	list() {
		head = 0;
		count = 0;
	}
	~list() {
		for (node* temp = head; temp != 0;)
		{
			node* temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
	}
	void insertathead(t d) {
		if (1) {
			node* temp = new node(d, head);
			head = temp;
		}
	}
	void print() {
		cout << "stack:\t";
		for (node* temp = head; temp != 0; temp = temp->next)
		{
			cout << temp->data << " ";

		}
		cout << endl;
	}
	bool searchelement(t key) {
		if (isempty())
			return false;
		for (node* temp = head; temp != 0; temp = temp->next)
		{
			if (temp->data == key)
			{
				cout << "\n found:" << key << endl;
				return 1;
			}
		}
		return 0;
	}
	void deleteatstart() {
		if (head) {
			node* temp = head->next;
			delete head;
			head = temp;
		}
	}
	void insertatend(t d) {

		node* newnode = new node(d, 0);
		node* i = head;
		for (; i->next != 0; i = i->next);

		i->next = newnode;

	}
	bool isempty() {
		if (head == 0)
			return true;
		return false;
	}
	void deleteall(t key) {
		if (head->data == key)
			deleteatstart();

		node* i = head;
		for (; i->next != 0; i = i->next) {
			if (i->next->data == key) {
				deleteafter(i);
				if (i->next == 0)
					break;
			}
		}
	}

	void insertbefore(t const v1, t const v2) {
		if (searchelement(v2)) {
			if (head->data == v2) {
				node* newnode = new node(v1, head);
				head = newnode;
				return;
			}

			node* i = head;
			for (; i->next->data != v2; i = i->next);

			node* temp = i->next;
			i->next = new node(v1, temp);

		}
	}
	list(list& rhs) {
		if (rhs.head == 0) {
			head = 0;
			count = 0;
		}
		else {
			head = new node(rhs.head->data, 0);
			for (node* i = rhs.head->next; i != 0; i = i->next) {
				insertatend(i->data);
			}
		}

	}
	list& operator=(list& rhs) {
		if (head != 0) {
			//first delete
			for (node* temp = rhs.head; temp != 0;)
			{
				node* temp2 = temp->next;
				delete temp;
				temp = temp2;
			}
			//copy
			head = new node(head->data, 0);
			for (node* i = head->next; i->next != 0; i = i->next) {
				insertatend(i->data);
			}
		}
		else {
			if (rhs.head == 0) {
				head = 0;
				count = 0;
			}
			else {
				rhs.head = new node(head->data, 0);
				for (node* i = head->next; i->next != 0; i = i->next) {
					insertatend(i->data);
				}
			}
		}
		return *this;
	}

	class node
	{
	public:
		node(t d, node* n = 0) {
			data = d;
			next = n;
		}
		~node() {

		}
		t data;
		node* next;



	};
	void deleteafter(node* ptr) {
		if (ptr->next) {
			node* temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
		}
	}


	node* head;
	int count;

};


template <class T>
class stack
{
public:
	stack();
	~stack();
	void push(T const& e) {
		stackList.insertathead(e);
		size++;
	}
	void pop() {
		if (size == 0) {
			cout << "Stack already empty\n";
			return;
		}
		else {
			stackList.deleteatstart();
		}
	}
	bool top(T &d) {
		if (size == 0) {
			cout << "Stack already empty\n";
			return false;
		}
		else {
			d = stackList.head->data;
			return true;
		}
	}
	bool isEmpty() {
		if (size == 0)return true;

		return false;
	}
	int Size() {
		return size;
	}
	void print() {
		stackList.print();
	}
private:
	int size;
	list<T> stackList;
};
template <class T>
stack<T>::stack()
{
	size = 0;
}
template <class T>
stack<T>::~stack()
{
}
int main() {
	stack<int> s1;
	s1.push(5);
	s1.push(6);
	s1.push(3);
	s1.push(3);
	s1.print();
	int d = 0;
	s1.top(d);
	cout << "\on top is : " << d;
	cout << "\nsize: " << s1.Size() << endl;
	s1.pop();
	cout << "after pop :";
	s1.print();



}

