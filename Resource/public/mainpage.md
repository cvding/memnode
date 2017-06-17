# ����任��
> ������ϵ�ж�����4�ַ���任��ƽ�ƣ����ţ���ת�����У���ض�Ӧ��������ο����ĵ�

### 1. 4�ֱ任����ͼ��ʾ
![Affine](d:/WorkRoot/dddz/code/homegit/affine/Resource/public/Affine.png)
### 2. �任��ʽ����ͼ��ʾ
![Formula](d:/WorkRoot/dddz/code/homegit/affine/Resource/public/Formule.png)<br />
**����Q=Ry - Rx**

### 3. ��Ҫע�������
- ��ȷ����任ǰ������ϵ
- ��ȷ���������������������ϵ

### 4. һ���򵥵�ʾ��

```c
#include <stdio.h>
#include "Affine.h"
int32_t main()
{
	const float r = 3.1415926f / 4;
	/* ���÷���ϵ�� */
	skaffine coef = mvSetAffine(1, 1, r, 0, 1, 1);
	skamatrix trans;

	/* ������ϵ��ת��Ϊ������� */
	mvAffine2Matrix(&coef, &trans);

	skpointf src, dst;

	src.x = 0;
	src.y = 0;

	/* �������(0,0) �����任ת��Ϊ(-1.414,0) */
	mvMapPoint(&src, &trans, &dst);

	printf("(%f,%f) ==> (%f,%f)\n", src.x, src.y, dst.x, dst.y);

	return 0;
}
```
��ͼʾ��:<br />
![Coordinate](d:/WorkRoot/dddz/code/homegit/affine/Resource/public/Coordinate.png)<br />
ƽ��A��һ��(0,0)��ƽ��B�д���(-1.414,0)λ��