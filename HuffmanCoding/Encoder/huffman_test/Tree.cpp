#include "Node.h"
#include "input.h"

void initialize(Data* data, Node** tail, int n_symbol)
{
	for (int i = 0; i < n_symbol; i++)
	{
		Node* node		= (Node*)malloc(sizeof(Node));

		node->freq		= data->freq[i];				//�߻�Ƚ��
		node->symbol	= data->symbol[i];				//�ɺ���

		node->left = NULL;
		node->right = NULL;

		tail[i] = node;
	}
}

void write_AbsValue(Data* data, int codeword[], int index)
{
	int buffer = 0;

	for (int i = 0; i < index; i++)
	{
		buffer = codeword[i];
		data->output = data->output << 1 | buffer;
		data->bitCnt++;

		if (data->bitCnt == 8)
		{
			printf("%u", data->output);
			fwrite(&data->output, sizeof(uint8), 1, data->fp_out);
			data->output = 0;
			data->bitCnt = 0;
		}
	}
	printf("\n");
}

Node* create_HuffmanTree(Node** nodeArr, uint8* n_symbol)
{
	Node* result;

	(*n_symbol)--;

	/* ��� ���� */
	QuickSort(nodeArr, 0, *n_symbol);								// ��带 �ɺ����� �߻�Ȯ���� ���� ������������ ����

	Node** newLayer;												// ����Ʈ������ ���� ������� ��� ��

	Node* newNode = (Node*)malloc(sizeof(Node));					// ������ ��� �޸� �Ҵ�

	newNode->left = nodeArr[0];
	newNode->right = nodeArr[1];

	newNode->freq = nodeArr[0]->freq + nodeArr[1]->freq;			// ������ ����� �� ��
	newNode->symbol = 0;

	/* ����Ʈ������ ���� ������� ��� �� */
	newLayer	= createNextFloor(newNode, nodeArr, *n_symbol);
	result		= newNode;

	if (*n_symbol > 1)
	{
		/* ��� ��ġ�� */
		result = create_HuffmanTree(newLayer, n_symbol);
	}

	return result;
}

Node** createNextFloor(Node* newNode, Node** nodeArr, uint8 arrLen)
{
	Node** newNodeArr = (Node**)malloc(sizeof(Node*) * arrLen);

	newNodeArr[0] = newNode;

	for (int i = 1; i < arrLen; i++)
	{
		newNodeArr[i] = nodeArr[i + 1];
	}
	return newNodeArr;
}


void Tree_traversal(Node* node, Data* data, uint8 symbol, int codeword[], int index)
{
	/* ���� ����� �ڽĳ�� Ž�� */

	//���� �ڽĳ�尡 �����ϸ�
	if (node->left != NULL)
	{
		codeword[index] = 0;
		Tree_traversal(node->left, data ,symbol, codeword, index + 1);
	}

	//������ �ڽĳ�尡 �����ϸ�
	if (node->right != NULL)
	{
		codeword[index] = 1;
		Tree_traversal(node->right, data, symbol, codeword, index + 1);
	}

	// ���� ����� �ڽĳ�尡 NULL�� ��� ��������̹Ƿ�, �ش� �ɺ����� ����ϰ� ��ȣ�����
	else
	{
		if (symbol == node->symbol)
		{
			printf("%d ", node->symbol);
			write_AbsValue(data ,codeword, index);
			printf("");
		}
	}
}

bool isEndNode(Node* node)
{
	return (node->left == NULL) && (node->right == NULL);
}