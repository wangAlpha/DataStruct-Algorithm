#include <cstdio>
#include <cstring>

struct Node {
    char str[15];
    Node *prev;
    Node *next;
};
class Queue {
    Node *head;
    Node *tail;

public:
    Queue() {
        head = new Node;
        tail = new Node;
        head->prev = NULL;
        head->next = tail;
        tail->prev = head;
        tail->next = NULL;
    }

    void enqueue(char *name) {
        Node *e = new Node;
        strcpy(e->str, name);
        e->prev = tail->prev;
        e->next = tail;
        tail->prev->next = e;
        tail->prev = e;
    }

    Node *dequeue() {
        Node *e = head->next;
        head->next = head->next->next;
        head->next->prev = head;
        return e;
    }

    void query(int n) {
        Node *e = head->next;
        for (int i = 1; i < n; ++i) {
            e = e->next;
        }
        printf("%s\n", e->str);
    }
};

int main() {
    int N, op;
    char name[15];
    Queue s;
    scanf("%d", &N);

    for (size_t i = 0; i < N; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%s", name);
            s.enqueue(name);
        } else if (op == 2) {
            Node *e = s.dequeue();
            printf("%s\n", e->str);
            delete e;
        } else if (op == 3) {
            int pos;
            scanf("%d", &pos);
            s.query(pos);
        }
    }

    return 0;
}