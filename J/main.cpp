#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> queue_head;
    deque<int> queue_tail;
    char type;
    int id;
    int n; // number of calls
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> type;
        switch (type) {
            case '+':
                cin >> id;
                queue_tail.push_back(id);
                if (queue_head.size() < queue_tail.size()) {
                    queue_head.push(queue_tail.front());
                    queue_tail.pop_front();
                }
                break;
            case '*':
                cin >> id;
                if (queue_head.size() == queue_tail.size())
                    queue_head.push(id);
                else
                    queue_tail.push_front(id);
                break;
            case '-':
                cout << queue_head.front() << endl;
                queue_head.pop();
                if (queue_head.size() < queue_tail.size()) {
                    queue_head.push(queue_tail.front());
                    queue_tail.pop_front();
                }
                break;
        }
    }

    return 0;
}
