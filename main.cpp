#include <iostream>

struct Node {
  int data;
  Node* next;
};

class LinkedList {
 private:
  Node* head;
private:
    int size_of_linked;

 public:
  LinkedList() { head = nullptr; size_of_linked = 0; }

  void addNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    this->size_of_linked++;
  }

  void printList() {
    Node* current = head;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
   void reverse(){
      Node* prev = nullptr;
      Node* next = nullptr;
      Node* current = head;
       while (current != nullptr){
           next = current->next;
           current->next = prev;
           prev = current;
           current = next;
       }
       // don't forget about referencing the head of the linkedlist reversed
       head = prev;
  }
public:
   Node* getHead(){
        return this->head;
  }
public:
    int size(){
      return this->size_of_linked;
  }
};

int main() {
    // programm executin samples for c++
  LinkedList list;
  list.addNode(1);
  list.addNode(2);
  list.addNode(3);
  std::cout << list.getHead()->data << std::endl;
  list.printList();
  list.reverse();
  std::cout << list.getHead()->data << std::endl;
  list.printList();
  return 0;
}
