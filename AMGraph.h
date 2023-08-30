#pragma once
#ifndef AMGRAPHY_H
#define AMGRAPHY_H
#include<iostream>
using namespace std;
enum GraphKind { DG, WDG, UDG, WUDG };
typedef string VerTexType;
typedef int ArcType;
typedef int InfoType;
//DG--����ͼ��WDG--��Ȩֵ������ͼ��UDG--����ͼ��WUDG--��Ȩֵ������ͼ
class AMGraph {
private:
	struct ArcCell
	{
		ArcType adj;   //�����ϵ���͡�������Ȩͼ����1��0��ʾ
		//��ʾ������񣻶Դ�Ȩͼ��ΪȨֵ����
		InfoType info;  //�û���ص���Ϣ��ָ��
	};
	VerTexType* vexs;//�����
	ArcCell** arcs;//�ڽӾ���
	int VexNum, ArcNum;//ͼ�ĵ�ǰ�����ͱ���
	GraphKind Kind;
public:
	AMGraph() = default;
	AMGraph(int vexNum, GraphKind kind);
	int locate(VerTexType v1);
	void Init();//��ʼ������������ڽӾ���
	void Create();
	void Create_DG();
	void Create_WDG();
	void Create_UDG();
	void Create_WUDG();
	void Display();
};
#endif // !AMGRAPHY_H