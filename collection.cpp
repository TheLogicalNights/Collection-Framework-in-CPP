/*
    Generic Implimantation of Linked List
*/

#include<iostream>
#include<string>
using namespace std;
#define TRUE 1
#define FALSE 0

typedef int BOOL;

//Structure for singly linked list
template <class T>
struct Node
{
	T iData;
	struct Node * next;
};
//Structure for doubly linked list
template <class T>
struct Node2
{
	T iData;
	struct Node2 * next;
	struct Node2 * prev;
};

template <class T>
class DoublyLinkedList
{
	public:
		struct Node2<T> * Head;
		DoublyLinkedList()
		{
			Head = NULL;
		}
		BOOL InsertFirst(int iValue)
		{
			int iFlag=0;
			struct Node2<T> *NewNode = new Node2<T>;
			NewNode->iData = iValue;
			NewNode->next = NULL;
			NewNode->prev = NULL;
			if(Head==NULL)
			{
				Head = NewNode;
				iFlag = 1;
			}
			else
			{
				NewNode->next = Head;
				Head->prev = NewNode;
				NewNode->prev = NULL;
				Head = NewNode;
				iFlag = 1;
			}
			if(iFlag==1)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
		void Display()
		{
			cout<<"-------------------------------------------\n";
			cout<<"Elements in Linked List are\n";
			struct Node2<T> * Temp = Head;
			while(Temp!=NULL)
			{
				cout<<"|"<<Temp->iData<<"|<=>";
				Temp = Temp->next;
			}
			cout<<"|NULL|\n";
			cout<<"-------------------------------------------\n";
		}
};
template <class T>
class SinglyLikedList
{
	public:
		struct Node<T> * Head;
		SinglyLikedList()
		{
			Head = NULL;
		}

		BOOL InsertFirst(T iValue)
		{
			int iFlag = 0;
			struct Node<T> * NewNode = new Node<T>;
			NewNode->iData = iValue;
			NewNode->next = NULL;
			if(Head==NULL)
			{
				Head = NewNode;
				iFlag=1;
			}
			else
			{
				NewNode->next=Head;
				Head = NewNode;
				iFlag=1;
			}
			if(iFlag==1)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
		BOOL InsertLast(T iValue)
		{
			int iFlag = 0;
			struct Node<T> * NewNode = new Node<T>;
			NewNode->iData = iValue;
			NewNode->next = NULL;
			if(Head==NULL)
			{
				Head = NewNode;
				iFlag=1;
			}
			else
			{
				struct Node<T> * Temp = Head;
				while(Temp->next!=NULL)
				{
					Temp=Temp->next;
				}
				Temp->next=NewNode;
				iFlag=1;
			}
			if(iFlag==1)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
		BOOL InsertAtPos(T iValue,int iPos)
		{
			int iFlag = 0;
			int iCnt = 1;
			int iLength = this->Count();
			if(iPos<1 || iPos>iLength+1)
			{
				cout<<"-------------------------------------------\n";
				cout<<"Error : Invalid Position...\n";
				cout<<"-------------------------------------------\n";
				return FALSE;
			}
			else if(iPos==1)
			{	
				this->InsertFirst(iValue);
				iFlag=1;
			}
			else if(iPos==iLength+1)
			{
				this->InsertLast(iValue);
				iFlag=1;
			}
			else
			{
				struct Node<T> * NewNode = new Node<T>;
				NewNode->iData = iValue;
				NewNode->next = NULL;
				struct Node<T> * Temp = Head;
				while(iCnt!=iPos-1)
				{
					Temp=Temp->next;
					iCnt++;
				}
				NewNode->next=Temp->next;
				Temp->next = NewNode;
				iFlag=1;
			}
			if(iFlag==1)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
		BOOL DeleteFirst()
		{
			int iFlag = 0;
			if(Head==NULL)
			{
				cout<<"-------------------------------------------\n";
				cout<<"Linked List is empty\n";
				cout<<"-------------------------------------------\n";
				return FALSE;
			}
			else if(Head->next==NULL)
			{
				Head = NULL;
				iFlag = 1;
			}
			else
			{
				struct Node<T> * Temp = Head;
				Head = Head->next;
				Temp->next = NULL;
				delete(Temp);
				iFlag = 1;
			}
			if(iFlag==1)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
		BOOL DeleteLast()
		{
			int iFlag = 0;
			if(Head==NULL)
			{
				cout<<"-------------------------------------------\n";
				cout<<"Linked List is empty\n";
				cout<<"-------------------------------------------\n";
				return FALSE;
			}
			else if(Head->next==NULL)
			{
				Head = NULL;
				iFlag = 1;
			}
			else
			{
				struct Node<T> * Temp = Head;
				while(Temp->next->next!=NULL)
				{
					Temp = Temp->next;
				}
				delete(Temp->next);
				Temp->next=NULL;
				iFlag = 1;
			}
			if(iFlag==1)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
		BOOL DeleteAtPos(int iPos)
		{
			int iLength = this->Count();
			int iFlag = 0;
			if(iPos<1 || iPos>iLength)
			{
				cout<<"-------------------------------------------\n";
				cout<<"Error : Invalid Position...\n";
				cout<<"-------------------------------------------\n";
				return FALSE;
			}
			else if(iPos==1)
			{
				this->DeleteFirst();
				iFlag=1;
			}
			else if(iPos==iLength)
			{
				this->DeleteLast();
				iFlag=1;
			}
			else
			{
				int iCnt = 1;
				struct Node<T> * Temp = Head;
				struct Node<T> * Helper = NULL;
				while(iCnt<iPos)
				{
					Helper = Temp;
					Temp = Temp->next;
					iCnt++;
				}
				Helper->next = Temp->next;
				delete(Temp);
			}
			if(iFlag==1)
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
		}
		void Display()
		{
			cout<<"-------------------------------------------\n";
			cout<<"Elements in Linked List are\n";
			struct Node<T> * Temp = Head;
			while(Temp!=NULL)
			{
				cout<<"|"<<Temp->iData<<"|->";
				Temp = Temp->next;
			}
			cout<<"|NULL|\n";
			cout<<"-------------------------------------------\n";
		}
		int Count()
		{
			int iCount = 0;
			struct Node<T> * Temp = Head;
			while(Temp!=NULL)
			{
				iCount++;;
				Temp = Temp->next;
			}
			return iCount;
		}
};

int main()
{
	int iList = 1;
	int iRet = 0;
	int iPos = 0;
	BOOL bRet = FALSE;

	while(iList!=0)//while-3
	{
		int iSelect = 1;
		cout<<"-------------------------------------------\n";
		cout<<"Enter your choice\n";
		cout<<"-------------------------------------------\n";
		cout<<"1.Singly Linear Linked List\n2.Doubly Linear Linked List\n3.Singly Circular Linked List\n4.Doubly Circular Linked List\n0.Exit\n";
		cout<<"-------------------------------------------\n";
		cin>>iList;
		switch(iList)
		{
			case 1 :  
					while(iSelect!=0)//while-2
					{	
							int iChoice = 1;
							cout<<"-------------------------------------------\n";
							cout<<"Enter your choice\n";
							cout<<"-------------------------------------------\n";
							cout<<"1.Linked list of integers\n2.Linked list of floating point\n3.Linked list of double\n4.Linked list of characters\n5.Linked list of String\n0.Exit\n";
							cout<<"-------------------------------------------\n";
							cin>>iSelect;
							switch(iSelect)//switch-2
							{
								case 1: {
											int iNo = 0;
											SinglyLikedList<int>obj;
											cout<<"-------------------------------------------\n";
											cout<<"Linked List of integers is created\n";
											cout<<"-------------------------------------------\n"; 
											while(iChoice!=0)//while-1
											{
												cout<<"1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Delete First\n5.Delete Last\n6.Delete At Position\n7.Display LL\n8.Count Elements\n0.Exit\n";
												cout<<"----------------------------\n";
												cout<<"Enter your choice\n";
												cin>>iChoice;
												switch(iChoice)//switch-1
												{
													case 1 : cout<<"Enter a number that you want to insert in the linked list\n";
															 cin>>iNo;
															 bRet = obj.InsertFirst(iNo);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 2 : cout<<"Enter a number that you want to insert in the linked list\n";
															 cin>>iNo;
															 bRet = obj.InsertLast(iNo);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 3 : cout<<"Enter a number that you want to insert in the linked list\n";
															 cin>>iNo;
															 cout<<"Enter position at which you want to insert element\n";
															 cin>>iPos;
															 bRet = obj.InsertAtPos(iNo,iPos);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 4 : bRet = obj.DeleteFirst();
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 5 : bRet = obj.DeleteLast();
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;
													case 6 : cout<<"Enter position at which you want to delete element\n";
															 cin>>iPos;
															 bRet = obj.DeleteAtPos(iPos);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;
													case 7 : obj.Display();
															 break;
													case 8 : iRet = obj.Count();
															 cout<<"-------------------------------------------\n";
															 cout<<"There are \""<<iRet<<"\" Elements in the linked list\n";
															 cout<<"-------------------------------------------\n";
															 break;
													case 0 : cout<<"-------------------------------------------\n";
															 cout<<"Thank you for using our application\nTry another application\n";
															 cout<<"-------------------------------------------\n";
															 break;
													default : cout<<"-------------------------------------------\n";
															  cout<<"Error:Invalid choice...\n";
															  cout<<"-------------------------------------------\n";
															 break;
												}//end of switch-1
											}//end of while-1
										}		
										break;

								case 2 :{
											float fNo = 0.0;
											SinglyLikedList<float>obj;
											cout<<"-------------------------------------------\n";
											cout<<"Linked List of floating point is created\n";
											cout<<"-------------------------------------------\n"; 
											while(iChoice!=0)
											{
												cout<<"1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Delete First\n5.Delete Last\n6.Delete At Position\n7.Display LL\n8.Count Elements\n0.Exit\n";
												cout<<"----------------------------\n";
												cout<<"Enter your choice\n";
												cin>>iChoice;
												switch(iChoice)
												{
													case 1 : cout<<"Enter a number that you want to insert in the linked list\n";
															 cin>>fNo;
															 bRet = obj.InsertFirst(fNo);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 2 : cout<<"Enter a number that you want to insert in the linked list\n";
															 cin>>fNo;
															 bRet = obj.InsertLast(fNo);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 3 : cout<<"Enter a number that you want to insert in the linked list\n";
															 cin>>fNo;
															 cout<<"Enter position at which you want to insert element\n";
															 cin>>iPos;
															 bRet = obj.InsertAtPos(fNo,iPos);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 4 : bRet = obj.DeleteFirst();
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 5 : bRet = obj.DeleteLast();
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;
													case 6 : cout<<"Enter position at which you want to delete element\n";
															 cin>>iPos;
															 bRet = obj.DeleteAtPos(iPos);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;
													case 7 : obj.Display();
															 break;

													case 8 : iRet = obj.Count();
															 cout<<"-------------------------------------------\n";
															 cout<<"There are \""<<iRet<<"\" Elements in the linked list\n";
															 cout<<"-------------------------------------------\n";
															 break;
													case 0 : cout<<"-------------------------------------------\n";
															 cout<<"Thank you for using our application\nTry another application\n";
															 cout<<"-------------------------------------------\n";
															 break;
													default : cout<<"-------------------------------------------\n";
															  cout<<"Error:Invalid choice...\n";
															  cout<<"-------------------------------------------\n";
															 break;
												}
											}
										}
										break;

								case 3 :{
											double dNo = 0.0;
											SinglyLikedList<double>obj;
											cout<<"-------------------------------------------\n";
											cout<<"Linked List of double is created\n";
											cout<<"-------------------------------------------\n"; 
											while(iChoice!=0)
											{
												cout<<"1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Delete First\n5.Delete Last\n6.Delete At Position\n7.Display LL\n8.Count Elements\n0.Exit\n";
												cout<<"----------------------------\n";
												cout<<"Enter your choice\n";
												cin>>iChoice;
												switch(iChoice)
												{
													case 1 : cout<<"Enter a number that you want to insert in the linked list\n";
															 cin>>dNo;
															 bRet = obj.InsertFirst(dNo);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 2 : cout<<"Enter a number that you want to insert in the linked list\n";
															 cin>>dNo;
															 bRet = obj.InsertLast(dNo);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 3 : cout<<"Enter a number that you want to insert in the linked list\n";
															 cin>>dNo;
															 cout<<"Enter position at which you want to insert element\n";
															 cin>>iPos;
															 bRet = obj.InsertAtPos(dNo,iPos);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 4 : bRet = obj.DeleteFirst();
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 5 : bRet = obj.DeleteLast();
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;
													case 6 : cout<<"Enter position at which you want to delete element\n";
															 cin>>iPos;
															 bRet = obj.DeleteAtPos(iPos);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;
													case 7 : obj.Display();
															 break;

													case 8 : iRet = obj.Count();
															 cout<<"-------------------------------------------\n";
															 cout<<"There are \""<<iRet<<"\" Elements in the linked list\n";
															 cout<<"-------------------------------------------\n";
															 break;
													case 0 : cout<<"-------------------------------------------\n";
															 cout<<"Thank you for using our application\nTry another application\n";
															 cout<<"-------------------------------------------\n";
															 break;
													default : cout<<"-------------------------------------------\n";
															  cout<<"Error:Invalid choice...\n";
															  cout<<"-------------------------------------------\n";
															 break;
												}
											}
										}
										break;

								case 4 :{
											char cCh = '\0';
											SinglyLikedList<char>obj;
											cout<<"-------------------------------------------\n";
											cout<<"Linked List of character is created\n";
											cout<<"-------------------------------------------\n"; 
											while(iChoice!=0)
											{
												cout<<"1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Delete First\n5.Delete Last\n6.Delete At Position\n7.Display LL\n8.Count Elements\n0.Exit\n";
												cout<<"----------------------------\n";
												cout<<"Enter your choice\n";
												cin>>iChoice;
												switch(iChoice)
												{
													case 1 : cout<<"Enter a charecter that you want to insert in the linked list\n";
															 cin>>cCh;
															 bRet = obj.InsertFirst(cCh);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 2 : cout<<"Enter a character that you want to insert in the linked list\n";
															 cin>>cCh;
															 bRet = obj.InsertLast(cCh);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 3 : cout<<"Enter a character that you want to insert in the linked list\n";
															 cin>>cCh;
															 cout<<"Enter position at which you want to insert element\n";
															 cin>>iPos;
															 bRet = obj.InsertAtPos(cCh,iPos);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 4 : bRet = obj.DeleteFirst();
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 5 : bRet = obj.DeleteLast();
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;
													case 6 : cout<<"Enter position at which you want to delete element\n";
															 cin>>iPos;
															 bRet = obj.DeleteAtPos(iPos);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;
													case 7 : obj.Display();
															 break;

													case 8 : iRet = obj.Count();
															 cout<<"-------------------------------------------\n";
															 cout<<"There are \""<<iRet<<"\" Elements in the linked list\n";
															 cout<<"-------------------------------------------\n";
															 break;
													case 0 : cout<<"-------------------------------------------\n";
															 cout<<"Thank you for using our application\nTry another application\n";
															 cout<<"-------------------------------------------\n";
															 break;
													default : cout<<"-------------------------------------------\n";
															  cout<<"Error:Invalid choice...\n";
															  cout<<"-------------------------------------------\n";
															 break;
												}
											}
										}
										break;
								case 5 :{
											char ch = '\0';
											string str;
											SinglyLikedList<string>obj;
											cout<<"-------------------------------------------\n";
											cout<<"Linked List of string is created\n";
											cout<<"-------------------------------------------\n"; 
											while(iChoice!=0)
											{
												cout<<"1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Delete First\n5.Delete Last\n6.Delete At Position\n7.Display LL\n8.Count Elements\n0.Exit\n";
												cout<<"----------------------------\n";
												cout<<"Enter your choice\n";
												cin>>iChoice;
												switch(iChoice)
												{
													case 1 : cout<<"Enter a string that you want to insert in the linked list\n";
															 getline(cin,str);
															 getline(cin,str);
															 bRet = obj.InsertFirst(str);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 2 : cout<<"Enter a string that you want to insert in the linked list\n";
															 getline(cin,str);
															 getline(cin,str);
															 bRet = obj.InsertLast(str);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 3 : cout<<"Enter a string that you want to insert in the linked list\n";
															 getline(cin,str);
															 getline(cin,str);
															 cout<<"Enter position at which you want to insert element\n";
															 cin>>iPos;
															 bRet = obj.InsertAtPos(str,iPos);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable add element into linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 4 : bRet = obj.DeleteFirst();
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;

													case 5 : bRet = obj.DeleteLast();
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;
													case 6 : cout<<"Enter position at which you want to delete element\n";
															 cin>>iPos;
															 bRet = obj.DeleteAtPos(iPos);
															 if(bRet==TRUE)
															 {
																cout<<"-------------------------------------------\n";
																cout<<"Element deleted from linked list successfully\n";
																cout<<"-------------------------------------------\n";
															 } 
															 else
															 {
																 cout<<"-------------------------------------------\n";
																 cout<<"Error : Unable delete element from linked list\n";
																 cout<<"-------------------------------------------\n";
															 }
															 break;
													case 7 : obj.Display();
															 break;

													case 8 : iRet = obj.Count();
															 cout<<"-------------------------------------------\n";
															 cout<<"There are \""<<iRet<<"\" Elements in the linked list\n";
															 cout<<"-------------------------------------------\n";
															 break;
													case 0 : cout<<"-------------------------------------------\n";
															 cout<<"Thank you for using our application\nTry another application\n";
															 cout<<"-------------------------------------------\n";
															 break;
													default : cout<<"-------------------------------------------\n";
															  cout<<"Error:Invalid choice...\n";
															  cout<<"-------------------------------------------\n";
															 break;
												}
											}
										}
										break;

								case 0: cout<<"-------------------------------------------\n";
										cout<<"Thank you for using our application\nTry another application\n";
										cout<<"-------------------------------------------\n";
										break;
								default : cout<<"-------------------------------------------\n";
										  cout<<"Error:Invalid choice...\n";
										  cout<<"-------------------------------------------\n";
										  break;

							}//end of switch-2
					}//end of while-2
					break;
			
			case 2 : {
						while(iSelect!=0)//while-2
						{	
							
							int iChoice = 1;
							cout<<"-------------------------------------------\n";
							cout<<"Enter your choice\n";
							cout<<"-------------------------------------------\n";
							cout<<"1.Linked list of integers\n2.Linked list of floating point\n3.Linked list of double\n4.Linked list of characters\n5.Linked list of String\n0.Exit\n";
							cout<<"-------------------------------------------\n";
							cin>>iSelect;
							switch(iSelect)//switch-2
							{
								case 1: {
											int iNo = 0;
											DoublyLinkedList<int>obj;
											cout<<"-------------------------------------------\n";
											cout<<"Linked List of integers is created\n";
											cout<<"-------------------------------------------\n"; 
											while(iChoice!=0)//while-1
											{
												cout<<"1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Delete First\n5.Delete Last\n6.Delete At Position\n7.Display LL\n8.Count Elements\n0.Exit\n";
												cout<<"----------------------------\n";
												cout<<"Enter your choice\n";
												cin>>iChoice;
												switch(iChoice)
												{
													case 1: cout<<"Enter a number that you want to insert in the linked list\n";
															cin>>iNo;
															bRet = obj.InsertFirst(iNo);
															if(bRet==TRUE)
															{
																cout<<"-------------------------------------------\n";
																cout<<"Element added to linked list successfully\n";
																cout<<"-------------------------------------------\n";
															} 
															else
															{
																cout<<"-------------------------------------------\n";
																cout<<"Error : Unable add element into linked list\n";
																cout<<"-------------------------------------------\n";
															}
															break;
													case 7: obj.Display();
															break;
												}
											}
										}
										break;
					 		}
						}
					}
			case 3 : 
				    break;
			
			case 4 :
					break;
			
			case 0 : cout<<"-------------------------------------------\n";
					 cout<<"Thank you for using our application\nTry another application\n";
					 cout<<"-------------------------------------------\n";
					 break;
			
			default : cout<<"-------------------------------------------\n";
					  cout<<"Error:Invalid choice...\n";
					  cout<<"-------------------------------------------\n";
					  break;
		}//end of switch-3
	}//end of while-3
	
	return 0;
}
