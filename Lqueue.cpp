#ifndef LQUEUE_CPP
#define LQUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
/*
Name: Sriram Vema
Date: 12/7/2021
File Name: Lqueue.cpp
Section: 11
Description: File that handles the linked list functions
*/
//Templated Node class used in templated linked list
template <class T>
class Node {
   public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
   return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
   m_data = 4;

}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lqueue {
 public:
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
  Lqueue();
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
 ~Lqueue();
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue(const Lqueue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue<T>& operator= (Lqueue&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Lqueue
  // Postconditions: Adds a new node to the end of the lqueue.
  void Push(const T&);
  // Name: Pop
  // Preconditions: Lqueue with at least one node. 
  // Postconditions: Removes first node in the lqueue, returns data from first node.
  T Pop();
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
  void Display();
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front 
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
  bool IsEmpty();
  // Name: size
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
  int size();
  // Name: Find()
  // Preconditions: Requires a lqueue
  // Postconditions: Iterates through lqueue and if it finds the thing, returns index, else -1
  int Find(T&);
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  void Swap(int);
  // Name: Clear
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
  void Clear();
  //Name: Overloaded [] operator
  //Precondition: Existing Lqueue
  //Postcondition: Returns object from Lqueue using []
  //Desc: Iterates to node x and returns data from Lqueue
  T& operator[] (int x);//Overloaded [] operator to pull data from Lqueue
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};
//***********IMPLEMENT LQUEUE HERE***********************
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
template <class T>
Lqueue<T>::Lqueue() {
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;

}
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
template <class T>
Lqueue<T>::~Lqueue() {
  if (m_head != nullptr) {
    Clear();
  }
}
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
template <class T>
Lqueue<T>::Lqueue(const Lqueue& newQueue) {
  Node <T> *newCurr = newQueue.m_head; // Iterates through the new lqueue and  deep copies the nodes
  T data;
  if (newQueue.m_head == nullptr) {
    m_head = nullptr;
    m_tail = nullptr;
  } else {
    while(newCurr != nullptr) {
      data = newCurr->GetData();
      Push(data);
      newCurr = newCurr->GetNext();
    }
  }
}
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
template <class T>
Lqueue<T>& Lqueue<T>::operator= (Lqueue& newQueue) {
  Node <T> *newCurr = newQueue.m_head;
  T data;
  if (newQueue.m_head == nullptr) { // Iterates through the new lqueue and  deep copies the nodes 
    m_head = nullptr;
    m_tail = nullptr;
  } else {
    while(newCurr != nullptr) {
      data = newCurr->GetData();
      Push(data);
      newCurr = newCurr->GetNext();
    }
  }
  return *this;
}
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Lqueue
  // Postconditions: Adds a new node to the end of the lqueue.
template <class T>
void Lqueue<T>::Push(const T& newNode) {
  Node <T> *temp = new Node<T>(newNode);
  if (m_head == nullptr) { // Adds a new node to the end of the linked list
    m_head = temp;
    m_tail = m_head;
    m_size ++;
  } else {
    m_tail->SetNext(temp);
    m_tail = m_tail->GetNext();
    m_size ++;
  }
}
  // Name: Pop
  // Preconditions: Lqueue with at least one node. 
  // Postconditions: Removes first node in the lqueue, returns data from first node.
template <class T>
T Lqueue<T>::Pop() {
  cout << "pop starting " << endl;
  Node <T> *curr = m_head;
  Node <T> *temp;
  if (m_head == nullptr) {
    cout << "Lqueue is empty" << endl;
  } else {
    if (curr->GetNext() == nullptr) {
      m_head = nullptr;
      m_size --;
      return 0;
    } else {
      curr = curr->GetNext();    // Deletes the first node in the ist and returns the data of the new head
      temp = m_head;
      delete temp;
      m_head = curr;
      m_size --;
      return m_head->GetData(); 
    }
    
  }
  cout << "popped size" << m_size << endl;
  return 0;
}
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
template <class T>
void Lqueue<T>::Display() {
  Node <T> *curr = m_head;
  for (int i = 0; i < m_size; i ++) {
    cout << i + 1 << ". "<< *curr->GetData() << endl;
    curr = curr->GetNext();
  }

}
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front 
template <class T>
T Lqueue<T>::Front() {
  return m_head->GetData();
}
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
template <class T>
bool Lqueue<T>::IsEmpty() {
  if (m_head == nullptr) {
    return true;
  } else {
    return false;
  }
}
  // Name: size
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
template <class T>
int Lqueue<T>::size() {
  return m_size;
}
  // Name: Find()
  // Preconditions: Requires a lqueue
  // Postconditions: Iterates through lqueue and if it finds the thing, returns index, else -1
template <class T>
int Lqueue<T>::Find(T& item) {
  Node <T> *curr = m_head;
  for(int i = 0; i < m_size; i ++) {
    if (curr->GetData() == item) {  // Returns the index of a node the user is trying to find otherwise it returns -1
      return i;
    } else {
      curr = curr->GetNext();
    }
  }
  return -1;
}
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
template <class T>
void Lqueue<T>::Swap(int index) {
  Node <T> *curr = m_head;
  Node <T> *firstprev;
  Node <T> *prev;
  Node <T> *next;
  for (int i = 0; i < (index-1); i ++) {
    curr = curr->GetNext();
  }
  firstprev = curr;
  prev = curr->GetNext();       // Swaps the nodes at a certain index
  curr = curr->GetNext();
  next = curr->GetNext();
  firstprev->SetNext(curr);
  curr->SetNext(prev);
  prev->SetNext(next);
}
  // Name: Clear
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
template <class T>
void Lqueue<T>::Clear() {
  Node <T> *curr = m_head; // Deletes the nodes in the linked list
  Node <T> *prev = curr;
  while (curr != nullptr) {
    prev = curr;
    curr = curr->GetNext();
    delete prev;
  }
  m_size = 0;
  delete curr;
}
  //Name: Overloaded [] operator
  //Precondition: Existing Lqueue
  //Postcondition: Returns object from Lqueue using []
  //Desc: Iterates to node x and returns data from Lqueue
template <class T>
T& Lqueue<T>::operator[] (int x) {
  Node <T> *curr = m_head;
  int count = 0;
  while (count < x) { // Iterates through the linked list and returns the data of a node at that index
    curr = curr->GetNext(); 
    count ++;
  }
  return curr->GetData();
}
#endif
