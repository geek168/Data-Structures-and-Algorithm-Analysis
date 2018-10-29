#include "hashtable.h"

void init(HashTable *h, int size)
{
	h->size = size;
	h->elem = (char **)malloc(sizeof(char *) * size);
	for (int i = 0; i < size; i++)
	{
		h->elem[i] = NULL;
	}
}

int hash(HashTable *h, char value[])
{
	int code = 0;
	for (int i = 0; i < strlen(value); i++)
	{
		code = (code * 256 + value[i] + 128) % h->size;
	}
	return code;
}

int search(HashTable *h, char value[], int *pos, int *times)
{
	*pos = hash(h, value);
	*times = 0;

	while (h->elem[*pos] != NULL && strcmp(h->elem[*pos], value) != 0) // ����hash��ͻ
	{
		(*times)++;
		if (*times < h->size) 
		{
			*pos = (*pos + 1) % h->size; //���Լ�1
		}
		else 
		{
			return 0;
		}
	}
	if (h->elem[*pos] != NULL && strcmp(h->elem[*pos], value) == 0) //�ܹ��ҵ�
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void recreate(HashTable *h)
{
	char **temp_elem;
	temp_elem = (char **)malloc(sizeof(char *) * h->size);
	for (int i = 0; i < h->size; i++)
	{
		if (h->elem[i] != NULL)
		{
			temp_elem[i] = (char *)malloc(strlen(h->elem[i]) + 1);
			strcpy(temp_elem[i], h->elem[i]);
		}
		else
		{
			temp_elem[i] = NULL;
		}
	}
	for (int i = 0; i < h->size; i++)
	{
		if (h->elem[i] != NULL)
		{
			free(h->elem[i]);
		}
	}
	free(h->elem);

	int copy_size = h->size;
	h->size = h->size * 2;
	h->elem = (char **)malloc(sizeof(char *) * h->size);
	for (int i = 0; i < h->size; i++)
	{
		h->elem[i] = NULL;
	}
	for (int i = 0; i < copy_size; i++)
	{
		if (temp_elem[i] != NULL)
		{
			insert(h, temp_elem[i]);
		}
	}
	for (int i = 0; i < copy_size; i++)
	{
		if (temp_elem[i] != NULL)
		{
			free(temp_elem[i]);
		}
	}
	free(temp_elem);
}

int insert(HashTable *h, char value[])
{
	int pos, times;
	if (search(h, value, &pos, &times)) //����
	{
		return 2;
	}
	else if (times < h->size / 2) //��ͻС��һ���С
	{
		h->elem[pos] = (char *)malloc(strlen(value) + 1);
		strcpy(h->elem[pos], value);
		return 1;
	}
	else 
	{
		recreate(h);
		insert(h, value);
		return 0;
	}
}

void clear(HashTable *h) 
{
	for (int i = 0; i < h->size; ++i) 
	{
		if (h->elem[i] != NULL) 
		{
			free(h->elem[i]);
		}
	}
	free(h->elem);
	free(h);
}