#pragma once
#define QUEEN_NUM 8

#include "Common.h"
#include <math.h>
#include <iostream>

class EightQueen
{
public:
	EightQueen()
	{
	}
	~EightQueen(){}

public:

	void CalQueens(int row)
	{
		if (row == QUEEN_NUM)
		{
			PrintQueens();
			return;
		}
		for (int column = 0; column < QUEEN_NUM; column++)
		{
			if (IsOk(row, column))
			{
				result[row] = column;
				CalQueens(row + 1);
			}
		}
	}

	void PrintQueens()
	{
		for (int row = 0; row < 8; ++row) 
		{ 
			for (int column = 0; column < 8; ++column) 
			{ 
				if (result[row] == column)
					std::cout << "Q ";
				else
					std::cout << "* ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

private:
	bool IsOk(int row, int column) 
	{//�ж�row��column�з����Ƿ���� 
		int leftup = column - 1, rightup = column + 1; 
		for (int i = row-1; i >= 0; --i) 
		{ // �������Ͽ���ÿһ�� 
			if (result[i] == column) 
				return false; // ��i�е�column���������� 
			if (leftup >= 0) 
			{ 
				// �������϶Խ��ߣ���i��leftup���������� 
				if (result[i] == leftup) 
					return false; 
			} 
			if (rightup < 8) 
			{ // �������϶Խ��ߣ���i��rightup���������� 
				if (result[i] == rightup) 
					return false; 
			} 
			--leftup; 
			++rightup; 
		} 
		return true;
	}
	/*bool IsOk(int row, int column)
	{
		SAFE_TEST_RET_VAL(row < QUEEN_NUM, false, false)
		SAFE_TEST_RET_VAL(column < QUEEN_NUM, false, false)

		for (int i = 0; i < QUEEN_NUM; i++)
		{
			for (int j = 0; j < QUEEN_NUM; j++)
			{
				if (i == row || j == column || abs(i-row) == abs(j-column))
				{
					if (a[i][j] != 0)
					{
						return false;
					}
				}
			}
		}

		return true;
	}*/


private:
	int result[QUEEN_NUM];
};