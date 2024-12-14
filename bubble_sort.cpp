#include <iostream>
using namespace std;

/**
Implement function for BubleSort for doubly linked list.(Swap data)
*/
class Node{
    public:
        int value;
        Node *next;
        Node *prev;
        Node(int _value, Node *_next = NULL, Node *_prev = NULL) : value(_value), next(_next), prev(_prev){}
};

class DoubblyLinkedList{
    public:
        Node *head;
        DoubblyLinkedList(){
            head = NULL;
        }

        void append(int x){
            Node *el = new Node(x);
            if(head == NULL){
                head = el;
                return;
            }

            Node *latest = getLatestNode();

            latest->next = el;
            el->prev = latest;
        }

        void append(int *x, int size){
            for(int i = 0; i<size; i++){
                append(x[i]);
            }
        }


        Node* getLatestNode(){
            Node *latest=head;
            while(latest->next != NULL){
                latest = latest->next;
            }

            return latest;
        }


        void display(){
            Node *current=head;
            while(current != NULL){
                cout << current->value << ", ";

                current = current->next;
            }
            cout << endl;
        }

        void sort(){
            int swapped;
            do{
                Node *current=head;
                swapped = 0;
                while(current != NULL && current->next != NULL){
                    
                    if(current->value > current->next->value){
                        int temp = current->value;
                        current->value = current->next->value;
                        current->next->value = temp;
                        swapped = 1;
                    }

                    current=current->next;
                }
            }while(swapped == 1);

        }
};

int main(){
    DoubblyLinkedList list;
    
    int data[] = {4, 5, 4, 8, 0, -5, 9, 13, -2, 1};

    list.append(data, 10);
    cout << "Before: \t";
    list.display();
    
    list.sort();
    cout << "After: \t\t";
    list.display();
    for(int i = 8; i > -2; i--){
        list.append(i);
    }
    cout << "Append & Sort: \t";
    
    list.sort();
    list.display();

    /**
                            SAMPLE OUTPUT
        Before:         4, 5, 4, 8, 0, -5, 9, 13, -2, 1, 
        After:          -5, -2, 0, 1, 4, 4, 5, 8, 9, 13,
        Append & Sort:  -5, -2, -1, 0, 0, 1, 1, 2, 3, 4, 4, 4, 5, 5, 6, 7, 8, 8, 9, 13, 
    */

    return 0;
}
