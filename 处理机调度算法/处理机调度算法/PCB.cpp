#include "PCB.h"
#include <iostream>
using namespace std;

PCB::PCB(int id, int p, int ct):pid(id), priority(p), claimTime(ct)
{
	runTime = 0;
}


int PCB::getPid()
{
	return pid;
}

int PCB::getRunTime()
{
	return runTime;
}

int PCB::getClaimTime()
{
	return claimTime;
}

int PCB::getPriority()
{
	return priority;
}

void PCB::run()
{
	runTime++;
	if (priority > 0)
	{
		priority--;
	}
}

bool PCB::isFinished()
{
	if (runTime == claimTime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PCB::operator<(const PCB& p)const
{
	/*优先级相同，返回所剩时间较短的*/
	if (this->priority == p.priority)
	{
		return this->claimTime - this->runTime < p.claimTime - p.runTime;
	}
	else
	{
		return this->priority < p.priority;
	}
}
