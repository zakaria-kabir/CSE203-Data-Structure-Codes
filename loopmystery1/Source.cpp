#include<iostream>
using namespace std;

int loopMysteryExam1(int i, int j) {

	while (i != 0 && j != 0) {

		i = i / j;

		j = (j - 1) / 2;

		cout << i << " " << j << " ";

	}

	cout << i << endl;

	return i + j;

}
int main() {
	loopMysteryExam1(5, 0);
	loopMysteryExam1(3, 2);
	loopMysteryExam1(16, 5);
	loopMysteryExam1(80, 9);
	loopMysteryExam1(1600, 40);
	//return last sum of last i+j

}