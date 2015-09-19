// P2P_ENDDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "ClientSock.h"
#include "P2PBase.h"
#include "P2P_END.h"
#include "P2PChatDlg.h"
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")


// CP2P_ENDDlg �Ի���
class CP2P_ENDDlg : public CDialog
{
// ����
public:
	CP2P_ENDDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CClientSock m_ClientSock;			//�����õ�csocket
	Message m_ClientMsg;		//��Ҫ�������û��б�
	SOCKADDR_IN m_ServAddr;	//��������ַ��Ϣ
	BOOL m_State;			//�ͻ���״̬
	UserData m_UserData;
	CP2PChatDlg *m_ChatMsgDlg;
	CPtrList m_P2PChatList;		//	����Ի����б�
	BOOL m_Extend;  //���÷�����IP
	void ReceiveData(CClientSock *m_ClientSock);
	void UpdateUserList(Message *buffer);		//	�ѷ����������Ĵ��뻺��Ķ������µ��б�
	void ShowP2PChatDlg(Message *buffer);
	void AddRecvMsg(CString *, Message *);
	void RecvP2PMsg(Message *p_PeerBuffer);
	PeerData* FindP2PChatDlgByName(char *userName);
	void UserListLightUp(BOOL flag,char *userName);
	void CreateP2PDlg(Message *p_PeerBuffer);
	void LoginToChat();
	void LoginToRegister();
// �Ի�������
	enum { IDD = IDD_P2P_END_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLogin();
	CEdit m_UserName;
	CEdit m_ServMsg;
	CEdit m_ServSend;
	afx_msg void OnServSend();
	CEdit m_ServIP;
	CEdit m_ServPort;
	CButton m_LoginButton;
	CButton m_ExitButton;
	CButton m_SendButton;
	afx_msg void OnExit();
	CListBox m_OLUserList;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnUserList();
	//CListBox m_UserListBox;
	afx_msg void OnEnChangeEditServport();
	afx_msg void OnCanel();
	afx_msg void OnSetting();
	afx_msg void OnForget();
	afx_msg void OnClear();
	CEdit m_Password;
	afx_msg void OnReg1();
	afx_msg void OnReg2();
	afx_msg void OnBack();
	afx_msg void OnForget2();
	afx_msg void OnEnChangeEditIdcard();
};
