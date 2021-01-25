
// FindingView.cpp : CFindingView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Finding.h"
#endif

#include "FindingDoc.h"
#include "FindingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFindingView

IMPLEMENT_DYNCREATE(CFindingView, CView)

BEGIN_MESSAGE_MAP(CFindingView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_COMMAND(ID_M0, &CFindingView::OnM0)
	ON_COMMAND(ID_M1, &CFindingView::OnM1)
	ON_COMMAND(ID_M2, &CFindingView::OnM2)
	ON_COMMAND(ID_M3, &CFindingView::OnM3)
	ON_COMMAND(ID_M4, &CFindingView::OnM4)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CFindingView 构造/析构

CFindingView::CFindingView()
{
	// TODO:  在此处添加构造代码

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			m_point[i][j].x = m_point[i][j].y = 0;
			m_bisFind[i][j] = false;

		}
	}

	m_m = 0;
	m_iTime = 0;

}

CFindingView::~CFindingView()
{
}

BOOL CFindingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFindingView 绘制

void CFindingView::OnDraw(CDC* pDC)
{
	CFindingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码

	DrawBitmap(pDC);	//绘制找不同图片

	CPen redPen;
	redPen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	pDC->SelectObject(redPen);
	pDC->SelectObject(GetStockObject(NULL_BRUSH));	//设置空白笔刷

	for (int j = 0; j < N; j++)
	{
		if (m_bisFind[m_m][j] == true)
		{
			pDC->Ellipse(m_point[m_m][j].x - 20, m_point[m_m][j].y - 20, m_point[m_m][j].x + 20, m_point[m_m][j].y + 20);
		}
	}

	DrawTimebar(pDC);
	DrawText(pDC);

}


// CFindingView 打印

BOOL CFindingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFindingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CFindingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CFindingView 诊断

#ifdef _DEBUG
void CFindingView::AssertValid() const
{
	CView::AssertValid();
}

void CFindingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFindingDoc* CFindingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFindingDoc)));
	return (CFindingDoc*)m_pDocument;
}
#endif //_DEBUG


// CFindingView 消息处理程序



// 绘制找不同图片
void CFindingView::DrawBitmap(CDC * pDC)
{
	CBitmap mybit;
	switch (m_m)
	{
	case 0:
		mybit.LoadBitmap(IDB_BITMAP1);
		break;
	case 1:
		mybit.LoadBitmap(IDB_BITMAP2);
		break;
	case 2:
		mybit.LoadBitmap(IDB_BITMAP3);
		break;
	case 3:
		mybit.LoadBitmap(IDB_BITMAP4);
		break;
	case 4:
		mybit.LoadBitmap(IDB_BITMAP5);
		break;
	default:
		break;
	}

	CDC backDC;
	backDC.CreateCompatibleDC(pDC);
	backDC.SelectObject(mybit);
	pDC->StretchBlt(50, 100, 600, 400, &backDC, 0, 0, 600, 400, SRCCOPY);

}



// 加载不同点的位置
void CFindingView::Load()
{

	switch (m_m)
	{
	case 0:	// 第一关
		//第一组
		m_point[0][0].x = 197;
		m_point[0][0].y = 157;
		m_point[0][1].x = 497;
		m_point[0][1].y = 157;
		//第二组
		m_point[0][2].x = 75;
		m_point[0][2].y = 220;
		m_point[0][3].x = 375;
		m_point[0][3].y = 220;
		//第三组
		m_point[0][4].x = 124;
		m_point[0][4].y = 220;
		m_point[0][5].x = 424;
		m_point[0][5].y = 220;
		//第四组
		m_point[0][6].x = 173;
		m_point[0][6].y = 220;
		m_point[0][7].x = 473;
		m_point[0][7].y = 220;
		//第五组
		m_point[0][8].x = 221;
		m_point[0][8].y = 220;
		m_point[0][9].x = 521;
		m_point[0][9].y = 220;
		break;

	case 1:	// 第二关
		//第一组
		m_point[1][0].x = 93;
		m_point[1][0].y = 140;
		m_point[1][1].x = 393;
		m_point[1][1].y = 140;
		//第二组
		m_point[1][2].x = 228;
		m_point[1][2].y = 145;
		m_point[1][3].x = 528;
		m_point[1][3].y = 145;
		//第三组
		m_point[1][4].x = 245;
		m_point[1][4].y = 318;
		m_point[1][5].x = 545;
		m_point[1][5].y = 318;
		//第四组
		m_point[1][6].x = 212;
		m_point[1][6].y = 386;
		m_point[1][7].x = 512;
		m_point[1][7].y = 386;
		//第五组
		m_point[1][8].x = 284;
		m_point[1][8].y = 452;
		m_point[1][9].x = 584;
		m_point[1][9].y = 452;
		break;

	case 2:	// 第三关
		//第一组
		m_point[2][0].x = 144;
		m_point[2][0].y = 135;
		m_point[2][1].x = 444;
		m_point[2][1].y = 135;
		//第二组
		m_point[2][2].x = 270;
		m_point[2][2].y = 289;
		m_point[2][3].x = 570;
		m_point[2][3].y = 289;
		//第三组
		m_point[2][4].x = 196;
		m_point[2][4].y = 344;
		m_point[2][5].x = 496;
		m_point[2][5].y = 344;
		//第四组
		m_point[2][6].x = 114;
		m_point[2][6].y = 399;
		m_point[2][7].x = 414;
		m_point[2][7].y = 399;
		//第五组
		m_point[2][8].x = 206;
		m_point[2][8].y = 447;
		m_point[2][9].x = 506;
		m_point[2][9].y = 447;
		break;

	case 3:	// 第四关
		//第一组
		m_point[3][0].x = 226;
		m_point[3][0].y = 118;
		m_point[3][1].x = 526;
		m_point[3][1].y = 118;
		//第二组
		m_point[3][2].x = 190;
		m_point[3][2].y = 136;
		m_point[3][3].x = 490;
		m_point[3][3].y = 136;
		//第三组
		m_point[3][4].x = 230;
		m_point[3][4].y = 306;
		m_point[3][5].x = 530;
		m_point[3][5].y = 306;
		//第四组
		m_point[3][6].x = 91;
		m_point[3][6].y = 371;
		m_point[3][7].x = 391;
		m_point[3][7].y = 371;
		//第五组
		m_point[3][8].x = 225;
		m_point[3][8].y = 478;
		m_point[3][9].x = 525;
		m_point[3][9].y = 478;
		break;

	case 4:	// 第五关
		//第一组
		m_point[4][0].x = 131;
		m_point[4][0].y = 141;
		m_point[4][1].x = 431;
		m_point[4][1].y = 141;
		//第二组
		m_point[4][2].x = 223;
		m_point[4][2].y = 268;
		m_point[4][3].x = 523;
		m_point[4][3].y = 268;
		//第三组
		m_point[4][4].x = 314;
		m_point[4][4].y = 277;
		m_point[4][5].x = 614;
		m_point[4][5].y = 277;
		//第四组
		m_point[4][6].x = 289;
		m_point[4][6].y = 363;
		m_point[4][7].x = 589;
		m_point[4][7].y = 363;
		//第五组
		m_point[4][8].x = 198;
		m_point[4][8].y = 428;
		m_point[4][9].x = 498;
		m_point[4][9].y = 428;
		break;

	default:
		break;
	}
}



void CFindingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	static int n = 0;	// 找到了几个不同

	for (int j = 0; j < N; j++)
	{
		if (point.x < m_point[m_m][j].x + 20 && point.x > m_point[m_m][j].x - 20
			&& point.y < m_point[m_m][j].y + 20 && point.y > m_point[m_m][j].y - 20)
		{
			if (m_bisFind[m_m][j] == false)
			{
				n++;
				m_bisFind[m_m][j] = true;	//当前点
				if (j % 2 == 0)				//修改当前对点的另一个
				{
					m_bisFind[m_m][j + 1] = true;
				}
				else
				{
					m_bisFind[m_m][j - 1] = true;
				}
				break;
			}
			
		}
	}

	InvalidateRect(0, NULL);

	CString str;		//游戏得分：游戏剩余时间*100
	str.Format(_T("已找到所有不同，您的得分为：%d\n是否进入下一关？"), (Time - m_iTime) * 100);

	if (n == 5)		//找到了所有不同
	{
		KillTimer(1);
		if (IDOK == MessageBox(str, _T("提示"), MB_OKCANCEL))
		{
			m_m++;
			Load();	   //下一关卡
			n = 0;	   //重置找到的不同数
			m_iTime = 0;	//重置已用时间
			SetTimer(1, 1000, NULL);	//重新开启定时器
			InvalidateRect(0, NULL);	//画面重绘
		}
	}

	CView::OnLButtonDown(nFlags, point);
}


int CFindingView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	Load();	//加载不同点位置
	SetTimer(1, 1000, NULL);

	return 0;
}


void CFindingView::OnM0()
{
	// TODO:  在此添加命令处理程序代码
	m_m = 0;
	Load();
	m_iTime = 0;
	SetTimer(1, 1000, NULL);
	InvalidateRect(0, NULL);
}


void CFindingView::OnM1()
{
	// TODO:  在此添加命令处理程序代码
	m_m = 1;
	Load();
	m_iTime = 0;
	SetTimer(1, 1000, NULL);
	InvalidateRect(0, NULL);
}


void CFindingView::OnM2()
{
	// TODO:  在此添加命令处理程序代码
	m_m = 2;
	Load();
	m_iTime = 0;
	SetTimer(1, 1000, NULL);
	InvalidateRect(0, NULL);
}


void CFindingView::OnM3()
{
	// TODO:  在此添加命令处理程序代
	m_m = 3;
	Load();
	m_iTime = 0;
	SetTimer(1, 1000, NULL);
	InvalidateRect(0, NULL);
}


void CFindingView::OnM4()
{
	// TODO:  在此添加命令处理程序代码
	m_m = 4;
	Load();
	m_iTime = 0;
	SetTimer(1, 1000, NULL);
	InvalidateRect(0, NULL);
}


void CFindingView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	m_iTime++;
	CRect rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = 900;
	rect.bottom = 80;
	InvalidateRect(rect, true);

	CView::OnTimer(nIDEvent);
}


// 绘制时间状态条
void CFindingView::DrawTimebar(CDC * pDC)
{
	CPen pen;
	pen.CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	pDC->SelectObject(pen);
	pDC->Rectangle(50, 35, 650, 70);
	
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 240, 160));
	pDC->SelectObject(brush);
	
	if (GameOver() == false)
	{
		float tmp = (Time - m_iTime)*0.01;	//剩余时间百分比
		int tmpbar = tmp * 600;		//绘制等比例的时间条

		pDC->Rectangle(50, 35, tmpbar+50, 70);
	}
	

}


// 绘制界面上文字提示信息
void CFindingView::DrawText(CDC * pDC)
{
	CString str;
	str.Format(_T("剩余时间：%d 秒"), Time - m_iTime);
	pDC->TextOut(700,40,str);

}


bool CFindingView::GameOver()
{
	if (Time - m_iTime <= 0)
	{
		KillTimer(1);
		MessageBox(_T("游戏结束!!!"), _T("提示"), MB_OK);
		return true;
	}
	return false;
}
