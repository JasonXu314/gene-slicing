#include <iostream>
#include <queue>

using namespace std;

int main() {
	priority_queue<int> ints;

	for (int i = 0; i < 10; i++) {
		ints.emplace(i);
	}

	while (!ints.empty()) {
		cout << ints.top() << endl;
		ints.pop();
	}

	return 0;
}