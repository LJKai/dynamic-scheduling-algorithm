#pragma once
class PCB
{
private:
	int pid;		//进程序号
	int runTime;	//进程已运行时间
	int claimTime;  //进程所需运行时间
	int priority;   //进程优先级
public:
	PCB(int id, int p, int ct);
	int getPid();
	int getRunTime();
	int getClaimTime();
	int getPriority();
	void run(); //进程运行函数
	bool isFinished(); //进程状态判断函数
	bool operator<(const PCB& p) const;//计算符<的重载函数

};

