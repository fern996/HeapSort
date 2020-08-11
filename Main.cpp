/*
Objective: To implement a Max Heap.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;


struct HeapQueue
{
private:

	vector<int> A;
	int PARENT(int i)
	// return parent of A[i]
	{
		return (i - 1) / 2;
	}

	
	int LEFT(int i)
	// return left child
	{
		return (2 * i + 1);
	}

	
	int RIGHT(int i)
	// return right child
	{
		return (2 * i + 2);
	}


	void heapify_down(int i)
	{
		int left = LEFT(i);
		int right = RIGHT(i);

		int largest = i;

			if (left < size() && A[left] > A[i])
			largest = left;

		if (right < size() && A[right] > A[largest])
			largest = right;

		if (largest != i) {
			swap(A[i], A[largest]);
			heapify_down(largest);
		}
	}

	
	void heapify_up(int i)
	{
		if (i && A[PARENT(i)] < A[i])
		{
	
			swap(A[i], A[PARENT(i)]);

	
			heapify_up(PARENT(i));
		}
	}

public:
	
	unsigned int size()
	//return size
	{
		return A.size();
	}

	
	bool empty()
	//return if empty
	{
		return size() == 0;
	}

	
	void push(int key)
	// insert key into the heap
	{

	A.push_back(key);

	
		int index = size()-1;
		heapify_up(index);
	}

	
	void pop()
	//Removes the root
	{
		try {
			// if heap has no elements, throw an exception
			if (size() == 0)
				throw out_of_range("Heap Underflow: Index out of range");

			
			A[0] = A.back();
			A.pop_back();
			heapify_down(0);
		}
		// catch and print the exception
		catch (const out_of_range& oor) {
			cout << "\n" << oor.what();
		}
	}

	int top()
	//Returns the top. 
	{
		try {
			
			if (size() == 0)
				throw out_of_range("Heap Underflow: Index out of range\n");

			
			return A.at(0);	
		}
		
		catch (const out_of_range& oor) {
			cout << "\n" << oor.what();
		}
	}

	void display()
	//displays heap
	{
		if(empty() == true)
			cout<<"\nHeap is empty. Use Push to enter values \n";
		for (int i = 0; i < size(); i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	HeapQueue pq;
	int n, a, choice;
	
	cout << "Enter the number of values you want to push onto heap \n";
	cin >> n;
	cout << "\nEnter the values. " << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		pq.push(a);
	}
	do
	{
		int value;
		cout << "\tMAX HEAP\n\n";
		cout << "1:PUSH\n2:POP\n3:DISPLAY HEAP\n4:EXIT";
		cout << "\nEnter your choice(1-4): ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "Enter value: ";
			cin >> value;
			pq.push(value);
			cout << endl;
			pq.display();
			break;
		case 2:
			pq.pop();
			pq.display();
			break;
		case 3:
			pq.display();
			break;
		case 4:
			return 0;
			break;
		default:
			cout << "\nPlease enter correct choice(1-4)!!";
			break;
		}
	} while (choice != 4);
	return 0;
}