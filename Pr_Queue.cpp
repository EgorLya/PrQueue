#include <iostream>
#include "Prqueue.h"
using namespace std;
// Func po dobavleniyu elementa
void push_element(Priority_Queue& queue)
{
	int numbr, prioritet;
	cout << "Enter number:";
	cin >> numbr;
	cout << "\n1 - H\n2 - M \n3 - L\n";
	cin >> prioritet;
	while (prioritet < 1 || prioritet>3)
	{
		cin >> prioritet;
	}
	system("Cls");
	Priority prior = Priority(prioritet);
	queue.Push(numbr, prior);
}
//swap first method


void swapcopied(Priority_Queue& queuef, Priority_Queue& queuet) {
	Priority_Queue temp_q(queuef);
	queuef = queuet;
	queuet = temp_q;
}


// iz prezentacii

void swap_move(Priority_Queue& queuef, Priority_Queue& queuet) {
	Priority_Queue temp_q(move(queuef));
	queuef = move(queuet);
	queuet = move(temp_q);
}

//razmer o4eredi
void showsize(Priority_Queue& queue)
{
	int l;
	cout << "1 - H\n2 - M\n3 - L\n4 - All\n";
	cin >> l;
	if (l == 1)
		cout << "Size High is - " << queue.GetSizeInHigh() << "\n";
	if (l == 2)
		cout << "Size Medium is - " << queue.GetSizeInMedium() << "\n";
	if (l == 3)
		cout << "Size Low is - " << queue.GetSizeInLow() << "\n";
	if (l == 4)
		cout << "Size is - " << queue.GetSize() << "\n";
}

int main()
{
	Priority_Queue firrst, twoo;


	//zapolnenie
	firrst.Push(1, Priority(1));
	firrst.Push(2, Priority(1));
	firrst.Push(3, Priority(1));
	firrst.Push(4, Priority(2));
	firrst.Push(5, Priority(2));
	firrst.Push(6, Priority(2));
	firrst.Push(7, Priority(3));
	firrst.Push(8, Priority(3));
	firrst.Push(9, Priority(3));


	//zapolnenie
	twoo.Push(10, Priority(1));
	twoo.Push(11, Priority(2));
	twoo.Push(12, Priority(2));
	twoo.Push(13, Priority(3));
	
	int switchh;


	bool abcd = true;
	while (abcd)
	{
		cout << "1. Swap - move\n2. Swap \n3. Close\n4. Size in details\n5. Show\n6. Add\n7. 1-st inf\n8. Delete\n9. Empty\nOther:close\n";
		cin >> switchh;
		switch (switchh)
		{
		case 1:
		{
			swap(firrst, twoo);
			break;
		}
		case 2:
		{
			swapcopied(firrst, twoo);
			break;
		}
		case 3:
		{
			return 0;
		}
		case 4:
		{
			showsize(firrst);
			break;
		}
		case 5:
		{
			cout << "\n";
			if (firrst.GetSize() > 0)
			{
				for (int i = 0; i < firrst.GetSize(); i++)
					cout << firrst[i] << " ";
			}
			cout << "\n";
			if (twoo.GetSize() > 0)
			{
				cout << "\n\nsecond\n";
				for (int i = 0; i < twoo.GetSize(); i++)
					cout << twoo[i] << " ";
				cout << endl;
			}
			break;
		}

		case 6:
		
			push_element(firrst);
			break;
		
		case 7:
		{
			if (firrst.GetSize() > 0)
			{
				cout << "\n\n....:::FIRST QUEUE:::....\nfirst is " << firrst.GetFirst() << "-" << firrst.GetFirstPriority() << "\n";
			}
			if (twoo.GetSize() > 0)
			{
				cout << "\n\n....:::SECOND QUEUE:::....\nfirst is " << twoo.GetFirst() << "-" << twoo.GetFirstPriority() << "\n";
			}
			break;


		}
		case 8:
		{
			firrst.pop();
			break;
		}
		case 9:
		{
			if (!firrst.IsEmpty())
				cout << "isn't empty!\n";
			else
				cout << "empty\n\n";
			break;
		}
		default:
			abcd = false;
			return 0;
		}
	}
	return 0;
}
