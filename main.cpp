#include <iostream>
using namespace std;

struct Node
{
	int key;
	int field;
	Node* ptr;
	Node* prev;
};

class List
{
private:
	Node* head;
	Node* tail;

	void IndexList()
	{
		Node* Index = head;
		int i = 1;
		while (Index->ptr != nullptr)
		{
			Index->key = i++;
			Index = Index->ptr;
		}
	}

	void Clear()
	{
		Node* Clear = head;
		if (Clear == nullptr) return;

		while (Clear != nullptr)
		{
			Node* Next = Clear;
			Clear = Clear->ptr;
			delete Next;
		}
		head = nullptr;
		tail = nullptr;
	}
public:
	int count = 0;
	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	~List()
	{
		Clear();
	}

	void Add_Begin(int x)
	{
		Node* elem = new Node;
		elem->field = x;

		if (head == nullptr)
		{
			elem->ptr = nullptr;
			elem->prev = nullptr;
			head = elem;
			tail = elem;
			this->count++;
			IndexList();
			return;
		}
		else
		{
			Node* pass = head;
			elem->prev = nullptr;
			elem->ptr = pass;
			pass->prev = elem;
			head = elem;
			this->count++;
			IndexList();
			return;
		}
	}

	void Add_End(int x)
	{
		Node* elem = new Node;
		elem->field = x;

		if (head == nullptr)
		{
			elem->ptr = nullptr;
			elem->prev = nullptr;
			head = elem;
			tail = elem;
			this->count++;
			IndexList();
			return;
		}
		else
		{
			Node* end = tail;
			tail = elem;
			end->ptr = elem;
			elem->ptr = nullptr;
			elem->prev = end;
			this->count++;
			IndexList();
			return;
		}
	}

	void Add(int x, int index)
	{
		Node* elem = new Node;
		elem->field = x;
		if (index == 1)
		{
			Add_Begin(x);
		}
		else if (index == this->count)
		{
			Add_End(x);
		}
		else
		{
			if ((this->count / 2) <= index)
			{
				Node* Parent = tail;
				Node* Next = Parent->prev;
				while (Next != nullptr)
				{
					if (Next->key == index)
					{
						Parent = Next;
						Next = Next->prev;
						elem->prev = Next;
						Next->ptr = elem;
						elem->ptr = Parent;
						Parent->prev = elem;
						this->count++;
						return;
					}
					Parent = Next;
					Next = Next->prev;
					Next->ptr = Parent;
				}
			}
			else
			{
				Node* Parent = head;
				Node* Next = Parent->ptr;
				while (Next != nullptr)
				{
					if (Next->key == index)
					{
						Parent = Next;
						Next = Next->ptr;
						Parent->ptr = elem;
						elem->prev = Parent;
						elem->ptr = Next;
						Next->prev = elem;
						this->count++;
						return;
					}
					Parent = Next;
					Next = Next->ptr;
					Next->prev = Parent;
				}
			}
		}
		IndexList();
	}

	void Print()
	{
		Node* Print = head;
		if (Print != nullptr)
		{
			while (Print != nullptr)
			{
				cout << "[" << Print->field << "]";
				Print = Print->ptr;
			}
			cout << endl;
		}
		else
		{
			cout << "This list is empty!" << endl;
		}
	}

	void PrintBack()
	{
		Node* PrintBack = tail;
		if (PrintBack != nullptr)
		{
			while (PrintBack != nullptr)
			{
				cout << "[" << PrintBack->field << "]";
				PrintBack = PrintBack->prev;
			}
			cout << endl;
		}
		else
		{
			cout << "This list is empty!" << endl;
		}
	}

	void DeleteBegin()
	{
		if (head != nullptr)
		{
			Node* begin = head;
			head = begin->ptr;
			head->prev = nullptr;
			delete begin;
			this->count--;
			IndexList();
			return;
		}
		else
		{
			cout << "This list is empty!\n";
		}

	}

	void DeleteEnd()
	{
		if (head != nullptr && tail != nullptr)
		{
			Node* end = tail;
			tail = end->prev;
			tail->ptr = nullptr;
			delete end;
			this->count--;
			IndexList();
			return;
		}
		else
		{
			cout << "This list is empty!\n";
		}
	}

	void Delete(int index)
	{
		IndexList();
		if (index == 1)
		{
			DeleteBegin();
		}
		else if (index == this->count)
		{
			DeleteEnd();
		}
		else
		{
			if (index <= (this->count / 2))
			{
				Node* Parent = tail;
				Node* Next = Parent->prev;
				while (Next != nullptr)
				{
					if (Next->key == index)
					{
						(Next->prev)->ptr = Parent;
						Parent->prev = Next->prev;
						delete Next;
						this->count--;
						IndexList();
						return;
					}
					Parent = Next;
					Next = Next->prev;
					Next->ptr = Parent;
				}
			}
			else
			{
				Node* Parent = head;
				Node* Next = Parent->ptr;
				while (Next != nullptr)
				{
					if (Next->key == index)
					{
						Parent->ptr = Next->ptr;
						(Next->ptr)->prev = Parent;
						delete Next;
						this->count--;
						IndexList();
						return;
					}
					Parent = Next;
					Next = Next->ptr;
					Next->prev = Parent;
				}
			}
		}
	}

	void Find(int x)
	{
		Node* search_elem = head;

		while (search_elem != nullptr)
		{
			if (search_elem->field == x)
			{
				cout << "Element [" << x << "] in the list is\n";
				return;
			}
			search_elem = search_elem->ptr;
		}
		cout << "Element [" << x << "] is not in the list\n";
	}

};

int main()
{
	setlocale(LC_ALL, "RU");

	List list;

	list.Add_Begin(3);
	list.Add_Begin(5);
	list.Add_End(10);
	list.Add_End(15);

	list.Add(6, 3);
	list.Add(11, 1);
	list.Add(17, 3);
	list.Print();
	list.DeleteBegin();
	list.Print();
	list.Delete(4);
	list.Print();
}