#include "linkstack.h"
#include "membase.h"

#include <stdio.h>
#include <assert.h>

typedef struct LSKMemory 
{
	int32_t  nData;
	int32_t *pData;

	int32_t  peak;
}LSKMemory;

int32_t lskCalc( int32_t nNode )
{
	LSKMemory *p = 0;
	uint8_t *pBuf = 0;

	if (nNode <= 0)
	{
		return 0;
	}

	ALIGN_CALMEM(p, pBuf, 1, LSKMemory);
	ALIGN_CALMEM(p->pData, pBuf, nNode, int32_t);

	return (int32_t)(pBuf + 32);
}

int32_t lskInit( void *handle,int32_t nNode )
{
	LSKMemory *p = 0;
	uint8_t *pBuf = 0;

	if (!handle || nNode <= 0)
	{
		return -1;
	}

	pBuf = ALIGN_16BYTE(handle);
	ALIGN_ALLOCATE(p, pBuf, 1, LSKMemory);
	ALIGN_ALLOCATE(p->pData, pBuf, nNode, int32_t);

	p->peak = -1;
	p->nData = nNode;

	return 0;
}

int32_t lskPop( void *handle,int32_t *elem )
{
	int32_t idx;
	LSKMemory *p = (LSKMemory *)ALIGN_16BYTE(handle);

	assert(p != 0);

	idx = p->peak;
	if (idx > -1)
	{
		p->peak--;
	}else
	{
		return 0;
	}

	*elem = p->pData[idx];

	return 1;
}

int32_t lskPush( void *handle,int32_t elem )
{
	int32_t idx;
	LSKMemory *p = (LSKMemory *)ALIGN_16BYTE(handle);

	assert(p != 0);

	idx = p->peak + 1;
	if (idx < p->nData)
	{
		p->pData[idx] = elem;
		p->peak = idx;
	}else
	{
		return 0;
	}

	return 1;
}

int32_t lskState( void *handle )
{
	int32_t flag;
	LSKMemory *p = (LSKMemory *)ALIGN_16BYTE(handle);
	
	assert(p != 0);

	if (p->peak < 0)
	{
		flag = -1;
	}else if (p->peak >= p->nData)
	{
		flag = 1;
	}else
	{
		flag = 0;
	}
	
	return flag;
}

void lskShow( void *handle )
{
	int32_t i;
	LSKMemory *p = (LSKMemory *)ALIGN_16BYTE(handle);

	assert(p != 0);

	printf("show static : %d data\n",p->peak+1);
	for (i = 0; i <= p->peak; i++)
	{
		printf("%d ",p->pData[i]);
	}
	printf("\n");
}

int32_t lskSize( void *handle )
{
	LSKMemory *p = (LSKMemory *)ALIGN_16BYTE(handle);

	assert(p != 0);

	return p->peak + 1;
}

int32_t lskCapacity( void *handle )
{
	LSKMemory *p = (LSKMemory *)ALIGN_16BYTE(handle);
	
	assert(p != 0);

	return p->nData;
}

void lskClean( void *handle )
{
	LSKMemory *p = (LSKMemory *)ALIGN_16BYTE(handle);

	assert(p != 0);

	p->peak = -1;
}

const int32_t* lskDataHead( void *handle )
{
	LSKMemory *p = (LSKMemory *)ALIGN_16BYTE(handle);

	assert(p != 0);

	return p->pData;
}

