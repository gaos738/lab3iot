#include <iostream>
#include <string>


// Note: It's ok that all the member variables are public for this
// tiny class.  We'll build up to a more robust and complete linked
// list implementation in lecture 10.
template <class T>
class Node {
public:
  T value;
  Node<T> *ptr;
};



template <class T>
void print(Node<T> *data, const std::string &label) {
  std::cout << label;
  Node<T> *tmp = data;
  while (tmp != NULL) {
    std::cout << " " << tmp->value;
    tmp = tmp->ptr;
  }
  std::cout << std::endl;
}



template <class T>
void reverse(Node<T>* &input) {
    Node<T> *current = input;
    Node<T> *next = current->ptr;
    input->ptr = NULL;
    Node<T> *next2 = next->ptr;
  while (next != NULL) {
    next->ptr = current;
    current = next;
    next = next2;
    if (next != NULL) {
    next2 = next->ptr;
    }
  }
  input = current;
}

template <class T>
void reverse(Node<T>* &input) {
    Node<T> *current = input;
    Node<T> *next = current->ptr;
    print(next,"my_list:");
  while (next->ptr != NULL) {
    next = next->ptr;
  }
  if (current->ptr != NULL) {
    reverse(current->ptr);
  }
  next->ptr = current;
  current->ptr = NULL;
  input = next;
}



int main() {

  // manually create a linked list of notes with 4 elements
  Node<int>* my_list = new Node<int>;
  my_list->value = 1;
  my_list->ptr = new Node<int>;
  my_list->ptr->value = 2;
  my_list->ptr->ptr = new Node<int>;
  my_list->ptr->ptr->value = 3;
  my_list->ptr->ptr->ptr = new Node<int>;
  my_list->ptr->ptr->ptr->value = 4;
  my_list->ptr->ptr->ptr->ptr = NULL;


  print(my_list,"my_list before");
  reverse(my_list);
  std::cout<< my_list->value;
  print(my_list,"my_list after ");

  return 0;
  // Note: We are not deleting any of the Nodes we created...  so this
  // program has memory leaks!  More on this in Checkpoint 2!

}

// ===========================================================================
