#include "Node.h"

void Extract_symbol(Data* data, uint8 code_symbol, uint8* index)
{
	//ù��° �ɺ����� 0��° �ε����� ����

	if (*index == 0)
	{
		data->symbol[0] = code_symbol;
		data->freq[0]++;

		(*index)++;
	}

	//�ι�° ���ʹ� �տ� ���� ��
	else
	{
		for (int i = 0; i < *(index); i++)
		{
			if (data->symbol[i] == code_symbol)		//���� �Է����� ������ �ɺ����̶� ������ �ִ� �ɺ����̶� ���� ��� �񱳸� ����
			{
				data->freq[i]++;
				break;
			}

			if (i == *(index)-1)				//���������ұ��� ���ߴµ��� ���� ���� ������ ���� �ε����� �ɺ��� ����
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

	//�Ǻ� ��������

	//���� ����: R�� ������ �Ǹ�, ���� �迭�� �������̹Ƿ� ����x
	if (left < R)
		QuickSort(nodeArr, left, R);

	//������ ����: L�� ���ҵ� �迭�� ������ ���� �����ϸ� ����x
	if (right > L)
		QuickSort(nodeArr, L, right);
}

void swap(Node **left, Node **right)
{
	Node* tmp = *left;
	*left = *right;
	*right = tmp;
}