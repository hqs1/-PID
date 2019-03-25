#include "PID.h"





#define Proportion  0.8 //�������� Proportional Const
#define Integral    0.5 //���ֳ��� Integral Const
#define Derivative  0.1 //΢�ֳ��� Derivative Const

//#define Proportion  0.62 //�������� Proportional Const
//#define Integral    0.45 //���ֳ��� Integral Const
//#define Derivative  0.1 //΢�ֳ��� Derivative Const
int LastError; //Error[-1]
int PrevError; //Error[-2]
int SetPoint; //�趨Ŀ�� Desired Value

//
/*==================================================================================================== 
PID Function 
The PID (���������֡�΢��) function is used in mainly 
control applications. PIDCalc performs one iteration of the PID 
algorithm. 
While the PID function works, main is just a dummy program showing 
a typical usage. 
=====================================================================================================*/  


/*==================================================================================================== 
Initialize PID Structure  PID������ʼ��
=====================================================================================================*/
void IncPIDInit(void)
{

	LastError = 0; //Error[-1]
	PrevError = 0; //Error[-2]
	SetPoint = 0;
}
 
/*==================================================================================================== 
����ʽPID���㲿�� 
=====================================================================================================*/
int IncPIDCalc(int NowPoint ,int SetSpeed)
{

	//register int iError, iIncpid; //��ǰ���
	int iError, iIncpid; //��ǰ���
	
	SetPoint = SetSpeed;//����Ŀ��ֵ
	
	iError = SetPoint - NowPoint;//�������㣬�������ǰֵ��Ŀ��ֵ�����ֵ
	
	iIncpid = Proportion * iError - Integral * LastError + Derivative * PrevError;
	
	//E[k]�
	//E[k��1]��
	//E[k��2]��
	
	//�洢�������´μ���
	PrevError = LastError;
	LastError = iError;
	//��������ֵ
	return(iIncpid);
}
