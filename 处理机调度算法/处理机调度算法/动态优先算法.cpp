#include <iostream>
#include <queue>
#include "PCB.h"
using namespace std;

int main()
{
	int timeslice = 0; //已经消耗的时间片
	priority_queue<PCB> queue; //就绪队列，优先级高的在前面
	for (int i = 0; i < 5; i++)//共有5个进程
	{
		int p, t;
		cout << "请输入第" << i << "号进程的优先级：";
		cin >> p;
		cout << "请输入第" << i << "号进程需要运行的时间：";
		cin >> t;
		queue.emplace(PCB(i, p, t));
	}
	cout << "===============================================" << endl;
	//动态优先算法
	while (!queue.empty())
	{
		PCB pcb = queue.top();
		queue.pop();
		cout << "进程" << pcb.getPid() << "号开始运行" << endl;
		cout << "优先级\t已运行时间" << endl;
		cout << pcb.getPriority() << '\t' << pcb.getRunTime() << endl;
		pcb.run();
		cout << "进程" << pcb.getPid() << "号结束运行" << endl;
		cout << "优先级\t已运行时间" << endl;
		cout << pcb.getPriority() << '\t' << pcb.getRunTime() << endl;
		if (pcb.isFinished())
		{
			cout << pcb.getPid() << "号进程已完成任务" << endl;
		}
		else
		{
			queue.push(pcb);
			cout << "进程任务未完成，已重新入队" << endl;
		}
		timeslice++;
		cout << "----------------------------------------------" << endl;
		system("pause");
	}
	cout << "所有进程任务完成，消耗运行时间片为：" << timeslice;
	return 0;
}