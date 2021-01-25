
// FindingView.h : CFindingView ��Ľӿ�
//

#pragma once

#define M 5		//�ܹ���5���ؿ�
#define N 10	//ÿ���ؿ���5�顪��10����ͬ��
#define Time 100	//ÿ����ϷΪ100s

class CFindingView : public CView
{
protected: // �������л�����
	CFindingView();
	DECLARE_DYNCREATE(CFindingView)

// ����
public:
	CFindingDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CFindingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

private:
	CPoint m_point[M][N];	// M�أ�ÿ��N����ͬ��
	bool m_bisFind[M][N];	// ����״̬
	int m_m;	// ��ǰ�ؿ�
	unsigned int m_iTime;	// ��¼��ǰ�ѹ����� unsigned��ʾʱ�䲻Ϊ��

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	void DrawBitmap(CDC * pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void Load();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnM0();
	afx_msg void OnM1();
	afx_msg void OnM2();
	afx_msg void OnM3();
	afx_msg void OnM4();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void DrawTimebar(CDC * pDC);
	void DrawText(CDC * pDC);
	bool GameOver();
};

#ifndef _DEBUG  // FindingView.cpp �еĵ��԰汾
inline CFindingDoc* CFindingView::GetDocument() const
   { return reinterpret_cast<CFindingDoc*>(m_pDocument); }
#endif

