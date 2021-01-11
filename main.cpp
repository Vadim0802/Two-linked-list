#include <iostream>
using namespace std;

struct Node {
	int key;
	int field;
	Node* ptr;
	Node* prev;
};

class List {
private:
	Node* head;
	Node* tail;
	int count;

	void IndexList() {
		Node* Index = head;
		int i = 1;
		while (Index->ptr != nullptr) {
			Index->key = i++;
			Index = Index->ptr;
		}
		count++;
	}

public:
	List() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	~List() {
		Clear();
	}

	void Clear() {
		Node* Clear = head;
		if (Clear == nullptr) return;

		while (Clear != nullptr) {
			Node* Next = Clear;
			Clear = Clear->ptr;
			delete Next;
		}
		
		head = nullptr;
		tail = nullptr;
	}

	void Add_Begin(int x) {
		Node* elem = new Node;
		elem->field = x;
		
		if (head == nullptr) {
			elem->ptr = nullptr;
			elem->prev = nullptr;
			head = elem;
			tail = elem;
		}
		else {
			Node* oldHead = head;
			elem->prev = nullptr;
			elem->ptr = oldHead;
			oldHead->prev = elem;
			head = elem;
		}
		IndexList();
	}

	void Add_End(int x) {
		Node* elem = new Node;
		elem->field = x;
		
		if (head == nullptr) {
			elem->ptr = nullptr;
			elem->prev = nullptr;
			head = elem;
			tail = elem;
		}
		else {
			Node* end = tail;
			tail = elem;
			end->ptr = elem;
			elem->ptr = nullptr;
			elem->prev = end;
		}
		IndexList();
	}

	void Print_By_Index(int index) {
		if (index <= count / 2) {
			Node* begin = head;
			
			int counter = 1;
			while (begin != nullptr) {
				if (counter == index) {
					cout << "[" << counter << "] " << "-->" << " [" << begin->field << "]\n";
					return;
				}
				begin = begin->ptr;
				counter++;
			}
		}
		else if (index > count / 2) {
			Node* end = tail;
			
			int counter = count;
			while (tail != nullptr) {
				if (counter == index) {
					cout << "[" << counter << "] " << "-->" << " [" << end->field << "]\n";
					return;
				}
				end = end->prev;
				counter--;
			}
		}
	}

	void Delete_By_Index(int index) {
		if (head != nullptr) {
			if (index <= count / 2) {
				Node* Parent = head;
				Node* Next = Parent->ptr;
				
				if (index == 1) {
					if (Parent->ptr == nullptr) {
						delete Parent;
						head = nullptr;
						tail = nullptr;
						count--;
						return;
					}
					head = Parent->ptr;
					head->prev = nullptr;
					delete Parent;
					count--;
					return;
				}
				while (Next != nullptr) {
					if (Next->key == index) {
						Next = Next->ptr;
						(Next->ptr)->prev = Parent;
						delete Next;
						count--;
						return;
					}
					Parent = Next;
					Next = Next->ptr;
				}
			}
			else if (index > count / 2) {
				Node* Parent = tail;
				Node* Next = Parent->prev;
				
				if (index == count) {
					if (Parent->prev == nullptr) {
						delete Parent;
						head = nullptr;
						tail = nullptr;
						count--;
						return;
					}
					tail = Parent->prev;
					tail->ptr = nullptr;
					delete Parent;
					count--;
					return;
				}
				while (Next != nullptr) {
					if (Next->key == index) {
						(Next->prev)->ptr = Parent;
						Parent->prev = Next->prev;
						delete Next;
						count--;
						return;
					}
					Parent = Next;
					Next = Next->prev;
				}
			}
		}
		else {
			return;
		}
	}

	void Print() {
		Node* Print = head;
		
		if (Print != nullptr) {
			while (Print != nullptr) {
				cout << "[" << Print->field << "]";
				Print = Print->ptr;
			}
			cout << endl;
		}
		else {
			cout << "This list is empty!" << endl;
		}
	}

	void PrintBack() {
		Node* PrintBack = tail;
		
		if (PrintBack != nullptr) {
			while (PrintBack != nullptr) {
				cout << "[" << PrintBack->field << "]";
				PrintBack = PrintBack->prev;
			}
			cout << endl;
		}
		else {
			cout << "This list is empty!" << endl;
		}
	}
};



void test_1() {
	List ll;
	ll.Add_End(1);
	ll.Add_End(2);
	ll.Delete_By_Index(1);
	ll.PrintBack();
}






int main() {
	setlocale(LC_ALL, "RU");
}
