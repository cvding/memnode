/*********************************************************************
 *	Copyright 1992-2008, ZheJiang HuaRay Technology Stock Co.Ltd.
 *						All Rights Reserved
 *	@file 	    		xvmem.h
 *	@author				dzf
 *	@brief				内存计算、划分相关基础宏定义
 *  
 *
 *	@date	        	2016:12:14 
 *	@version			1.00.1
 *	@todo				
**********************************************************************/
#ifndef __MEMBASE_H__
#define __MEMBASE_H__

#include <stdint.h>

#ifdef WIN32
#pragma warning(disable:4311 4312)
#endif // WIN32


/** 16字节地址对齐 */
#ifndef ALIGN_16BYTE
#define ALIGN_16BYTE(x) ((uint8_t*)(((uint32_t)(x) + 15) >> 4 << 4))
#endif

/** 内存对齐分配 */
#ifndef ALIGN_ALLOCATE
#define ALIGN_ALLOCATE(pDst, pBuf, size, type) \
{ \
    pBuf = ALIGN_16BYTE(pBuf); \
    pDst = (type *)pBuf; \
    pBuf = pBuf + (size) * sizeof(type); \
}
#endif

/** 内存对其计算 */
#ifndef ALIGN_CALMEM
#define ALIGN_CALMEM(pDst, pBuf, size, type) \
{ \
    pBuf = ALIGN_16BYTE(pBuf); \
    pBuf = pBuf + (size) * sizeof(type); \
}
#endif

#endif







