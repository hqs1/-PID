#include "PID.h"





#define Proportion  0.8 //比例常数 Proportional Const
#define Integral    0.5 //积分常数 Integral Const
#define Derivative  0.1 //微分常数 Derivative Const

//#define Proportion  0.62 //比例常数 Proportional Const
//#define Integral    0.45 //积分常数 Integral Const
//#define Derivative  0.1 //微分常数 Derivative Const
int LastError; //Error[-1]
int PrevError; //Error[-2]
int SetPoint; //设定目标 Desired Value

//
/*==================================================================================================== 
PID Function 
The PID (比例、积分、微分) function is used in mainly 
control applications. PIDCalc performs one iteration of the PID 
algorithm. 
While the PID function works, main is just a dummy program showing 
a typical usage. 
=====================================================================================================*/  


/*==================================================================================================== 
Initialize PID Structure  PID参数初始化
=====================================================================================================*/
void IncPIDInit(void)
{

	LastError = 0; //Error[-1]
	PrevError = 0; //Error[-2]
	SetPoint = 0;
}
 
/*==================================================================================================== 
增量式PID计算部分 
=====================================================================================================*/
int IncPIDCalc(int NowPoint ,int SetSpeed)
{

	//register int iError, iIncpid; //当前误差
	int iError, iIncpid; //当前误差
	
	SetPoint = SetSpeed;//输入目标值
	
	iError = SetPoint - NowPoint;//增量计算，计算出当前值和目标值的误差值
	
	iIncpid = Proportion * iError - Integral * LastError + Derivative * PrevError;
	
	//E[k]项，
	//E[k－1]项
	//E[k－2]项
	
	//存储误差，用于下次计算
	PrevError = LastError;
	LastError = iError;
	//返回增量值
	return(iIncpid);
}
