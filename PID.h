#ifndef __PID_H
#define	__PID_H


void IncPIDInit(void);/*Initialize PID Structure  PID参数初始化*/

int IncPIDCalc(int NowPoint ,int SetSpeed);/*增量式PID计算部分 */


#endif /* __PID_H */
