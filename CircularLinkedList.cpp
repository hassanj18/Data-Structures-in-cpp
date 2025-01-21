#include<iostream>
using namespace std;

template <class T>
class List
{
public:
	List();
	~List();
	void insertAtStart(T d){
		if (tail == 0){
			tail = new Node(d, tail);
			tail->next = tail;
			return;
		}
		Node* temp = tail->next;
		tail->next = new Node(d, temp);

	}
	void insertAtEnd(T d){
		if (tail == 0){
			tail = new Node(d, NULL);
			tail->next = tail;
			return;
		}
		tail->next = new Node(d, tail->next);
		tail = tail->next;

	}
	bool addAfter(T data, T item){
		if (tail){
			Node* curr = tail->next;
			do{
				if (curr->data == data){
					Node* temp = curr -> next;
					curr->next = new Node(item, temp);
						return true;
				}
				
				curr = curr->next;
			} while (curr != tail->next);
		}
			return false;
		
	}
	bool deleteNode(T key){
		if (tail->next == tail){
			if (tail->data == key){
				delete tail;
				tail = 0;
				return true;
			}
			return false;
		}
		if (tail){
			if (tail->data == key){
				Node* temp = tail->next;
				delete tail;
				tail = temp;
				return true;
			}
			Node* curr = tail->next;
			do{
				if (curr->next->data == key){
					Node* temp = curr->next;
					curr->next = temp->next;
					delete temp;
					return true;
				}

				curr = curr->next;
			} while (curr != tail->next);
		}
		return false;

	
	}
	void print(){
		if (tail){
			Node* curr = tail->next;
			do{

				cout << curr->data<< " " ;
			curr = curr->next;
			} while (curr != tail->next);
			cout << endl;
		}
	}
private:
	class Node
	{
	public:
		Node(){
			tail = NULL;
		}
		Node(T d, Node* n){
			data = d;
			next = n;
		}

	public:
		T data;
		Node* next;
	};

	Node* tail;
};

template <class T>
List<T>::List()
{
	tail = 0;
}
template <class T>
List<T>::~List()
{
}







void main(){
	//cout << "hello wordl";

	List<int> l;
	l.insertAtEnd(6);
	l.insertAtStart(5);
	l.insertAtStart(4);
	l.insertAtStart(1);
	l.insertAtEnd(55);
	l.print();
	l.addAfter(55, 96);
	l.print();

	l.deleteNode(55);

	l.print();



	system("pause");
}
