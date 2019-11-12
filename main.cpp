#include <iostream>
using namespace std;

struct Node
{
	int count;
	int field;
	Node* ptr;
	Node* prev;
};

class List
{
private:
	Node* head;
	Node* tail;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	~List()
	{
		Clear();
	}
	void Add_Element(int x)
	{
		Node* elem = new Node;
		elem->field = x;

		if (head == nullptr)
		{
			elem->ptr = nullptr;
			elem->prev = nullptr;
			head = elem;
			tail = elem;
			return;
		}

		Node* pass = head;
		if (pass->field >= elem->field)
		{
			elem->prev = nullptr;
			elem->ptr = pass;
			pass->prev = elem;
			head = elem;
			return;
		}

		Node* pass1 = pass->ptr;

		while (pass1)
		{
			if (pass->field < elem->field && elem->field <= pass1->field)
			{
				pass->ptr = elem;
				elem->prev = pass;
				elem->ptr = pass1;
				pass1->prev = elem;
				return;
			}
			pass = pass1;
			pass1 = pass1->ptr;
		}
		tail = elem;
		pass->ptr = elem;
		elem->ptr = nullptr;
		elem->prev = pass;
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

	void DeleteElem(int x)
	{
		Node* begin = head;
		Node* end = tail;

		if (begin->field == x)
		{
			head = begin->ptr;
			head->prev = nullptr;
			delete begin;
			return;
		}
		if (end->field == x)
		{
			tail = end->prev;
			tail->ptr = nullptr;
			delete end;
			return;
		}

		Node* search = begin->ptr;
		while (search)
		{
			if (search->field == x)
			{
				begin->ptr = search->ptr;
				(search->ptr)->prev = begin;
				delete search;
				return;
			}
			begin = search;
			search = search->ptr;
			search->prev = begin;
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

	void IndexList()
	{
		if (head != nullptr)
		{
			Node* Index = head;
			int i = 1;
			while (Index != nullptr)
			{
				Index->count = i++;
				Index = Index->ptr;
			}
		}
	}

	void FindByIndex(int x)
	{
		IndexList();
		if (head != nullptr)
		{
			Node* Find = head;
			while (Find != nullptr)
			{
				if (Find->count == x)
				{
					cout << "The value of this element - [" << Find->field << "]" << endl;
					return;
				}
				Find = Find->ptr;
			}
			if (Find == nullptr)
			{
				cout << "Not Find!" << endl;
			}
		}
		else
		{
			cout << "This list is empty!" << endl;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "RU");

	List list;
	cout << "1 - Add\n2 - Delete\n3 - Print\n4 - Print Back\n5 - Find\n6 - Clear\n7 - FindByIndex\n";
	while (1)
	{
		cout << "Enter choice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			int num;
			cout << "Num elem:"; cin >> num;
			for (int i = 0; i < num; i++)
			{
				int x;
				cout << i + 1 << " - "; cin >> x;
				list.Add_Element(x);
			}
			break;
		case 2:
			int Delete;
			cout << "Field delete elem - "; cin >> Delete;
			list.DeleteElem(Delete);
			break;
		case 3:
			list.Print();
			break;
		case 4:
			cout << endl;
			list.PrintBack();
			break;
		case 5:
			int FindElem;
			cout << "Field find elem - "; cin >> FindElem;
			list.Find(FindElem);
			break;
		case 6:
			list.Clear();
			break;
		case 7:
			int FindIndex;
			cout << "What is the element to find - "; cin >> FindIndex;
			list.FindByIndex(FindIndex);
		default:
			break;
		}
	}
}