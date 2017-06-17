/*******************************************************************
 *    COPYRIGHT NOTICE
 *    Copyright 1992-2025, ZheJiang Dahua Technology Stock Co.Ltd.
 *                         All Rights Reserved.  
 *  
 * @file    LinkStack.h 
 * @brief   link list(elem type == int)
 *   
 *  
 * @version 1.0 
 * @author   
 * @date    2016:2:22 
 *  
 * @attention 
 *   
 *******************************************************************/
#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include <stdint.h>


#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
	/** 计算栈内存大小
	 *    
	 * @param [in] nNode 节点数量
	 * @return int32_t 栈内存大小
	 * @note
	 */
	int32_t lskCalc(int32_t nNode);

	/** 初始化栈内存
	 *    
	 * @param [in] handle 栈句柄
	 * @param [in] nNode 节点数量
	 * @return int32_t 初始化状态
	 * @note 
	 */
	int32_t lskInit(void *handle,int32_t nNode);

	/** 元素出栈
	 *    
	 * @param [in] handle 栈句柄
	 * @param [in] elem 出栈元素
	 * @return int32_t 出栈状态
	 * @note 非零表示成功
	 */
	int32_t lskPop(void *handle,int32_t *elem);

	/** 元素入栈
	 *    
	 * @param [in] handle 栈句柄
	 * @param [in] elem 入栈元素
	 * @return int32_t 入栈状态
	 * @note 非零表示成功
	 */
	int32_t lskPush(void *handle,int32_t elem);

	/** 栈状态
	 *    
	 * @param [in] handle 栈句柄
	 * @return int32_t 栈状态
	 * @note -1:栈空 1:栈满 0:中间 
	 */
	int32_t lskState(void *handle);

	/** 显示栈元素
	 *    
	 * @param [in] handle 栈句柄
	 * @return void
	 * @note
	 */
	void lskShow(void *handle);

	/** 栈当前大小
	 *    
	 * @param [in] handle 栈句柄
	 * @return int32_t 栈中元素数量
	 * @note
	 */
	int32_t lskSize(void *handle);

	/** 栈容量大小
	 *    
	 * @param [in] handle 栈句柄
	 * @return int32_t 栈容量大小
	 * @note
	 */
	int32_t lskCapacity(void *handle);

	/** 清除栈内容
	 *    
	 * @param [in] handle 栈句柄
	 * @return void
	 * @note
	 */
	void lskClean(void *handle);

	/** 栈头指针
	 *    
	 * @param [in] handle 栈句柄
	 * @return const int32_t* 栈头指针
	 * @note
	 */
	const int32_t* lskDataHead(void *handle);

#ifdef __cplusplus
};
#endif // __cplusplus
#endif // __XVLINKSTACK_H__