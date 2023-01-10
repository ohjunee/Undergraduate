#include "Node.h"
#include "input.h"

void initialize(Data* data, Node** tail, int n_symbol)
{
	for (int i = 0; i < n_symbol; i++)
	{
		Node* node		= (Node*)malloc(sizeof(Node));

		node->freq		= data->freq[i];				//발생횟수
		node->symbol	= data->symbol[i];				//심볼값

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

	/* 노드 정렬 */
	QuickSort(nodeArr, 0, *n_symbol);								// 노드를 심볼값의 발생확률에 대해 오름차순으로 정렬

	Node** newLayer;												// 이진트리에서 새로 만들어진 노드 층

	Node* newNode = (Node*)malloc(sizeof(Node));					// 합쳐진 노드 메모리 할당

	newNode->left = nodeArr[0];
	newNode->right = nodeArr[1];

	newNode->freq = nodeArr[0]->freq + nodeArr[1]->freq;			// 합쳐진 노드의 빈도 수
	newNode->symbol = 0;

	/* 이진트리에서 새로 만들어진 노드 층 */
	newLayer	= createNextFloor(newNode, nodeArr, *n_symbol);
	result		= newNode;

	if (*n_symbol > 1)
	{
		/* 노드 합치기 */
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
	/* 현재 노드의 자식노드 탐색 */

	//왼쪽 자식노드가 존재하면
	if (node->left != NULL)
	{
		codeword[index] = 0;
		Tree_traversal(node->left, data ,symbol, codeword, index + 1);
	}

	//오른쪽 자식노드가 존재하면
	if (node->right != NULL)
	{
		codeword[index] = 1;
		Tree_traversal(node->right, data, symbol, codeword, index + 1);
	}

	// 현재 노드의 자식노드가 NULL인 경우 꼬리노드이므로, 해당 심볼값을 출력하고 부호어출력
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