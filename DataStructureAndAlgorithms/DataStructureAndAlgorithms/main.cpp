#include <iostream>
#include <vector>

#include "LadderStep.h"
#include "BubbleSort.h"
#include "InsertSort.h"
#include "SelectSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main()
{
	// √∞≈›≈≈–Ú
	int a[] = {9,8,7,6,5,4,3,2,1,100,53,44,75};
	//BubbleSort(a, sizeof(a)/4);
	//InsertSort(a, sizeof(a) / 4);
	//SelectSort(a, sizeof(a) / 4);

	// πÈ≤¢≈≈–Ú
	const int length = sizeof(a) / sizeof(int);
	//int tmp[length];
	//MergeSort(a, tmp, 0, length-1);

	// øÏÀŸ≈≈–Ú
	QuickSort(a, 0, length-1);

	// ≈¿¬•Ã›Œ Ã‚
	//cout << LadderStep::ClimbLadder(7) << endl;

	return 0;
}