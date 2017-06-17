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
	/** ����ջ�ڴ��С
	 *    
	 * @param [in] nNode �ڵ�����
	 * @return int32_t ջ�ڴ��С
	 * @note
	 */
	int32_t lskCalc(int32_t nNode);

	/** ��ʼ��ջ�ڴ�
	 *    
	 * @param [in] handle ջ���
	 * @param [in] nNode �ڵ�����
	 * @return int32_t ��ʼ��״̬
	 * @note 
	 */
	int32_t lskInit(void *handle,int32_t nNode);

	/** Ԫ�س�ջ
	 *    
	 * @param [in] handle ջ���
	 * @param [in] elem ��ջԪ��
	 * @return int32_t ��ջ״̬
	 * @note �����ʾ�ɹ�
	 */
	int32_t lskPop(void *handle,int32_t *elem);

	/** Ԫ����ջ
	 *    
	 * @param [in] handle ջ���
	 * @param [in] elem ��ջԪ��
	 * @return int32_t ��ջ״̬
	 * @note �����ʾ�ɹ�
	 */
	int32_t lskPush(void *handle,int32_t elem);

	/** ջ״̬
	 *    
	 * @param [in] handle ջ���
	 * @return int32_t ջ״̬
	 * @note -1:ջ�� 1:ջ�� 0:�м� 
	 */
	int32_t lskState(void *handle);

	/** ��ʾջԪ��
	 *    
	 * @param [in] handle ջ���
	 * @return void
	 * @note
	 */
	void lskShow(void *handle);

	/** ջ��ǰ��С
	 *    
	 * @param [in] handle ջ���
	 * @return int32_t ջ��Ԫ������
	 * @note
	 */
	int32_t lskSize(void *handle);

	/** ջ������С
	 *    
	 * @param [in] handle ջ���
	 * @return int32_t ջ������С
	 * @note
	 */
	int32_t lskCapacity(void *handle);

	/** ���ջ����
	 *    
	 * @param [in] handle ջ���
	 * @return void
	 * @note
	 */
	void lskClean(void *handle);

	/** ջͷָ��
	 *    
	 * @param [in] handle ջ���
	 * @return const int32_t* ջͷָ��
	 * @note
	 */
	const int32_t* lskDataHead(void *handle);

#ifdef __cplusplus
};
#endif // __cplusplus
#endif // __XVLINKSTACK_H__