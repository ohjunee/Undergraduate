#include "Node.h"
#include "input.h"

void encoding(Data* data, int* pred_err, uint8 p_size)
{
	uint8 sign, absErr, index = 0;

	for (int i = 0; i < p_size*p_size; i++)
	{
		sign = (pred_err[i] < 0) ? 1 : 0;
		write_Sign(data, sign);
	}

	printf("\n");

	for (int i = 0; i < p_size*p_size; i++)
	{
		data->input_sequence[i] = absErr = abs(pred_err[i]);
		Extract_symbol(data, absErr, &index);
	}
	
	Huffman_Coding(data, index, PSIZE);
	printf("");
}

void Send_Table(Data* data, uint8 n_symbol)
{
	//n_symbol: 양자화된 변환계수 블록에서 관찰되는 심볼 갯수 정보 보내주기
	fwrite(&n_symbol, sizeof(uint8), 1, data->fp_out);

	//관찰된 심볼 값 차례로 보내기
	for (int i = 0; i < n_symbol; i++)
	{
		fwrite(&data->symbol[i], sizeof(uint8), 1, data->fp_out);
	}

	//심볼의 발생 빈도수를 차례로 보내기
	for (int i = 0; i < n_symbol; i++)
	{
		fwrite(&data->freq[i], sizeof(uint8), 1, data->fp_out);
	}
}
void Huffman_Coding(Data* data, uint8 n_symbol, uint8 p_size)
{
	int* codeword = (int*)calloc(sizeof(int), p_size*p_size);
	int start_index = 0;

	Node*	head = NULL;																	// 머리노드 생성, 자식노드는 모두 NULL로 초기화
	Node**	tail = (Node**)malloc(sizeof(Node*)*n_symbol);

	initialize(data, tail, n_symbol);

	Send_Table(data, n_symbol);

	head = create_HuffmanTree(tail, &n_symbol);												// 머리 노드를 허프만 트리와 연결

	for (int i = 0; i < p_size*p_size; i++)
	{
		Tree_traversal(head, data, data->input_sequence[i], codeword, start_index);			// 전위 순회하여 왼쪽 꼬리노드부터 탐색
	}

	if (data->bitCnt)
	{
		printf("\n");
		printf("남은 비트값: ");
		printf("%u", data->output);
		data->output <<= 8 - data->bitCnt;
		fwrite(&data->output, sizeof(uint8), 1, data->fp_out);
	}

	free_Tree(head);																		// 전위 순회방식으로 메모리 순차 해제
	free(codeword);
}

void write_Sign(Data* data, uint8 code_symbol)
{
	data->output = data->output << 1 | code_symbol;
	data->bitCnt++;

	if (data->bitCnt == 8)
	{
		printf("%u \n", data->output);
		fwrite(&data->output, sizeof(uint8), 1, data->fp_out);
		data->output = 0;
		data->bitCnt = 0;
	}
}