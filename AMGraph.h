#pragma once
#ifndef AMGRAPHY_H
#define AMGRAPHY_H
#include<iostream>
using namespace std;
enum GraphKind { DG, WDG, UDG, WUDG };
typedef string VerTexType;
typedef int ArcType;
typedef int InfoType;
//DG--有向图，WDG--带权值的有向图，UDG--无向图，WUDG--带权值的无向图
class AMGraph {
private:
	struct ArcCell
	{
		ArcType adj;   //顶点关系类型。对于无权图，用1或0表示
		//表示相邻与否；对带权图，为权值类型
		InfoType info;  //该弧相关的信息的指针
	};
	VerTexType* vexs;//顶点表
	ArcCell** arcs;//邻接矩阵
	int VexNum, ArcNum;//图的当前点数和边数
	GraphKind Kind;
public:
	AMGraph() = default;
	AMGraph(int vexNum, GraphKind kind);
	int locate(VerTexType v1);
	void Init();//初始化顶点数组和邻接矩阵
	void Create();
	void Create_DG();
	void Create_WDG();
	void Create_UDG();
	void Create_WUDG();
	void Display();
};
#endif // !AMGRAPHY_H