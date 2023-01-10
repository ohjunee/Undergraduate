#include "Node.h"
#include "input.h"

void Read_Sign(Data* data, int* predErr_blk, uint8 p_size)
{
	uint8 buffer, sign, cnt = 0;
	uint8 check_bit = 128;

	fread(&buffer, sizeof(uint8), 1, data->fp_in);

	for (int i = 0; i < p_size*p_size; i++)
	{
		sign = buffer << cnt & check_bit;
		predErr_blk[i] = pow(-1, sign);
		cnt++;

		if (cnt == 8)
		{
			fread(&buffer, sizeof(uint8), 1, data->fp_in);
			cnt = 0;
		}
	}
}

void Read_AbsVal(Data* data, int* predErr_blk, uint8 p_size)
{
	//������ Ʈ�������
	Huffman_Coding(data, data->n_symbol, p_size);

	//������� Ʈ�������� ���� ��Ʈ��Ʈ�� �б�
}

void Read_Table(Data* data, uint8 p_size)
{
	fread(&data->n_symbol, sizeof(uint8), 1, data->fp_in);

	memory_alloc1D(data);

	for (int i = 0; i < data->n_symbol; i++)
	{
		fread(&data->symbol[i], sizeof(uint8), 1, data->fp_in);
	}

	for (int i = 0; i < data->n_symbol; i++)
	{
		fread(&data->freq[i], sizeof(uint8), 1, data->fp_in);
	}
}


void Read_PredErr(Data* data, int* predErr_blk, uint8 p_size)
{
	Read_Sign	(data, predErr_blk, p_size);

	Read_Table	(data, p_size);
	Read_AbsVal	(data, predErr_blk, p_size);
}

void decoding(Node* node, Data* data, uint8 p_size)
{
	uint8 sign, absErr, n_symbol = 0;
	
	int* predErr_blk = (int*)calloc(sizeof(int), p_size*p_size);

	Read_PredErr	(data, predErr_blk, p_size);

	printf("");

	free(predErr_blk);
}


void Huffman_Coding(Data* data, uint8 n_symbol, uint8 p_size)
{
	int* codeword = (int*)calloc(sizeof(int), p_size*p_size);
	int start_index = 0;

	Node*	head = NULL;																	// �Ӹ���� ����, �ڽĳ��� ��� NULL�� �ʱ�ȭ
	Node**	tail = (Node**)malloc(sizeof(Node*)*n_symbol);

	initialize(data, tail, n_symbol);

	head = create_HuffmanTree(tail, &n_symbol);												// �Ӹ� ��带 ������ Ʈ���� ����

	for (int i = 0; i < p_size*p_size; i++)
	{
		Tree_traversal(head, data, data->input_sequence[i], codeword, start_index);			// ���� ��ȸ�Ͽ� ���� ���������� Ž��
	}

	if (data->bitCnt)
	{
		printf("\n");
		printf("���� ��Ʈ��: ");
		printf("%u", data->output);
		data->output <<= 8 - data->bitCnt;
		fwrite(&data->output, sizeof(uint8), 1, data->fp_out);
	}
	free_Tree(head);																		// ���� ��ȸ������� �޸� ���� ����
	free(codeword);
}

