#include<iostream>
#include<string>

using namespace std;
struct Node
{
	int runScore;
	int matchNumber;
	Node* next;
	Node* previous;
	Node()
	{
		runScore = -1;
		next = nullptr;
		previous = nullptr;
		matchNumber = -1;
	}
	Node(int run,int matchno)
	{
		this->runScore = run;
		next = nullptr;
		previous = nullptr;
		this->matchNumber = matchno;
	}
};
	class doublyList
	{
	public:
		Node* head;
		Node* tail;
		doublyList()
		{
			head = nullptr;
			tail = nullptr;
		}
		bool isEmpty()
		{
			return head == nullptr;
		}
		bool addRunsAtStart(int runs,int matchNo)
		{
			if (MatchRecordExists(matchNo))
			{
				cout << "\nMatch Record Already exists, try different match Number\n";
				return false;
			}
			Node* newNode = new Node(runs,matchNo);//info set 
			if (isEmpty())
			{
				head = newNode;
				tail = newNode;//constructor ki wjah sy dono k next previous null hain
				return true;
			}
			else
			{
				newNode->next = head;
				head->previous = newNode;
				head = newNode;//no need to update tail ka pointer
				head->previous = nullptr;
				return true;

			}
		}
		bool addRunsAtEnd(int runs,int matchNo)
		{
			if (MatchRecordExists(matchNo))
			{
				cout << "\nMatch Record Already exists, try different match Number\n";
				return false;
			}
			Node* newNode = new Node(runs,matchNo);//info set 
			if (isEmpty())
			{
				head = newNode;
				tail = newNode;//constructor ki wjah sy dono k next previous null hain

			}
			else
			{
				tail->next = newNode;
				newNode->previous = tail;
				tail = newNode;
			}
			return true;
		}
		void displayListForward()
		{
			if (isEmpty() == false)
			{
				cout << "Forward List: \n";
				Node* curr = head;
				while (curr != nullptr)
				{
					cout <<"Match: "<<curr->matchNumber <<"\tRunscore: " << curr->runScore << endl;
					curr = curr->next;
				}
			}
			else
			{
				cout << "List is Empty!"<<endl;
			}
		}
		void displayListReverse()
		{
			if (isEmpty() == false)
			{
				cout << "Reverse List: \n";
				Node* curr = tail;
				do
				{
					cout << "Match:" << curr->matchNumber << "\tRunscore: " << curr->runScore << endl;
					curr = curr->previous;
				} while (curr!= nullptr);
			}
			else
			{
				cout << "List is Empty!" << endl;
			}
		}
		void deleteAllOccurrences(int score) {
			if (isEmpty()) {
				cout << "List is Empty. Deletion not Possible;\n";
				return;
			}
			
			Node* current = head;
			bool found = false;

			while (current != nullptr) {
				if (current->runScore == score) {
					found = true;
					Node* temp = current; 

					// adjust pointers
					if (temp->previous != nullptr) {
						temp->previous->next = temp->next;
					}
					else {
						head = temp->next; // update head 
					}
					if (temp->next != nullptr) {
						temp->next->previous = temp->previous;
					}
					else {
						tail = temp->previous; // update tail
					}

					current = current->next; // Move to the next node
					delete temp; // Delete node 
					cout << "Deleted score: " << score << "\n"; 
				}
				else {
					current = current->next; 
				}
			}

			if (!found) {
				cout << "Score not found in the List\n";
			}
		}
		int displayHighest()
		{
			if (isEmpty()) { cout << "List is Empty"; return -1; }
			int highestScore = head->runScore;
			Node* curr = head;
			while(curr!=nullptr)
			{
				if (curr->runScore > highestScore)
				{
					highestScore = curr->runScore;
				}
				
				curr = curr->next;
			}
			
			return highestScore;
		}
		int displayLowest()
		{
			if (isEmpty()) { cout << "List is Empty"; return -1; }
			int lowestScore = head->runScore;
			Node* curr = head;
			while (curr != nullptr)
			{
				
				if (curr->runScore < lowestScore)
				{
					lowestScore = curr->runScore;
				}
				curr = curr->next;
			}

			return lowestScore;
		}
		bool MatchRecordExists(int matchNo) 
		{
			
			Node* current = head;
			
		    while (current!= nullptr) {
				if (current->matchNumber== matchNo) {
					return true;
				}
				current= current->next;
			}
			return false;
		}
	};
int main()
{
	doublyList dl;
	string option;
	cout << "******** Choose Options from the following: *********" << endl;
	do
	{
		cout << "Enter\n1.Insert new Match Scores at Start.\n2.Insert new Match Scores at End\n3.Delete All Occurrences of a Score: \n4.Display Scores in Forward Sequence: \n5.Display Scores in Reverse Sequence: \n6.Find Highest Scores: \n7.Find Lowest Scores: \nEnter exit to exit: ";
		getline(cin, option);

		int score,match;
		if (option == "1")
		{
			while (true)
			{
				cout << "Enter Match number: ";
				if (cin >> match)
				{
					if (match > 0) { break; }
					
					else
					{
						cout << "Enter a Positive Number:\n";
					}
				}
				else
				{
					cout << "invalid input!\t Retry\n";
					cin.clear();
					cin.ignore(123, '\n');
				}
			}
			cin.ignore(123, '\n');
			while (true)
			{
				cout << "Enter Runs Scored: ";
				if (cin >> score)
				{
					if (score > 0) { break; }

					else
					{
						cout << "Enter a Positive Number:\n";
					}
				}
				else
				{
					cout << "invalid input!\t Retry\n";
					cin.clear();
					cin.ignore(123, '\n');
				}
			}
			cin.ignore(123, '\n');
			dl.addRunsAtStart(score, match);
			cout << endl << endl;
			dl.displayListForward();
			cout << endl << endl;
		}
		else if (option == "2")
		{
			while (true)
			{
				cout << "Enter Match number: ";
				if (cin >> match)
				{
					if (match > 0) { break; }

					else
					{
						cout << "Enter a Positive Number:\n";
					}
				}
				else
				{
					cout << "invalid input!\t Retry\n";
					cin.clear();
					cin.ignore(123, '\n');
				}
				dl.displayListForward();

			}
			cin.ignore(123, '\n');
			while (true)
			{
				cout << "Enter Runs Scored: ";
				if (cin >> score)
				{
					if (score > 0) { break; }

					else
					{
						cout << "Enter a Positive Number:\n";
					}
				}
				else
				{
					cout << "invalid input!\t Retry\n";
					cin.clear();
					cin.ignore(123, '\n');
				}
			}
			cin.ignore(123, '\n');
			dl.addRunsAtEnd(score, match);
			cout << endl << endl;
			dl.displayListForward();
			cout << endl << endl;
		}
		else if (option == "3")
		{
			cout << "Enter the Score to delete all matches having this score: ";
			while (true)
			{
				if (cin >> score)
				{
					if (score > 0) { break; }
					else { cout << "Invalid Score Entered"; }

				}
				else
				{
					cout << "Enter a valid integer for score:";
					cin.clear();
					cin.ignore(123, '\n');
				}
			}
			cin.ignore(123, '\n');
			dl.deleteAllOccurrences(score);
			cout << endl << endl;
			dl.displayListForward();
			cout << endl << endl;
		}
		else if (option == "4")
		{
			cout << endl << endl;
			dl.displayListForward();
			cout << endl << endl;


		}
		else if (option == "5")
		{
			cout << endl << endl;
			dl.displayListReverse();
			cout << endl << endl;

		}
		else if (option == "6")
		{
			cout << endl << endl;

			cout << "Highest score from all match is: " << dl.displayHighest()<<endl;
			cout << endl << endl;

		}
		else if (option == "7")
		{
			cout << endl << endl;

			cout << "Lowest Score from all matches is " << dl.displayLowest()<<endl;
			cout << endl << endl;

		}
		else if (option == "exit")
		{
			cout << "Exiting Application!";
			exit(0);
		}
		else
		{
			cout << "Invalid Option Entered!\n";
		}
		cout << endl << endl;
	} while (true);


}