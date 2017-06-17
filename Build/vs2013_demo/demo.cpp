#include <stdio.h>
#include <stdlib.h>
#include "memnode.h"

#ifdef _DEBUG
#pragma comment(lib, "memnoded.lib")
#else
#pragma comment(lib, "memnode.lib")
#endif

typedef struct Value
{
	int32_t pasid;
	char    name[20];
}Value;

int main()
{
	int32_t memSize = mnCalc(10, sizeof(Value));

	void *handle = malloc(memSize);

	mnInit(handle, 10, sizeof(Value));
	
	// you can malloc max mnCapcity() number node
	// one time one node
	Value *node = (int32_t *)mnMalloc(handle);
	mnFree(&node);

	free(handle);

	return 0;
}