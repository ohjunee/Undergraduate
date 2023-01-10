#include "Node.h"

void memory_alloc1D(Data* data, uint8 size)
{
	data->input_sequence = (uint8*)calloc(sizeof(uint8), size);
	data->symbol		 = (uint8*)calloc(sizeof(uint8), size);
	data->freq			 = (uint8*)calloc(sizeof(uint8), size);
	
	data->bitCnt = 0;
	data->output = 0;
}

void memory_free1D(Data* data)
{
	free(data->input_sequence);
	free(data->symbol);
	free(data->freq);
}

void free_Tree(Node* node)
{
	if (node->left != NULL)
	{
		free_Tree(node->left);
		node->left = NULL;
	}

	if (node->right != NULL)
	{
		free_Tree(node->right);
		node->right = NULL;
	}

	if (isEndNode(node))// ��������� ���, �ش� �ɺ����� ����ϰ� ��ȣ�����
	{
		free(node);
	}
}
