#include<iostream>
using namespace std;

// ======================================== CLASS DEFINITION ========================================
class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};  


// ======================================== CLASS DECLARATION ========================================
class LinkedList {
   int size = 0; // Initialize size to 0 for an empty list

private:
  Node* head; // Pointer to the head (first) node of the list
  
  
//   
public:
  LinkedList() : head(nullptr)    {}  //  ----------------- // Constructor
//   {
//     head = nullptr; // Initialize the head to null for an empty list
    
//   }

// getter and setter
//   int getSize(Node* head) {
//     return __size;
//   }

//   void setSize(int size) {
//     this->__size = size;
//   }

  ~LinkedList() {          // Destructor to free the memory allocated for the linked list
    Node* temp = head;
    while (temp != nullptr) {
      Node* next = temp->next;
      delete temp;
      temp = next;
    }
  }


//  ====================== ======================== Function implementations ============================ ========================

Node* append(int data){

    Node* newNode = new Node(data);
    if(head == nullptr){
        head = newNode;
        return head;    
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = nullptr;  // to avoid dangling pointer, or memory leak
    size++;
    return head;

}

int getSize(){

    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }

    return count;
}


bool isEmpty(){
    return head == nullptr;
}


int search(int data) {              // Search for the given data
  int index = 0;
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->data == data) {
      return index;
    }
    index++;
    temp = temp->next;
  }
  throw out_of_range("Data not found"); // Data not found
}


void getNthNode(int index) {               // Get the node at the given index
  if (index < 0) {
    throw out_of_range("Index out of bounds"); // Handle negative index
  }
  Node* temp = head;
  int count = 0;
  while (temp != nullptr && count < index) {
    count++;
    temp = temp->next;
  }
  cout << temp->data << endl; // Return the node at the index or nullptr if not found
}


void display(){                     // Print the linked list
  
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ---> ";
        temp = temp->next;
    }
    cout << endl;
}

// ======================================= INserting & Deleting elements ====================================================

Node* prepend( int data){

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return newNode;
}



Node* insertAt(int data, int index){

    Node* newNode = new Node(data);
    if(index == 0){
        prepend( data);
        return head;
    }
    else if(index == size){
        append(data);
        return head;
    }

    Node* temp = head;
    int i = 0;
    while(i < index - 1){
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    this->size+=1;                // increment the size of the list
    

    return head;
}

void deleteAt( int index){

    if(index < 0 || index >= size){
        throw out_of_range("Index out of bounds");
    }

    if(index == 0){
        deleteAtBeginning();
        return;
    }

    if(index == size- 1){
        deleteAtEnd();
        return;
    }

    Node* temp = head;
    int i = 0;
    while(i < index - 1){  // 
        temp = temp->next;
        i++;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete; 

}

void deleteAtBeginning(){

    if(head == nullptr){
        throw out_of_range("List is empty");
    }

    head = head->next;
    delete head;  // to avoid dangling pointer, or memory leak        
    return; 
}
void deleteAtEnd(){

    if(head == nullptr){
        throw out_of_range("List is empty");
    }

    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }


    Node* toDelete = temp->next;
    temp->next = nullptr;
    delete toDelete;
    return;
}






  // Function prototypes for common linked list operations
//   void prepend(int data);
//   void append(int data);
//   void insertAt(int index, int data);
//   void deleteAt();
//   void deleteAtEnd();
//   void deleteAtIndex(int index);
//   int __size(Node* head);
//   bool isEmpty();
//   void printList();
//   int search(int data);
//   Node* getNthNode(int index);

};


// ======================================== CONSTRUCTOR ========================================
// LinkedList::LinkedList() {
//   head = nullptr; // Initialize the head to null for an empty list
// }





// =========================== ======================== M A I N ====================== =================================
int main(){

    LinkedList* l=new LinkedList;
    

// inserting elements

    l->insertAt(1,0);
    l->display();

    l->insertAt(2,1);
    l->display();
    l->append(3);
    l->display();


    l->insertAt(11, 0);
    l->display();
    l->insertAt(12, 1);
    l->display();
    l->insertAt(13, 2);
    l->display();

    l->getNthNode(0);
    
    cout<<l->isEmpty();

    return 0;

}