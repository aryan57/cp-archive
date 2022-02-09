/*
	group : local
	name : pq1.cpp
	srcPath : /home/aryan/Dropbox/Documents from PC/Kaccha Badam/frost/heap/pq1.cpp
	url : /home/aryan/Dropbox/Documents from PC/Kaccha Badam/frost/heap/pq1.cpp
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// PART 1. Linked List Priority Queue

class PriPair
{
public:
    int priority;
    int timestamp;

    PriPair()
    {
        priority = 0;
        timestamp = 0;
    }
    PriPair(int _p, int _t)
    {
        priority = _p;
        timestamp = _t;
    }

    bool operator>(const PriPair &p)
    {
        if (priority > p.priority)
        {
            return true;
        }
        if (priority < p.priority)
        {
            return false;
        }
        return timestamp < p.timestamp;
    }
    friend ostream &operator<<(ostream &out, const PriPair &c);
};

ostream &operator<<(ostream &out, const PriPair &c)
{
    out << "" << c.priority << " " << c.timestamp << "";
    return out;
}

class Node
{
public:
    PriPair data;
    Node *next = nullptr;
    Node(int priority, int timestamp, Node *next = nullptr)
    {
        data.priority = priority;
        data.timestamp = timestamp;
        next = nullptr;
    }
};

class LinkedListPQ
{
public:
    Node *head;
    LinkedListPQ()
    {
        head = nullptr;
    }

    void insert(int priority, int timestamp)
    {
        Node *n = new Node(priority, timestamp);
        if (head == nullptr || n->data > head->data)
        {
            n->next = head;
            head = n;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr && (temp->next->data > n->data))
            {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
        cout << "\n";
    }
    int lookup(int i)
    {
        Node *temp = head;
        int index = 0;
        while (temp != nullptr)
        {
            if (index++ == i)
            {
                return temp->data.timestamp;
            }
            temp = temp->next;
        }
        return -1;
    }

    PriPair deleteMax()
    {
        if (head != nullptr)
        {
            Node *prev = head;
            PriPair ans = head->data;
            head = head->next;
            delete prev;
            return ans;
        }
        return PriPair(-1,-1);
    }

    PriPair findMax()
    {
        if (head != nullptr)
        {
            return head->data;
        }
        return PriPair(-1,-1);
    }

    void reset()
    {
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
};

// PART 2: Dynamic array priority

class DynamicArrayPQ
{
private:
    void fix_up(int l)
    {
        while (l >= 0 && arr[l] > arr[(l - 1) / 2])
        {
            // doing swap
            PriPair temp = arr[l];
            arr[l] = arr[(l - 1) / 2];
            arr[(l - 1) / 2] = temp;

            l = (l - 1) / 2;
        }
    }
    void fix_down(int i)
    {
        while (2*i+1<size)
        {
            int j=2*i+1;
            if(j+1<size && arr[j+1]>arr[j])j++;
            if(arr[i]>arr[j])break;
            // doing swap
            PriPair temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i=j;
        }
    }
    PriPair *arr;
    int size;
    int capacity;

public:
    DynamicArrayPQ()
    {
        arr = nullptr;
        size = 0;
        capacity=0;
    }

    void insert(int priority, int value)
    {
        if (size == capacity)
        {
            capacity *= 2;
            capacity += 1;
            arr = (PriPair*)realloc(arr, capacity * sizeof(PriPair));
        }
        size++;
        arr[size - 1] = PriPair(priority, value);
        fix_up(size - 1);
    }

    PriPair findMax()
    {
        if (size >= 1)
        {
            return arr[0];
        }
        return PriPair(-1,-1); // to denote not found
    }
    PriPair deleteMax()
    {
        if (size == 0)
            return PriPair(-1,-1);
        PriPair ans = arr[0];
    
        // doing swap
        PriPair temp = arr[size-1];
        arr[size-1] = arr[0];
        arr[0] = temp;

        size--;
        fix_down(0);

        // if size/capacity <= 1/4
        // or 4*size<=capacity

        if(4*size<=capacity){
            capacity=2*size;
            arr = (PriPair*)realloc(arr, capacity * sizeof(PriPair));
        }

        return ans;
    }

    int lookup(int i)
    {
        if(i>=size)return -1;
        return arr[i].timestamp;
    }

    void reset(){
        free(arr);
        size=0;
        capacity=0;
        arr=nullptr;
    }
};

class VectorQueuePQ{
    private:
        int size; // or max element stored
        vector<queue<PriPair>*> v;
    public:
        VectorQueuePQ(){
            size=1;
            v.resize(1,nullptr);
        }
        ~VectorQueuePQ(){
            reset();
        }


    void insert(int priority, int value)
    {
        if (priority>=size)
        {
            size=priority+1;
            v.resize(size,nullptr);
        }
        if(v[priority]==nullptr)v[priority] = new queue<PriPair>;
        v[priority]->push(PriPair(priority,value));
    }

    PriPair findMax()
    {
        if (size >= 1)
        {
            if(v[size-1]==nullptr)return PriPair(-1,-1);
            return v[size-1]->front();
        }
        return PriPair(-1,-1); // to denote not found
    }
    PriPair deleteMax()
    {

        if (size == 0)
            return PriPair(-1,-1);
        if(v[size-1]==nullptr){
            // this means size must be 1
            // and priorirty queue is empty 
            PriPair(-1,-1);
        }

        PriPair ans = v[size-1]->front();
        v[size-1]->pop();

        while(size>=1){
            if(v[size-1]==nullptr || v[size-1]->empty()){
                delete v[size-1];
                size--;

                continue;
            }
            break;
        }
        if(size==0){
            size=1;
            v.clear();
        }
        v.resize(size,nullptr);
        return ans;
    }

    int lookup(int i)
    {
        if(i>=size)return -1;
        if(v[i]==nullptr)return 0;
        return v[i]->size();
    }

    void reset(){
        for(int i=0;i<size;i++){
           if(v[i]!=nullptr){
               while (v[i]->empty()==false)
               {
                   v[i]->pop();
               }
               delete v[i];
           }
        }
        v.clear();
        size=1;
        v.resize(size,nullptr);
    }

};

int main()
{
    // vector<int> T(4, 1);
    int T=1;
    LinkedListPQ list;
    DynamicArrayPQ da;
    VectorQueuePQ vq;

    while (true)
    {
        char op;
        cin >> op;
        if (op == 'x')
        {
            break;
        }
        if (op == 'r')
        {
            list.reset();
            da.reset();
            vq.reset();
            continue;
        }
        if (op == 'l')
        {
            int num, i;
            cin >> num >> i;
            int ans;
            int sz;
            switch (num)
            {
            case 1:
                ans = list.lookup(i);
                if(ans!=-1){
                    cout<<ans<<"\n";
                }
                break;
            case 2:
                ans = da.lookup(i);
                if(ans!=-1){
                    cout<<ans<<"\n";
                }
                break;
            case 3:
                sz = vq.lookup(i);
                if(sz!=-1){
                    cout<<sz<<"\n";
                }
                break;
            default:
                break;
            }
            continue;
        }
        if (op == 'f')
        {
            int num;
            cin >> num;
            PriPair ans;
            switch (num)
            {
            case 1:
                ans = list.findMax();
                break;
            case 2:
                ans = da.findMax();
                break;
            case 3:
                ans = vq.findMax();
                break;
            default:
                break;
            }
            if(ans.timestamp!=-1){
                cout<<ans<<"\n";
            }
            continue;
        }
        if (op == 'd')
        {
            int num;
            cin >> num;
            PriPair ans;
            switch (num)
            {
            case 1:
                ans = list.deleteMax();
                break;
            case 2:
                ans = da.deleteMax();
                break;
            case 3:
                ans = vq.deleteMax();
                break;
            default:
                break;
            }
            if(ans.timestamp!=-1){
                cout<<ans<<"\n";
            }
            continue;
        }
        if (op == 'i')
        {
            int num, priority;
            cin >> num >> priority;
            switch (num)
            {
            case 1:
                list.insert(priority, T++);
                break;
            case 2:
                da.insert(priority,T++);
                break;
            case 3:
                vq.insert(priority,T++);
                break;
            default:
                break;
            }
            continue;
        }
    }

    return 0;
}
