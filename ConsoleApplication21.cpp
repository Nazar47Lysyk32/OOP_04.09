#include <iostream>
#include <string>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(char value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    char dequeue() {
        if (isEmpty()) {
            cerr << "Cherga Empty." << endl;
            return '\0'; // Повернення пустого символу як помилка
        }
        else {
            char value = front->data;
            Node* temp = front;
            front = front->next;
            delete temp;
            return value;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    ~MyQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

private:
    struct Node {
        char data;
        Node* next;
        Node(char val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;
};

int main() {
    string inputString = "Hello World! 123";

    MyQueue englishQueue; // Черга для англійських символів
    MyQueue otherQueue;   // Черга для інших символів

    // Розділення символів рядка на дві черги
    for (char c : inputString) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            englishQueue.enqueue(c);
        }
        else {
            otherQueue.enqueue(c);
        }
    }

    // Виведення вмісту черг на екран
    cout << "English symbols:" << endl;
    while (!englishQueue.isEmpty()) {
        cout << englishQueue.dequeue() << " ";
    }
    cout << endl;

    cout << "Inshi symbols::" << endl;
    while (!otherQueue.isEmpty()) {
        cout << otherQueue.dequeue() << " ";
    }

    return 0;
}
