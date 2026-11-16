#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    cout << "Highest Priority: " << pq.top() << endl;

    pq.pop();

    cout << "After Deletion: ";

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}