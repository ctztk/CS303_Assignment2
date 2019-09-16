#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string val;
    Node* next;
};

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* current = nullptr;
    Node* prev = nullptr;
    Node* temp = nullptr;

    // Setting up initial linked list
    head->val = "Tom";
    head->next = second;
    second->val = "John";
    second->next = third;
    third->val = "Harry";
    third->next = fourth;
    fourth->val = "Sam";

    // a. insert Bill before Tom
    temp = new Node();
    temp->val = "Bill";
    temp->next = head;
    head = temp;

    // b. Insert Sue before Sam
    temp = new Node();
    temp->val = "Sue";
    current = head->next;
    prev = head;
    while ( true ) {
        if ( current->val == "Sue" ) {
            prev->next = temp;
            temp->next = current;
            break;
        }
        prev = current;
        current = current->next;
    }
    temp = nullptr;
    current = nullptr;
    prev = nullptr;

    // c. Remove Bill
    head = head->next;

    // d. Remove Sam
    current = head->next;
    prev = head;
    while ( true ) {
        if ( current->val == "Sam" ) {
            prev->next = current->next;
            break;
        }
        prev = current;
        current = current->next;
    }
    current = nullptr;
    prev = nullptr;

    current = head;
    while ( true ) {
        if ( current->next == nullptr ) {
            break;
        }
        cout << current->val << endl;
        current = current->next;
    }
    return 0;
}