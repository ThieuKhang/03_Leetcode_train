#include <iostream>

template<typename T>
struct Node {
    T data;
    T min;
    Node *next;

    Node(T val = 0, T minVal = 0, Node *ptr = nullptr) : data(val), min(minVal), next(ptr) {}
    ~Node() {
        std::cout << "Delete node : " << data << std::endl;
    }
};

template<typename T>
class Stack {
private:
    Node<T> *head;

public:
    Stack() {
        head = nullptr;
    }

    void push(T val) {
        if (head == nullptr) {
            head = new Node<T>(val, val, nullptr);
        } else {
            T minVal = std::min(val, head->min); // Update the min value for the new node
            head = new Node<T>(val, minVal, head);
        }
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node<T> *tmp = head;
        head = head->next;
        delete tmp;
    }

    T top() {
        if (head == nullptr) {
            std::cerr << "Stack is empty!" << std::endl;
            exit(1);
        }
        return head->data;
    }

    void print() {
        Node<T> *tmp = head;
        std::cout << "[ ";
        while (tmp != nullptr) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << "]" << std::endl;
    }

    T getMin() {
        if (head == nullptr) {
            std::cerr << "Stack is empty!" << std::endl;
            exit(1);
        }
        return head->min;
    }

    ~Stack() {
        while (head != nullptr) {
            Node<T> *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};
int main() {
    Stack<int> myStack;
    myStack.push(10);
    myStack.push(9);
    myStack.push(12);
    myStack.push(18);
    myStack.push(5);

    myStack.print();
    std::cout << "Minimum: " << myStack.getMin() << std::endl;

    myStack.pop();
    myStack.pop();

    myStack.print();
    std::cout << "Minimum: " << myStack.getMin() << std::endl;
    return 0;
}