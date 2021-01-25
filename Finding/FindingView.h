
// FindingView.h : CFindingView 类的接口
//

#pragma once

#define M 5		//总共有5个关卡
#define N 10	//每个关卡有5组——10个不同点
#define Time 100	//每局游戏为100s

class CFindingView : public CView
{
protected: // 仅从序列化创建
	CFindingView();
	DECLARE_DYNCREATE(CFindingView)

// 特性
public:
	CFindingDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CFindingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

private:
	CPoint m_point[M][N];	// M关，每关N个不同点
	bool m_bisFind[M][N];	// 发现状态
	int m_m;	// 当前关卡
	unsigned int m_iTime;	// 记录当前已过秒数 unsigned表示时间不为负

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // FindingView.cpp 中的调试版本
inline CFindingDoc* CFindingView::GetDocument() const
   { return reinterpret_cast<CFindingDoc*>(m_pDocument); }
#endif

