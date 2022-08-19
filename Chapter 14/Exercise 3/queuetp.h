#ifndef QUEUETP_H_
#define QUEUETP_H_

template <typename T> class Queue
{
  private:
    struct Node
    {
        T item;
        struct Node *next;
    };
    enum
    {
        Q_SIZE = 10
    };

    // private class members
    Node *front;     // pointer to front of Queue
    Node *rear;      // pointer to rear of Queue
    int items;       // current number of items in Queue
    const int qsize; // maximum number of items in Queue
    // preemptive definitions to prevent public copying
    Queue(const Queue &q) : qsize(0) {}
    Queue &operator=(const Queue &q) { return *this; }

  public:
    Queue(int qs = Q_SIZE); // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enquene(const T &item); // add item to end
    bool dequeue(T &item);       // remove item from front
};

template <typename T> Queue<T>::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

template <typename T> Queue<T>::~Queue()
{
    Node *temp;
    while (front != nullptr)
    {
        temp = front;        // save address of front item
        front = front->next; // reset pointer to next item
        delete temp;         // delete former front
    }
}

template <typename T> bool Queue<T>::isempty() const { return items == 0; }

template <typename T> bool Queue<T>::isfull() const { return items == qsize; }

template <typename T> int Queue<T>::queuecount() const { return items; }

// Add item to queue
template <typename T> bool Queue<T>::enquene(const T &item)
{
    if (isfull())
    {
        return false;
    }
    Node *add = new Node; // create node
    // on failure, new throws std::bad_alloc exception
    add->item = item; // set node pointers
    add->next = nullptr;
    items++;
    if (front == nullptr) // if queue is empty,
    {
        front = add; // place item at front
    }
    else
    {
        rear->next = add; // else place at rear
    }
    rear = add;
    return true;
}

// Place front item into item variable and remove from queue
template <typename T> bool Queue<T>::dequeue(T &item)
{
    if (front == nullptr)
    {
        return false;
    }
    item = front->item; // set item to first item in queue
    items--;
    Node *temp = front;  // save location of first item
    front = front->next; // reset front to next item
    delete temp;         // delete former first item
    if (items == 0)
    {
        rear = nullptr;
    }
    return true;
}

#endif