/*******************************************************************
 *    COPYRIGHT NOTICE
 *    Copyright 1992-2025, ZheJiang Dahua Technology Stock Co.Ltd.
 *                         All Rights Reserved.  
 *  
 * @file    memnode.h
 * @brief   �ڵ��ڴ����
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
	/** �����ڴ��С
	 *    
	 * @param [in] nNode �ڴ�ڵ�����
	 * @param [in] nodeSize ���ڵ��ڴ��С
	 * @return int32_t �ڴ��С
	 * @note 
	 */

	 int32_t mnCalc(int32_t nNode,int32_t nodeSize);

	/** ��ʼ���ڴ�
	 *    
	 * @param [in] handle �ڴ���
	 * @param [in] nNode �ڴ�ڵ�����
	 * @param [in] nodeSize ���ڵ��ڴ��С
	 * @return int32_t �ڴ��С
	 * @note 
	 */
	 int32_t mnInit(void *handle,int32_t nNode,int32_t nodeSize);

	/** ����ڵ�
	 *    
	 * @param [in] handle �ڴ���
	 * @return void* ���뷵��ָ��
	 * @note
	 */
	 void* mnMalloc(void *handle);

	/** �ͷŽڵ�
	 *    
	 * @param [in] handle �ڴ���
	 * @param [in] pNode �ڴ�ڵ�ָ��
	 * @return void
	 * @note
	 */
	 void mnFree(void *handle,void **pNode);

	/** �ڴ�ڵ�����
	 *    
	 * @param [in] handle �ڴ���
	 * @return int32_t �ڴ�ڵ�����
	 * @note
	 */
	 int32_t mnCapacity(void *handle);

	/** ����ڵ��¼
	 *    
	 * @param [in] handle �ڴ���
	 * @return void
	 * @note
	 */
	 void mnClean(void *handle);

#ifdef __cplusplus
};
#endif // __cplusplus
#endif // __XVMEMORY_H__