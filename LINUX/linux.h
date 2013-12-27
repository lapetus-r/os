/*
╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋
┃			  														  lapetOS			   													   ┃
┃				 						 [ General Purpose Kernel for Embedded System ]									   ┃
┃			  																   																	   ┃
┃			  							  					SangMyung University									   					   ┃
┃			  							  				  Computer Science Major												       ┃
┃			  																				   													   ┃
┃					  					  Made By: Yoo Sang-Gi / Park Il-Kwon, 2011-2012							  	   ┃
┃			  												   File Name: linux.h	 													   ┃
╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋
*/

#define INTERRUPT_NUM	1						/* 인터럽트 번호	*/
#define ContextSW()	CtxSwfromSched();		/* 문맥전환			*/

/*
╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋
┃				 											 [ Global Variable Declare ]												   ┃
┃			  									 for the purpose of porting to linux kernel		  								   ┃
╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋
*/

typedef int INT;
typedef char CHAR;
typedef float FLOAT;
typedef double DOUBLE;
typedef long LONG;
typedef unsigned int INT_U;
typedef unsigned char CHAR_U;
typedef unsigned long LONG_U;
typedef float FLOAT_U;
typedef double DOUBLE_U;

typedef CHAR_U BOOLEAN;
typedef unsigned long STACK;

/*
╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋
┃				 										 [ Method Prototype Declare ]												   ┃
┃			  									 for the purpose of porting to linux kernel		  								   ┃
╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋
*/

void (*tickMethod)(void);
void EnableInt(void);
void DisableInt(void);
void CtxSwfromSched(void);
void CtxSwfromInt(void);
void KernelBreaker(int ctrl);
void SchedFlagHandler(int para);
void IntFlagHandler(int para);
void PScheduler(int parameter);
void ISR(int parameter);
void ThreadInit(void);
void KernelSleep(void);
void TimeTickInit(void);
void TimeTickSignal(int parameter);
void KernelStart(void);
void ThreadStart(void);
STACK *PCBStackInit(void (*proc)(void *pd), STACK *stktop);
