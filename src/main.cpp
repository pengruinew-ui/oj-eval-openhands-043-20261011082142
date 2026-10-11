#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

struct NODE
{
    int data;
    NODE* prev;
    NODE* next;
    
    NODE(int val) : data(val), prev(nullptr), next(nullptr) {}
};

NODE *head = nullptr, *tail = nullptr;
int len = 0;

void Pre()
{
    head = nullptr;
    tail = nullptr;
    len = 0;
}

NODE* move(int i)
{
    if (i < 0 || i >= len) return nullptr;
    
    NODE* current;
    if (i < len / 2) {
        // Move from head
        current = head;
        for (int j = 0; j < i; j++) {
            current = current->next;
        }
    } else {
        // Move from tail
        current = tail;
        for (int j = len - 1; j > i; j--) {
            current = current->prev;
        }
    }
    return current;
}

void insert(int i, int x)
{
    NODE* newNode = new NODE(x);
    
    if (len == 0) {
        // Empty list
        head = tail = newNode;
    } else if (i == 0) {
        // Insert at beginning
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (i == len) {
        // Insert at end
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    } else {
        // Insert in middle
        NODE* current = move(i);
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    
    len++;
}

void remove(int i)
{
    if (len == 0 || i < 0 || i >= len) return;
    
    NODE* toRemove;
    
    if (i == 0) {
        // Remove from beginning
        toRemove = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            // List becomes empty
            tail = nullptr;
        }
    } else if (i == len - 1) {
        // Remove from end
        toRemove = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            // List becomes empty
            head = nullptr;
        }
    } else {
        // Remove from middle
        toRemove = move(i);
        toRemove->prev->next = toRemove->next;
        toRemove->next->prev = toRemove->prev;
    }
    
    delete toRemove;
    len--;
}

int Get_length()
{
    return len;
}

int Query(int i)
{
    if (i < 0 || i >= len) return -1;
    
    NODE* current = move(i);
    return current ? current->data : -1;
}

void Print()
{
    if (len == 0) {
        cout << -1 << endl;
        return;
    }
    
    NODE* current = head;
    while (current) {
        cout << current->data;
        if (current->next) cout << " ";
        current = current->next;
    }
    cout << endl;
}

void Clear()
{
    NODE* current = head;
    while (current) {
        NODE* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    len = 0;
}

}

int n;
int main()
{
    cin >> n;
    int op, x, p, ans;
    LIST::Pre();
    for (int _=0;_<n;++_)
    {
        cin >> op;
        switch(op)
        {
            case 0:
                ans = LIST::Get_length();
                cout << ans << endl;
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                ans = LIST::Query(p);
                cout << ans << endl;
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                LIST::Print();
                break;
        }
    }
    LIST::Clear();
    return 0;
}