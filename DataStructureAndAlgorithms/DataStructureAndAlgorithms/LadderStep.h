#pragma once
/*
	Climb Ladder Question
	There's a ladder of N steps, you can take 1 or 2 steps once a time.
	Question: How many kind of ways one can climb to the top?
*/

class LadderStep
{
public:
	LadderStep();
	~LadderStep();

public:
/*
	第一步   1级      2级
	f(n) = f(n-1) + f(n-2);

	递归结束条件
	f(1) = 1, f(2) = 2;

*/
	static int ClimbLadder(int n)
	{
		if (n == 2)
		{
			return 2;
		}
		else if (n == 1)
		{
			return 1;
		}
		else
			return ClimbLadder(n - 1) + ClimbLadder(n - 2);
	}

private:
	int m_n;
};

LadderStep::LadderStep()
{
}

LadderStep::~LadderStep()
{
}