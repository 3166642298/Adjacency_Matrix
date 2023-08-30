#include "AMGraph.h"
AMGraph::AMGraph(int vexNum, GraphKind kind)
{
	this->VexNum = vexNum;
	this->ArcNum = 0;
	this->Kind = kind;
	this->vexs = new VerTexType[VexNum];//分配顶点表
	this->arcs = new ArcCell * [VexNum];//动态分配二维数组
	for (int i = 0; i < VexNum; i++)
	{
		arcs[i] = new ArcCell[VexNum];//为每一行动态分配内存
	}
}
int AMGraph::locate(VerTexType v1)
{
	int i = 0;
	for (i = 0; i < this->VexNum; i++)
	{
		if (v1 == this->vexs[i]) {
			return i;
		}
	}
	return -1;
}
void AMGraph::Init()
{
	cout << "请输入每一个顶点的关键字：" << endl;
	VerTexType temp;
	for (int i = 0; i < this->VexNum; i++)
	{
		cin >> temp;
		this->vexs[i] = temp;
	}
	for (int i = 0; i < this->VexNum; i++)
	{
		ArcCell ac;
		ac.adj = 0;
		ac.info = NULL;
		for (int j = 0; j < VexNum; j++)
		{
			this->arcs[i][j] = ac;
		}
	}
}
void AMGraph::Create()
{
	switch (Kind)
	{
	case DG:
	{
		Create_DG();    //构造一个有向图
		break;
	}
	case WDG:
	{
		Create_WDG();    //构造一个带权有向图
		break;
	}
	case UDG:
	{
		Create_UDG();    //构造一个无向图
		break;
	}
	case WUDG:
	{
		Create_WUDG();   //构造一个带权无向图
		break;
	}
	default:
		return;
	}
}
void AMGraph::Create_DG()
{
	Init();
	VerTexType v1, v2;
	cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
	while (cin >> v1 >> v2)
	{
		this->ArcNum++;
		int i = locate(v1);
		int j = locate(v2);
		arcs[i][j].adj = 1;
	}
}
void AMGraph::Create_WDG()
{
	Init();
	VerTexType v1, v2;
	ArcType w;
	cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
	while (cin >> v1 >> v2 >> w)
	{
		this->ArcNum++;
		int i = locate(v1);
		int j = locate(v2);
		arcs[i][j].adj = w;
	}
}
void AMGraph::Create_UDG()
{
	Init();
	VerTexType v1, v2;
	cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
	while (cin >> v1 >> v2)
	{
		this->ArcNum += 2;
		int i = locate(v1);
		int j = locate(v2);
		arcs[i][j].adj = 1;
		arcs[j][i].adj = 1;
	}
}
void AMGraph::Create_WUDG()
{
	Init();
	VerTexType v1, v2;
	ArcType w;
	cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
	while (cin >> v1 >> v2 >> w)
	{
		this->ArcNum++;
		int i = locate(v1);
		int j = locate(v2);
		arcs[i][j].adj = w;
		arcs[j][i].adj = 1;
	}
}

void AMGraph::Display()
{
	cout << "总共有" << this->VexNum << "个顶点," << this->ArcNum << "条边" << endl;
	for (int i = 0; i < this->VexNum; i++)
	{
		cout << "第" << i + 1 << "个顶点是：" << this->vexs[i]
			<< "相邻的边有: ";
		for (int j = 0; j < this->VexNum; j++)
		{
			if (arcs[i][j].adj != 0)
				cout << vexs[j] << "(" << arcs[i][j].adj << ") ";
		}
		cout << endl;
	}

}
