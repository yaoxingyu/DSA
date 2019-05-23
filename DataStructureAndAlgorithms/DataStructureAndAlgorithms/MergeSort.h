#pragma once
//#include <vector>

void Merge(int a[], int tmp[], int low, int mid, int high)
{
	int i = low, j = mid + 1, pos = low;
	while (i<=mid && j<=high)
	{
		if (a[i] < a[j])
		{
			tmp[pos++] = a[i++];
		}
		else
		{
			tmp[pos++] = a[j++];
		}
	}

	while (i <= mid)
	{
		tmp[pos++] = a[i++];
	}

	while (j <= high)
	{
		tmp[pos++] = a[j++];
	}

	for (int i = low; i <= high; i++)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int a[], int tmp[], int low, int high)
{
	if (low >= high)
		return;

	int mid = low + (high - low) / 2;
	MergeSort(a, tmp, low, mid);
	MergeSort(a, tmp, mid+1, high);
	Merge(a, tmp, low, mid, high);
}


//////////////////////////////////////////////////////////////////////
/*
 稳定，非原地，时间复杂度O(nlogn)
*/

/*std::vector<int> Merge(std::vector<int> vec1, std::vector<int> vec2)
{
	std::vector<int> result;
	int i = 0, j = 0;
	while (i < vec1.size() && j < vec2.size())
	{
		if (vec1[i] < vec2[j])
		{
			result.push_back(vec1[i]);
			i++;
		}
		else
		{
			result.push_back(vec2[j]);
			j++;
		}
	}

	if (i < vec1.size())
	{
		result.insert(result.end(), vec1.begin() + i, vec1.end());
	}
	else
	{
		result.insert(result.end(), vec2.begin() + j, vec2.end());
	}

	return result;
}

std::vector<int> MergeSort(std::vector<int> vec)
{
	if (vec.size() <= 1)
	{
		return vec;
	}
	else
	{
		return Merge(MergeSort(std::vector<int>(vec.begin(), vec.begin() + vec.size() / 2)), 
			         MergeSort(std::vector<int>(vec.begin() + vec.size()/2, vec.end())));
	}
}*/
