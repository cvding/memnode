/*******************************************************************
 *    COPYRIGHT NOTICE
 *    Copyright 1992-2025, ZheJiang Dahua Technology Stock Co.Ltd.
 *                         All Rights Reserved.  
 *  
 * @file    memnode.h
 * @brief   节点内存分配
 *   
 *  
 * @version 1.0 
 * @author   
 * @date    2016:2:22 
 *  
 * @attention 
 *   
 *******************************************************************/
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
	/** 计算内存大小
	 *    
	 * @param [in] nNode 内存节点数量
	 * @param [in] nodeSize 单节点内存大小
	 * @return int32_t 内存大小
	 * @note 
	 */

	 int32_t mnCalc(int32_t nNode,int32_t nodeSize);

	/** 初始化内存
	 *    
	 * @param [in] handle 内存句柄
	 * @param [in] nNode 内存节点数量
	 * @param [in] nodeSize 单节点内存大小
	 * @return int32_t 内存大小
	 * @note 
	 */
	 int32_t mnInit(void *handle,int32_t nNode,int32_t nodeSize);

	/** 申请节点
	 *    
	 * @param [in] handle 内存句柄
	 * @return void* 申请返回指针
	 * @note
	 */
	 void* mnMalloc(void *handle);

	/** 释放节点
	 *    
	 * @param [in] handle 内存句柄
	 * @param [in] pNode 内存节点指针
	 * @return void
	 * @note
	 */
	 void mnFree(void *handle,void **pNode);

	/** 内存节点容量
	 *    
	 * @param [in] handle 内存句柄
	 * @return int32_t 内存节点容量
	 * @note
	 */
	 int32_t mnCapacity(void *handle);

	/** 清除节点记录
	 *    
	 * @param [in] handle 内存句柄
	 * @return void
	 * @note
	 */
	 void mnClean(void *handle);

#ifdef __cplusplus
};
#endif // __cplusplus
#endif // __XVMEMORY_H__