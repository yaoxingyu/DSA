#include <iostream>
#include "LadderStep.h"
#include "BubbleSort.h"

using namespace std;

int main()
{
	// ð������
	int a[] = {1, 43, 2, 89, 565, 66, 4, 59, 0};
	BubbleSort(a, sizeof(a)/4);

	// ��¥������
	//cout << LadderStep::ClimbLadder(7) << endl;

	return 0;
}