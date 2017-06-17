#include "memnode.h"
#include "linkstack.h"
#include "membase.h"
#include <math.h>
#include <memory.h>
#include <assert.h>

typedef struct MMN_Memory 
{
	int32_t nNode;
	int32_t nodeSize;
	void *pNode;
	void *pStack;
}MMN_Memory;

int32_t mnCalc( int32_t nNode,int32_t nodeSize )
{
	MMN_Memory *p = 0;
	uint8_t *pBuf = 0;
	int32_t memSize;

	if (nNode <= 0 || nodeSize <= 0)
	{
		return -1;
	}
	
	ALIGN_CALMEM(p,pBuf,1,MMN_Memory);
	ALIGN_CALMEM(p->pNode, pBuf, nNode*nodeSize, uint8_t);

	memSize = lskCalc(nNode);
	ALIGN_CALMEM(p->pStack, pBuf, memSize, uint8_t);
	

	return (int32_t)(pBuf + 32);
}

int32_t mnInit( void *handle,int32_t nNode,int32_t nodeSize )
{
	MMN_Memory *p = 0;
	uint8_t *pBuf = 0;
	int32_t memSize;
	int32_t fidx;

	if (!handle || nNode <= 0 || nodeSize <= 0)
	{
		return -1;
	}

	pBuf = ALIGN_16BYTE(handle);
	ALIGN_ALLOCATE(p,pBuf,1,MMN_Memory);
	ALIGN_ALLOCATE(p->pNode, pBuf, nNode*nodeSize, uint8_t);

	memSize = lskCalc(nNode);
	ALIGN_ALLOCATE(p->pStack, pBuf, memSize, uint8_t);
	lskInit(p->pStack, nNode);

	p->nNode = nNode;
	p->nodeSize = nodeSize;

	for (fidx = nNode - 1; fidx >= 0; fidx--)
	{
		lskPush(p->pStack, fidx);
	}

	return 0;
}

void* mnMalloc( void *handle )
{
	MMN_Memory *p;
	int32_t fidx;

	if (!handle)
	{
#ifdef _DEBUG
		perror("error : no memory handle");
#endif
		return 0;
	}

	p = (MMN_Memory *)ALIGN_16BYTE(handle);

	if (!lskPop(p->pStack,&fidx))
	{
#ifdef _DEBUG
		perror("error : no free memory node");
#endif
		return 0;
	}else
	{
		return (uint8_t *)p->pNode + fidx * p->nodeSize;
	}
}

void mnFree( void *handle,void **pNode )
{
	int32_t fidx;
	MMN_Memory *p;
	if (handle && pNode)
	{
		p = (MMN_Memory *)ALIGN_16BYTE(handle);
		fidx = ((uint8_t *)(*pNode) - (uint8_t *)p->pNode) / p->nodeSize;
		lskPush(p->pStack, fidx);
		*pNode = 0;
	}
}

int32_t mnCapacity( void *handle )
{
	MMN_Memory *p;

	if (!handle) return -1;

	p = (MMN_Memory *)ALIGN_16BYTE(handle);

	return p->nNode;
}

void mnClean( void *handle )
{
	int32_t i;
	MMN_Memory *p;

	p = (MMN_Memory *)ALIGN_16BYTE(handle);

	assert(p != 0);

	lskClean(p->pStack);
	for (i = p->nNode - 1; i >= 0; i--)
	{
		lskPush(p->pStack,i);
	}
}

