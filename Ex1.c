#include <iostream>
#define MAX 100

struct Stack {
    int data[MAX];
    int top = -1;

   
    bool isEmpty() {
        return top == -1;
    }

    
    bool isFull() {
        return top == MAX - 1;
    }

    
    void push(int x) {
        if (isFull()) {
            std::cout << "Stiva este plina!\n";
            return;
        }
        data[++top] = x;
    }

   
    int pop() {
        if (isEmpty()) {
            std::cout << "Stiva este goala!\n";
            return -1;
        }
        return data[top--];
    }

   
    int peek() {
        if (isEmpty()) return -1;
        return data[top];
    }
};

struct Queue {
    int data[MAX];
    int front = 0;
    int rear = -1;
    int count = 0; 

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX;
    }

    
    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Coada este plina!\n";
            return;
        }
        rear = (rear + 1) % MAX; 
        data[rear] = x;
        count++;
    }

    
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Coada este goala!\n";
            return -1;
        }
        int x = data[front];
        front = (front + 1) % MAX;
        count--;
        return x;
    }

   
    int peek() {
        if (isEmpty()) return -1;
        return data[front];
    }
};

int main() {
    
    Stack s;
    s.push(10);
    s.push(20);
    std::cout << "Vârful stivei: " << s.peek() << "\n"; 
    std::cout << "Pop stivă: " << s.pop() << "\n";      
    std::cout << "Este stiva goală? " << (s.isEmpty() ? "Da" : "Nu") << "\n\n";

    
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "Primul element în coadă: " << q.peek() << "\n";
    std::cout << "Dequeue coadă: " << q.dequeue() << "\n";       
    std::cout << "Este coada plină? " << (q.isFull() ? "Da" : "Nu") << "\n";

    return 0;
}
