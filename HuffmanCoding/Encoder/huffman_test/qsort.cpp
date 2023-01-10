#include "Node.h"

void Extract_symbol(Data* data, uint8 code_symbol, uint8* index)
{
	//첫번째 심볼값은 0번째 인덱스에 저장

	if (*index == 0)
	{
		data->symbol[0] = code_symbol;
		data->freq[0]++;

		(*index)++;
	}

	//두번째 부터는 앞에 값과 비교
	else
	{
		for (int i = 0; i < *(index); i++)
		{
			if (data->symbol[i] == code_symbol)		//현재 입력으로 들어오는 심볼값이랑 이전에 있던 심볼값이랑 같은 경우 비교를 중지
			{
				data->freq[i]++;
				break;
			}

			if (i == *(index)-1)				//마지막원소까지 비교했는데도 같은 값이 없으면 현재 인덱스에 심볼값 저장
			{
				data->symbol[(*index)++] = code_symbol;
			}
		}
	}

	printf("");
}

void QuickSort(Node** nodeArr, int left, int right)
{
	int L = left;
	int R = right;

	Node* pivot = nodeArr[(L + R) / 2];

	do
	{
		while (nodeArr[L]->freq < pivot->freq)
			L++;
		while (nodeArr[R]->freq > pivot->freq)
			R--;

		if (L <= R)
		{
			swap(&nodeArr[L], &nodeArr[R]);
			L++; R--;
		}

	} while (L <= R);

	//피봇 기준으로

	//왼쪽 정렬: R이 음수가 되면, 왼쪽 배열은 공집합이므로 정렬x
	if (left < R)
		QuickSort(nodeArr, left, R);

	//오른쪽 정렬: L이 분할된 배열의 오른쪽 끝에 도달하면 정렬x
	if (right > L)
		QuickSort(nodeArr, L, right);
}

void swap(Node **left, Node **right)
{
	Node* tmp = *left;
	*left = *right;
	*right = tmp;
}