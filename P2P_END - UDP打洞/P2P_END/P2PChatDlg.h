#pragma once
#ifndef TESTCLASS_H
#define TESTCLASS_H

#include "P2PBase.h"
#include "P2P_ENDDlg.h"
#include "afxwin.h"
// CP2PChatDlg �Ի���
class CP2P_ENDDlg;
class CP2PChatDlg : public CDialog
{
	DECLARE_DYNAMIC(CP2PChatDlg)

public:
	CP2PChatDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CP2PChatDlg();
	char m_PeerName[20] ;  //���ڻظ����ڼ�������
	CP2P_ENDDlg *m_pParent;	
	//CString m_PeerRecv;
	//CString m_PeerSend;
	Message m_SaveMsg;
	BOOL isActive;
	void SetParentDlg(CP2P_ENDDlg*);
	void AddRecvMsg(CString *p_MsgLog,char *userName,CString *chat);
// �Ի�������
	enum { IDD = IDD_P2PCHAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHide();

	afx_msg void OnPeerSend();
	CEdit m_PeerRecv;
	CEdit m_PeerSend;
	afx_msg void OnClear();
};
#endif