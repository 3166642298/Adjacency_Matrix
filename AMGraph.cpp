#include "AMGraph.h"
AMGraph::AMGraph(int vexNum, GraphKind kind)
{
	this->VexNum = vexNum;
	this->ArcNum = 0;
	this->Kind = kind;
	this->vexs = new VerTexType[VexNum];//���䶥���
	this->arcs = new ArcCell * [VexNum];//��̬�����ά����
	for (int i = 0; i < VexNum; i++)
	{
		arcs[i] = new ArcCell[VexNum];//Ϊÿһ�ж�̬�����ڴ�
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
	cout << "������ÿһ������Ĺؼ��֣�" << endl;
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
		Create_DG();    //����һ������ͼ
		break;
	}
	case WDG:
	{
		Create_WDG();    //����һ����Ȩ����ͼ
		break;
	}
	case UDG:
	{
		Create_UDG();    //����һ������ͼ
		break;
	}
	case WUDG:
	{
		Create_WUDG();   //����һ����Ȩ����ͼ
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
	cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
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
	cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
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
	cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
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
	cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
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
	cout << "�ܹ���" << this->VexNum << "������," << this->ArcNum << "����" << endl;
	for (int i = 0; i < this->VexNum; i++)
	{
		cout << "��" << i + 1 << "�������ǣ�" << this->vexs[i]
			<< "���ڵı���: ";
		for (int j = 0; j < this->VexNum; j++)
		{
			if (arcs[i][j].adj != 0)
				cout << vexs[j] << "(" << arcs[i][j].adj << ") ";
		}
		cout << endl;
	}

}
