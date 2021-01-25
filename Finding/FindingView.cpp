
// FindingView.cpp : CFindingView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CFindingView ����/����

CFindingView::CFindingView()
{
	// TODO:  �ڴ˴���ӹ������

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
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFindingView ����

void CFindingView::OnDraw(CDC* pDC)
{
	CFindingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���

	DrawBitmap(pDC);	//�����Ҳ�ͬͼƬ

	CPen redPen;
	redPen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	pDC->SelectObject(redPen);
	pDC->SelectObject(GetStockObject(NULL_BRUSH));	//���ÿհױ�ˢ

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


// CFindingView ��ӡ

BOOL CFindingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFindingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFindingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CFindingView ���

#ifdef _DEBUG
void CFindingView::AssertValid() const
{
	CView::AssertValid();
}

void CFindingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFindingDoc* CFindingView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFindingDoc)));
	return (CFindingDoc*)m_pDocument;
}
#endif //_DEBUG


// CFindingView ��Ϣ�������



// �����Ҳ�ͬͼƬ
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



// ���ز�ͬ���λ��
void CFindingView::Load()
{

	switch (m_m)
	{
	case 0:	// ��һ��
		//��һ��
		m_point[0][0].x = 197;
		m_point[0][0].y = 157;
		m_point[0][1].x = 497;
		m_point[0][1].y = 157;
		//�ڶ���
		m_point[0][2].x = 75;
		m_point[0][2].y = 220;
		m_point[0][3].x = 375;
		m_point[0][3].y = 220;
		//������
		m_point[0][4].x = 124;
		m_point[0][4].y = 220;
		m_point[0][5].x = 424;
		m_point[0][5].y = 220;
		//������
		m_point[0][6].x = 173;
		m_point[0][6].y = 220;
		m_point[0][7].x = 473;
		m_point[0][7].y = 220;
		//������
		m_point[0][8].x = 221;
		m_point[0][8].y = 220;
		m_point[0][9].x = 521;
		m_point[0][9].y = 220;
		break;

	case 1:	// �ڶ���
		//��һ��
		m_point[1][0].x = 93;
		m_point[1][0].y = 140;
		m_point[1][1].x = 393;
		m_point[1][1].y = 140;
		//�ڶ���
		m_point[1][2].x = 228;
		m_point[1][2].y = 145;
		m_point[1][3].x = 528;
		m_point[1][3].y = 145;
		//������
		m_point[1][4].x = 245;
		m_point[1][4].y = 318;
		m_point[1][5].x = 545;
		m_point[1][5].y = 318;
		//������
		m_point[1][6].x = 212;
		m_point[1][6].y = 386;
		m_point[1][7].x = 512;
		m_point[1][7].y = 386;
		//������
		m_point[1][8].x = 284;
		m_point[1][8].y = 452;
		m_point[1][9].x = 584;
		m_point[1][9].y = 452;
		break;

	case 2:	// ������
		//��һ��
		m_point[2][0].x = 144;
		m_point[2][0].y = 135;
		m_point[2][1].x = 444;
		m_point[2][1].y = 135;
		//�ڶ���
		m_point[2][2].x = 270;
		m_point[2][2].y = 289;
		m_point[2][3].x = 570;
		m_point[2][3].y = 289;
		//������
		m_point[2][4].x = 196;
		m_point[2][4].y = 344;
		m_point[2][5].x = 496;
		m_point[2][5].y = 344;
		//������
		m_point[2][6].x = 114;
		m_point[2][6].y = 399;
		m_point[2][7].x = 414;
		m_point[2][7].y = 399;
		//������
		m_point[2][8].x = 206;
		m_point[2][8].y = 447;
		m_point[2][9].x = 506;
		m_point[2][9].y = 447;
		break;

	case 3:	// ���Ĺ�
		//��һ��
		m_point[3][0].x = 226;
		m_point[3][0].y = 118;
		m_point[3][1].x = 526;
		m_point[3][1].y = 118;
		//�ڶ���
		m_point[3][2].x = 190;
		m_point[3][2].y = 136;
		m_point[3][3].x = 490;
		m_point[3][3].y = 136;
		//������
		m_point[3][4].x = 230;
		m_point[3][4].y = 306;
		m_point[3][5].x = 530;
		m_point[3][5].y = 306;
		//������
		m_point[3][6].x = 91;
		m_point[3][6].y = 371;
		m_point[3][7].x = 391;
		m_point[3][7].y = 371;
		//������
		m_point[3][8].x = 225;
		m_point[3][8].y = 478;
		m_point[3][9].x = 525;
		m_point[3][9].y = 478;
		break;

	case 4:	// �����
		//��һ��
		m_point[4][0].x = 131;
		m_point[4][0].y = 141;
		m_point[4][1].x = 431;
		m_point[4][1].y = 141;
		//�ڶ���
		m_point[4][2].x = 223;
		m_point[4][2].y = 268;
		m_point[4][3].x = 523;
		m_point[4][3].y = 268;
		//������
		m_point[4][4].x = 314;
		m_point[4][4].y = 277;
		m_point[4][5].x = 614;
		m_point[4][5].y = 277;
		//������
		m_point[4][6].x = 289;
		m_point[4][6].y = 363;
		m_point[4][7].x = 589;
		m_point[4][7].y = 363;
		//������
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	static int n = 0;	// �ҵ��˼�����ͬ

	for (int j = 0; j < N; j++)
	{
		if (point.x < m_point[m_m][j].x + 20 && point.x > m_point[m_m][j].x - 20
			&& point.y < m_point[m_m][j].y + 20 && point.y > m_point[m_m][j].y - 20)
		{
			if (m_bisFind[m_m][j] == false)
			{
				n++;
				m_bisFind[m_m][j] = true;	//��ǰ��
				if (j % 2 == 0)				//�޸ĵ�ǰ�Ե����һ��
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

	CString str;		//��Ϸ�÷֣���Ϸʣ��ʱ��*100
	str.Format(_T("���ҵ����в�ͬ�����ĵ÷�Ϊ��%d\n�Ƿ������һ�أ�"), (Time - m_iTime) * 100);

	if (n == 5)		//�ҵ������в�ͬ
	{
		KillTimer(1);
		if (IDOK == MessageBox(str, _T("��ʾ"), MB_OKCANCEL))
		{
			m_m++;
			Load();	   //��һ�ؿ�
			n = 0;	   //�����ҵ��Ĳ�ͬ��
			m_iTime = 0;	//��������ʱ��
			SetTimer(1, 1000, NULL);	//���¿�����ʱ��
			InvalidateRect(0, NULL);	//�����ػ�
		}
	}

	CView::OnLButtonDown(nFlags, point);
}


int CFindingView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	Load();	//���ز�ͬ��λ��
	SetTimer(1, 1000, NULL);

	return 0;
}


void CFindingView::OnM0()
{
	// TODO:  �ڴ���������������
	m_m = 0;
	Load();
	m_iTime = 0;
	SetTimer(1, 1000, NULL);
	InvalidateRect(0, NULL);
}


void CFindingView::OnM1()
{
	// TODO:  �ڴ���������������
	m_m = 1;
	Load();
	m_iTime = 0;
	SetTimer(1, 1000, NULL);
	InvalidateRect(0, NULL);
}


void CFindingView::OnM2()
{
	// TODO:  �ڴ���������������
	m_m = 2;
	Load();
	m_iTime = 0;
	SetTimer(1, 1000, NULL);
	InvalidateRect(0, NULL);
}


void CFindingView::OnM3()
{
	// TODO:  �ڴ�������������
	m_m = 3;
	Load();
	m_iTime = 0;
	SetTimer(1, 1000, NULL);
	InvalidateRect(0, NULL);
}


void CFindingView::OnM4()
{
	// TODO:  �ڴ���������������
	m_m = 4;
	Load();
	m_iTime = 0;
	SetTimer(1, 1000, NULL);
	InvalidateRect(0, NULL);
}


void CFindingView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_iTime++;
	CRect rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = 900;
	rect.bottom = 80;
	InvalidateRect(rect, true);

	CView::OnTimer(nIDEvent);
}


// ����ʱ��״̬��
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
		float tmp = (Time - m_iTime)*0.01;	//ʣ��ʱ��ٷֱ�
		int tmpbar = tmp * 600;		//���Ƶȱ�����ʱ����

		pDC->Rectangle(50, 35, tmpbar+50, 70);
	}
	

}


// ���ƽ�����������ʾ��Ϣ
void CFindingView::DrawText(CDC * pDC)
{
	CString str;
	str.Format(_T("ʣ��ʱ�䣺%d ��"), Time - m_iTime);
	pDC->TextOut(700,40,str);

}


bool CFindingView::GameOver()
{
	if (Time - m_iTime <= 0)
	{
		KillTimer(1);
		MessageBox(_T("��Ϸ����!!!"), _T("��ʾ"), MB_OK);
		return true;
	}
	return false;
}
