// P2P_ENDDlg.cpp : ʵ���ļ�
//
#pragma once

#include <ctime>
#include "stdafx.h"
#include "P2P_END.h"
#include "P2P_ENDDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CP2P_ENDDlg �Ի���




void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

CP2P_ENDDlg::CP2P_ENDDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CP2P_ENDDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CP2P_ENDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_LOGIN, m_UserName);
	DDX_Control(pDX, IDC_EDIT_SERVMSG, m_ServMsg);
	DDX_Control(pDX, IDC_EDIT_SEND, m_ServSend);
	DDX_Control(pDX, IDC_EDIT_SERVIP, m_ServIP);
	DDX_Control(pDX, IDC_EDIT_SERVPORT, m_ServPort);
	DDX_Control(pDX, IDC_LOGIN, m_LoginButton);
	DDX_Control(pDX, IDC_BUTTON_EXIT, m_ExitButton);
	DDX_Control(pDX, IDC_SERVSEND, m_SendButton);
	DDX_Control(pDX, IDC_LIST1, m_OLUserList);
	//DDX_Control(pDX, IDC_USERLIST, m_UserListBox);
	DDX_Control(pDX, IDC_EDIT_PSW, m_Password);
}

BEGIN_MESSAGE_MAP(CP2P_ENDDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_LOGIN, &CP2P_ENDDlg::OnLogin)
	ON_BN_CLICKED(IDC_SERVSEND, &CP2P_ENDDlg::OnServSend)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CP2P_ENDDlg::OnExit)
	ON_WM_TIMER()
	ON_LBN_DBLCLK(IDC_LIST1, &CP2P_ENDDlg::OnUserList)
	ON_EN_CHANGE(IDC_EDIT_SERVPORT, &CP2P_ENDDlg::OnEnChangeEditServport)
	ON_BN_CLICKED(IDC_CANEL, &CP2P_ENDDlg::OnCanel)
	ON_BN_CLICKED(IDC_SETTING, &CP2P_ENDDlg::OnSetting)
	ON_BN_CLICKED(IDC_FORGET, &CP2P_ENDDlg::OnForget)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CP2P_ENDDlg::OnClear)
	ON_BN_CLICKED(IDC_REG1, &CP2P_ENDDlg::OnReg1)
	ON_BN_CLICKED(IDC_REG2, &CP2P_ENDDlg::OnReg2)
	ON_BN_CLICKED(IDC_BACK, &CP2P_ENDDlg::OnBack)
	ON_BN_CLICKED(IDC_FORGET2, &CP2P_ENDDlg::OnForget2)
	ON_EN_CHANGE(IDC_EDIT_IDCARD, &CP2P_ENDDlg::OnEnChangeEditIdcard)
END_MESSAGE_MAP()


// CP2P_ENDDlg ��Ϣ�������

BOOL CP2P_ENDDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_UserData.strPort = "1000";
	m_UserData.strIP = "127.0.0.1";
	m_ServIP.SetWindowText("127.0.0.1");
	m_ServPort.SetWindowText("1000");
	m_ExitButton.EnableWindow(FALSE);
	m_SendButton.EnableWindow(FALSE);
	m_State = FALSE ;
	   //Ϊ�Ի������ռ�  ����create������ - -
	m_Extend=FALSE;
	this->MoveWindow(470,260,327,230,1);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CP2P_ENDDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CP2P_ENDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CP2P_ENDDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CP2P_ENDDlg::OnLogin()
{
	CString strName;
	CString strPSW;
	///CString strChat;
	//m_State = TRUE ;
	this->GetDlgItem(IDC_EDIT_LOGIN)->GetWindowText(strName);
	this->GetDlgItem(IDC_EDIT_PSW)->GetWindowText(strPSW);
	this->GetDlgItem(IDC_EDIT_SERVIP)->GetWindowText(m_UserData.strIP);
	this->GetDlgItem(IDC_EDIT_SERVPORT)->GetWindowText(m_UserData.strPort);
	strcpy(m_UserData.userName,strName.GetBuffer());
	strName.ReleaseBuffer();
	strcpy(m_ClientMsg.m_UserName,m_UserData.userName);
	strcpy(m_ClientMsg.m_PSW,strPSW.GetBuffer());
	strPSW.ReleaseBuffer();
	strName+=" �����ˣ�����";
	strcpy(m_ClientMsg.chat,strName.GetBuffer());
	strName.ReleaseBuffer();
	m_ClientMsg.sign = 1;
	m_ClientMsg.id = 1;
	m_ClientSock.SetDlg(this);
	if (strName.GetLength()==0)
	{
		MessageBox("�������û���");
		return;
	}
	if(m_UserData.strIP.GetLength()==0||m_UserData.strPort.GetLength()==0)
	{
		MessageBox("������IP�Ͷ˿ں�");
		return;
	}
	if(!m_ClientSock.Create(0,SOCK_DGRAM))		//	0��ʾ�ͻ�������˿�
	{
		char szMsg[1024] = {0};
		sprintf(szMsg, "create faild: %d", m_ClientSock.GetLastError());
		AfxMessageBox(szMsg);
		return;
	}
	int nPort = atoi(m_UserData.strPort);
	m_ClientSock.SendTo((char*)&m_ClientMsg, sizeof(m_ClientMsg),nPort,m_UserData.strIP,0);
	m_LoginButton.EnableWindow(FALSE); //����һ�β����ٰ��ˣ���Ϊ�ͻ��˴��������ӻ�û�ر�
	
	SetTimer(1,10000,NULL);   //���ö�ʱ�����жϵ�½��ʱ
	SetTimer(2,40000,NULL);   //���ö�ʱ�����ж��Ƿ����������������
	//m_ClientSock.Close();
	
	//MessageBox("���ӳɹ�");
	
}

void CP2P_ENDDlg::ReceiveData(CClientSock *sock)
{
	Message buffer;
	CString strName;
	CString strChat;
	CString str;
	CString strTime;  
	POSITION pos;
	PeerData *p_PeerData =NULL;
	int len = sizeof(SOCKADDR_IN);
	this->GetDlgItem(IDC_EDIT_LOGIN)->GetWindowText(strName);
	//CTime t=CTime::GetCurrentTime();
	//strTime.Format("%d:%d:%d",t.GetHour(),t.GetMinute(),t.GetSecond());
 	sock->ReceiveFrom((char*)&buffer,sizeof(buffer),(SOCKADDR*)&(this->m_ServAddr),&len,0);
	
	if (buffer.sign!=P2PCHATMSG)  //p2p��Ϣ�����������б�
	{
		UpdateUserList(&buffer);
	}
	
	switch (buffer.sign)
	{
	case LOGINMSG:
		if (buffer.servACK==-1)
		{
			MessageBox(_T("�û�����������󣡣�"));
			m_LoginButton.EnableWindow(TRUE);
			m_ClientSock.Close();
			return;
		}
		PlaySound((LPCTSTR)IDR_LOGINMSG, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);		//��������

		//if (buffer.servACK==1000)
		//{
			m_State = TRUE;
			m_UserData.id = buffer.id;
			m_UserData.servACK = buffer.servACK;
			m_LoginButton.EnableWindow(FALSE);
			m_ExitButton.EnableWindow(TRUE);
			m_SendButton.EnableWindow(TRUE);
			m_ServIP.EnableWindow(FALSE);
			m_ServPort.EnableWindow(FALSE);
			m_UserName.EnableWindow(FALSE);
			this->SetWindowText(strName+"��P2P������");
			MessageBox("���ӳɹ�");
		//}
			LoginToChat();
		break;

	case MULCHATMSG:
		if (strcmp(buffer.m_UserName,m_UserData.userName))
		{
			PlaySound((LPCTSTR)IDR_MULCHATMSG, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);		//��������
		}
		

		//strChat = buffer.chat;
		/*m_UserData.ServChat+=_T(buffer.m_UserName);
		m_UserData.ServChat+="\t";
		m_UserData.ServChat+=strTime;
		m_UserData.ServChat+="\r\n";
		m_UserData.ServChat+=buffer.chat;
		m_UserData.ServChat+="\r\n";
		m_UserData.ServChat+="\r\n";*/
		AddRecvMsg(&(m_UserData.ServChat),&buffer);
		m_ServMsg.SetWindowText(m_UserData.ServChat);
		m_ServMsg.LineScroll(m_ServMsg.GetLineCount());		//	 �Զ����������
		break;

	case EXITMSG: 
		PlaySound((LPCTSTR)IDR_EXITMSG, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);		//��������
		if (buffer.servACK==0)
		{
			m_ClientSock.Close();
			m_State = FALSE;
			m_LoginButton.EnableWindow(TRUE);
			m_ExitButton.EnableWindow(FALSE);
			m_SendButton.EnableWindow(FALSE);
			m_ServIP.EnableWindow(TRUE);
			m_ServPort.EnableWindow(TRUE);
			m_UserName.EnableWindow(TRUE);
			m_OLUserList.ResetContent();	//�Ƴ��б��е�����

			pos = m_P2PChatList.GetHeadPosition();
			PeerData *p_PeerData = NULL;
			while(pos!=NULL)
			{
				p_PeerData = (PeerData*)m_P2PChatList.GetNext(pos);
				delete p_PeerData;
			}
			
		}
		MessageBox(_T("��������Ͽ����ӣ����򼴽��˳���"));
		OnCancel();
		break;
	case ISALIVEMSG:
		//Msg buffer ;
		//buffer.sign = ISALIVEMSG;
		buffer.id = m_UserData.id;
		m_UserData.servACK = buffer.servACK;
		m_ClientSock.SendTo((char*)&buffer, sizeof(buffer),atoi(m_UserData.strPort),m_UserData.strIP,0);
		break;

	case PEERLOGINMSG:
		PlaySound((LPCTSTR)IDR_UPLINE, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);		//��������
		AddRecvMsg(&(m_UserData.ServChat),&buffer);
		m_ServMsg.SetWindowText(m_UserData.ServChat);
		m_ServMsg.LineScroll(m_ServMsg.GetLineCount());		//	 �Զ����������
		break;

	case P2PHOLETO:				//���ܷ�������������peer��ַ
		//buffer.sign = P2PCHATMSG;
		//ShowP2PChatDlg(&buffer);
	//	MessageBox(buffer.m_UserName);
		CreateP2PDlg(&buffer);
		break;

	case P2PCHATMSG:		//����peer���͹�������Ϣ.
							//һ����Ϣ����Ӧ��CLient������������׷�����ݣ��������򴴽��Ի����û�˫���˲���ʾ
		PlaySound((LPCTSTR)IDR_PEERMSG, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);		//��������
		buffer.userAddr  =  m_ServAddr;   //p2pmsg�϶���client��������
		p_PeerData = FindP2PChatDlgByName(buffer.m_UserName);
		if (p_PeerData!=NULL)
		{
			
			if (p_PeerData->peerChatDlg->isActive)
			{
				ShowP2PChatDlg(&buffer);	//	�����Ѵ��ڲ���ʾ��׷������
			}
			else
			{
				p_PeerData->isRead = FALSE;
				UserListLightUp(TRUE,buffer.m_UserName);	//�����Ѵ���δ��ʾ����������׷������
				ShowP2PChatDlg(&buffer);
			}
		}
		else
		{
			UserListLightUp(TRUE,buffer.m_UserName);
			CreateP2PDlg(&buffer); //������׷������
		}
		
		
		break;
	case REGMSG:
		KillTimer(1);
		if (buffer.servACK==-1)
		{
			MessageBox(_T("�û����ѱ�ע�ᣡ��"));
			this->GetDlgItem(IDC_REG2)->EnableWindow(TRUE);
			m_ClientSock.Close();
			return;
		}
		else
		{
			MessageBox(_T("ע��ɹ�����"));
			this->GetDlgItem(IDC_REG2)->EnableWindow(TRUE);
			m_ClientSock.Close();
			GetDlgItem(IDC_LOGIN)->ShowWindow(TRUE);
			GetDlgItem(IDC_REG1)->ShowWindow(TRUE);
			GetDlgItem(IDC_CHECK1)->ShowWindow(TRUE);
			GetDlgItem(IDC_FORGET)->ShowWindow(TRUE);
			GetDlgItem(IDC_CHECK2)->ShowWindow(TRUE);
			GetDlgItem(IDC_CANEL)->ShowWindow(TRUE);
			GetDlgItem(IDC_REG2)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_IDCARD)->ShowWindow(FALSE);
			GetDlgItem(IDC_EDIT_IDCARD)->ShowWindow(FALSE);
			GetDlgItem(IDC_BACK)->ShowWindow(FALSE);

			return;
		}
		break;
	case FORGETMSG:
		KillTimer(1);
		if (buffer.servACK==-1)
		{
			MessageBox(_T("������д���󣡣�"));
			this->GetDlgItem(IDC_FORGET2)->EnableWindow(TRUE);
			m_ClientSock.Close();
			return;
		}
		else
		{
			MessageBox(_T("�����һسɹ�����"));
			m_Password.SetPasswordChar(NULL);
			GetDlgItem(IDC_EDIT_PSW)->EnableWindow(TRUE);
			GetDlgItem(IDC_EDIT_PSW)->SetWindowText(buffer.m_PSW);
			GetDlgItem(IDC_FORGET2)->EnableWindow(TRUE);
			m_ClientSock.Close();
			return;
		}
		break;
	default:;

	};
	KillTimer(2);				// ���ö�ʱ��ʱ��
	SetTimer(2,40000,NULL);
}
void CP2P_ENDDlg::UserListLightUp(BOOL flag,char *userName) //flagΪ��ʱ�����
{
	int index ;
	index = m_OLUserList.FindString(0,userName);
	m_OLUserList.SetSel(index,TRUE);
}

void CP2P_ENDDlg::ShowP2PChatDlg(Message *p_PeerBuffer)
{
	//�ж϶Ի��Ƿ�������б�
	CString userName = p_PeerBuffer->m_UserName;	//	�Է�������
	POSITION pos = m_P2PChatList.GetHeadPosition();
	PeerData *p_PeerData = NULL;
	p_PeerData = FindP2PChatDlgByName(p_PeerBuffer->m_UserName);
	if (!strcmp(p_PeerData->peerName,userName))
	{
		//
		//if (p_PeerData->peerChatDlg->isActive==FALSE)
		//{
		//	p_PeerData->peerChatDlg->ShowWindow(SW_SHOW);	//	���ڵĻ�  show��
		//}
		AddRecvMsg(&(p_PeerData->peerMsgLog),p_PeerBuffer);
		p_PeerData->peerChatDlg->m_PeerRecv.SetWindowText(p_PeerData->peerMsgLog);
		p_PeerData->peerChatDlg->m_PeerRecv.LineScroll(p_PeerData->peerChatDlg->m_PeerRecv.GetLineCount());
		return;	
	}

	//������  �����µ�DLG
	/*m_ChatMsgDlg = new CP2PChatDlg();
	m_ChatMsgDlg->Create(IDD_P2PCHAT,this);
	m_ChatMsgDlg->ModifyStyleEx(0,  WS_EX_APPWINDOW);//��������ʾ
	m_ChatMsgDlg->ShowWindow(SW_SHOW);
	m_ChatMsgDlg->SetWindowText("������"+userName+"��̸��");
	m_ChatMsgDlg->SetParentDlg(this);				//���븸���ڵ�ָ��
	m_ChatMsgDlg->m_SaveMsg = *p_PeerBuffer;
	m_ChatMsgDlg->m_SaveMsg.sign = P2PCHATMSG;

	strcpy(m_ChatMsgDlg->m_SaveMsg.m_UserName,m_UserData.userName);
	strcpy(m_ChatMsgDlg->m_PeerName,userName);

	//m_ChatMsgDlg->m_ParentMsg = *p_PeerBuffer;
	//p_PeerData = NULL;				//����ѭ���󾭳����ǰ�ָ������ ���������ж��䶫��
	p_PeerData = new PeerData();
	p_PeerData->peerAddr = p_PeerBuffer->userAddr;
	p_PeerData->state = true;
	strcpy(p_PeerData->peerName,userName);
	p_PeerData->peerChatDlg = m_ChatMsgDlg;
	if (p_PeerBuffer->sign==P2PHOLETO)
	{
	p_PeerData->peerMsgLog = "��������ɹ�\r\n";
	strcpy(p_PeerData->peerChatDlg->m_SaveMsg.chat,"��������ɹ�\r\n");
	p_PeerData->peerChatDlg->m_PeerRecv.SetWindowText(p_PeerData->peerMsgLog);
	}
	else
	{
	AddRecvMsg(&(p_PeerData->peerMsgLog),p_PeerBuffer);
	p_PeerData->peerChatDlg->m_PeerRecv.SetWindowText(p_PeerData->peerMsgLog);
	}
	//	׷�������¼
	m_P2PChatList.AddTail(p_PeerData); //���뵽�Ի�������ͷ
	m_ChatMsgDlg = NULL;*/
}

void CP2P_ENDDlg::OnServSend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strText;
	Message buffer ;
	int nPort ;
	
	if (m_State)
	{
		this->GetDlgItem(IDC_EDIT_SEND)->GetWindowText(strText);
		if (strText=="")
		{
			MessageBox("���������ݣ�");
			return;
		}
		m_ClientSock.SetDlg(this);
		strcpy(buffer.m_UserName,m_UserData.userName);
		strcpy(buffer.chat,strText.GetBuffer());	strText.ReleaseBuffer();
		buffer.sign = 2;
		buffer.id = m_UserData.id;
		m_ServSend.SetWindowText("");
		nPort = atoi(m_UserData.strPort);
		m_ClientSock.SendTo((char*)&buffer, sizeof(buffer),nPort,m_UserData.strIP,0);
	}
	else
	{
		MessageBox("���ȵ�¼��");
		return;
	}
	
	

	//m_ClientSock.Close();

	//MessageBox("���ӳɹ�");
}

void CP2P_ENDDlg::OnExit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Message buffer ;
	buffer.sign = EXITMSG;
	buffer.id = m_UserData.id;
	m_ClientSock.SendTo((char*)&buffer, sizeof(buffer),atoi(m_UserData.strPort),m_UserData.strIP,0);
}

void CP2P_ENDDlg::UpdateUserList(Message *buffer)
{
	PeerData *p_PeerData=NULL;
	POSITION pos = m_P2PChatList.GetHeadPosition();
	m_OLUserList.ResetContent();
	for(int i=0 ;i<buffer->userNum ; i++ )
	{
		strcpy(m_ClientMsg.OLUserList[i],buffer->OLUserList[i]);
		m_OLUserList.AddString(m_ClientMsg.OLUserList[i]);//���������û��б�
	}
	while (pos!=NULL)
	{
		p_PeerData = (PeerData *)m_P2PChatList.GetNext(pos);
		if (p_PeerData->isRead==FALSE)
		{
			UserListLightUp(TRUE,p_PeerData->peerName);
		}
	}

}

void CP2P_ENDDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch(nIDEvent)
	{
	case 1:
		KillTimer(1);
		if (!m_State)
		{
			MessageBox("���ӷ�������ʱ��");
			m_ClientSock.Close();
			m_LoginButton.EnableWindow(TRUE);
			GetDlgItem(IDC_FORGET2)->EnableWindow(TRUE);
			GetDlgItem(IDC_REG2)->EnableWindow(TRUE);
		}
		break;
	case 2:
		KillTimer(2);
		MessageBox("���������ʧ���ӣ�");
		//this->CloseWindow();
		m_ClientSock.Close();
		m_LoginButton.EnableWindow(TRUE);
		break;
	default:;
	}
	CDialog::OnTimer(nIDEvent);
}

void CP2P_ENDDlg::OnUserList()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//�Ƿ����������һ��P2P����
	Message buffer;
	int listCount;
	int nPort = atoi(m_UserData.strPort);
	PeerData *p_PeerData;
	buffer.sign = P2PHOLETO;
	buffer.id = m_UserData.id;
	listCount = m_OLUserList.GetCurSel();
	m_OLUserList.GetText(listCount,buffer.m_UserName);
	p_PeerData=FindP2PChatDlgByName(buffer.m_UserName);	//	�����Ƿ��Ѵ��ڶԻ���
	if (p_PeerData!=NULL)		//�����ˣ���Ϊ��˫����ֱ��SHOW��
	{
		p_PeerData->isRead = TRUE;
		p_PeerData->peerChatDlg->ShowWindow(SW_SHOW);
		m_OLUserList.SetSel(listCount,FALSE);
		return;
	}
	m_ClientSock.SendTo((char*)&buffer, sizeof(buffer),nPort,m_UserData.strIP,0);//�����ڷ��ʹ�����
	
}


void CP2P_ENDDlg::RecvP2PMsg(Message *p_PeerBuffer)
{

}

PeerData* CP2P_ENDDlg::FindP2PChatDlgByName(char *userName)
{													//	�Է�������
	POSITION pos = m_P2PChatList.GetHeadPosition();
	PeerData *p_PeerData = NULL;
	p_PeerData = new PeerData();		//	������ռ���޷�������ı�����ֵ��
	while(pos!=NULL)
	{
		p_PeerData = (PeerData*)m_P2PChatList.GetNext(pos);
		if (!strcmp(p_PeerData->peerName ,userName))
		{
			return p_PeerData;	
		}
		//isPeerExist = true;
	}
	return NULL;
}

void CP2P_ENDDlg::AddRecvMsg(CString *p_MsgLog,Message *p_MsgBuffer)
{
	CTime t=CTime::GetCurrentTime();
	CString strTime;
	strTime.Format("%d:%d:%d",t.GetHour(),t.GetMinute(),t.GetSecond());

	*p_MsgLog+=p_MsgBuffer->m_UserName;
	*p_MsgLog+="\t";
	*p_MsgLog+=strTime;
	*p_MsgLog+="\r\n";
	*p_MsgLog+=p_MsgBuffer->chat;
	*p_MsgLog+="\r\n";
	*p_MsgLog+="\r\n";

}

void CP2P_ENDDlg::CreateP2PDlg(Message *p_PeerBuffer)
{
	CString userName = p_PeerBuffer->m_UserName;	//	�Է�������
	POSITION pos = m_P2PChatList.GetHeadPosition();
	PeerData *p_PeerData = NULL;
	m_ChatMsgDlg = new CP2PChatDlg();
	m_ChatMsgDlg->Create(IDD_P2PCHAT,this);
	m_ChatMsgDlg->ModifyStyleEx(0,  WS_EX_APPWINDOW);//��������ʾ
	
	m_ChatMsgDlg->SetWindowText("������"+userName+"��̸��");
	m_ChatMsgDlg->SetParentDlg(this);				//���븸���ڵ�ָ��
	m_ChatMsgDlg->m_SaveMsg = *p_PeerBuffer;
	m_ChatMsgDlg->m_SaveMsg.sign = P2PCHATMSG;
	m_ChatMsgDlg->isActive = FALSE;
	strcpy(m_ChatMsgDlg->m_SaveMsg.m_UserName,m_UserData.userName);
	strcpy(m_ChatMsgDlg->m_PeerName,userName);

	//m_ChatMsgDlg->m_ParentMsg = *p_PeerBuffer;
	//p_PeerData = NULL;				//����ѭ���󾭳����ǰ�ָ������ ���������ж��䶫��
	p_PeerData = new PeerData();
	p_PeerData->peerAddr = p_PeerBuffer->userAddr;
	p_PeerData->state = true;
	p_PeerData->isRead = FALSE;
	strcpy(p_PeerData->peerName,userName);
	p_PeerData->peerChatDlg = m_ChatMsgDlg;
	if (p_PeerBuffer->sign==P2PHOLETO)
	{
		m_ChatMsgDlg->ShowWindow(SW_SHOW);
		m_ChatMsgDlg->isActive = TRUE;
		p_PeerData->isRead = TRUE;
		p_PeerData->peerMsgLog = "��������ɹ�\r\n";
		strcpy(p_PeerData->peerChatDlg->m_SaveMsg.chat,"��������ɹ�\r\n");
		p_PeerData->peerChatDlg->m_PeerRecv.SetWindowText(p_PeerData->peerMsgLog);
	}
	else
	{
		AddRecvMsg(&(p_PeerData->peerMsgLog),p_PeerBuffer);
		p_PeerData->peerChatDlg->m_PeerRecv.SetWindowText(p_PeerData->peerMsgLog);
	}
	//	׷�������¼
	m_P2PChatList.AddTail(p_PeerData); //���뵽�Ի�������ͷ
	m_ChatMsgDlg = NULL;
}

void CP2P_ENDDlg::OnEnChangeEditServport()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CP2P_ENDDlg::OnCanel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->OnCancel();
}

void CP2P_ENDDlg::OnSetting()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	PlaySound((LPCTSTR)IDR_FOLDER, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);		//��������

	if(m_Extend)
	{
		this->MoveWindow(470,260,327,230,1);
		GetDlgItem(IDC_SETTING)->SetWindowText("�߼����á�");		
		m_Extend=FALSE;
	}
	else
	{
		this->MoveWindow(470,260,327,360,1);
		GetDlgItem(IDC_SETTING)->SetWindowText("�߼����á�");
		m_Extend=TRUE;
	}
}

void CP2P_ENDDlg::OnForget()
{
	GetDlgItem(IDC_LOGIN)->ShowWindow(FALSE);
	GetDlgItem(IDC_REG1)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK1)->ShowWindow(FALSE);
	GetDlgItem(IDC_FORGET)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK2)->ShowWindow(FALSE);
	GetDlgItem(IDC_CANEL)->ShowWindow(FALSE);
	GetDlgItem(IDC_FORGET2)->ShowWindow(TRUE);
	GetDlgItem(IDC_BACK)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_IDCARD)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_IDCARD)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_PSW)->EnableWindow(FALSE);
}

void CP2P_ENDDlg::LoginToChat()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_SETTING)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_LOGIN)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_PSW)->ShowWindow(FALSE);
	GetDlgItem(IDC_LOGIN)->ShowWindow(FALSE);
	GetDlgItem(IDC_REG1)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK1)->ShowWindow(FALSE);
	GetDlgItem(IDC_FORGET)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK2)->ShowWindow(FALSE);
	GetDlgItem(IDC_CANEL)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_BOX1)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_PSW)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_SERVIP)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_SERVPORT)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_BOX2)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_IP)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_PORT)->ShowWindow(FALSE);
	MoveWindow(350,200,600,400,1);
	GetDlgItem(IDC_BUTTON_EXIT)->SetWindowPos( NULL,500,10,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
	GetDlgItem(IDC_EDIT_SERVMSG)->SetWindowPos( NULL,10,60,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
	GetDlgItem(IDC_EDIT_SEND)->SetWindowPos( NULL,10,280,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
	GetDlgItem(IDC_LIST1)->SetWindowPos( NULL,450,80,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
	GetDlgItem(IDC_BUTTON_CLEAR)->SetWindowPos( NULL,340,255,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
	GetDlgItem(IDC_STATIC_LIST)->SetWindowPos( NULL,450,60,0,0,SWP_NOZORDER | SWP_NOSIZE ); 
	GetDlgItem(IDC_SERVSEND)->SetWindowPos( NULL,420,340,0,0,SWP_NOZORDER | SWP_NOSIZE ); 

}
void CP2P_ENDDlg::OnClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_UserData.ServChat = "";
	GetDlgItem(IDC_EDIT_SERVMSG)->SetWindowText("");

}

void CP2P_ENDDlg::OnReg1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_LOGIN)->ShowWindow(FALSE);
	GetDlgItem(IDC_REG1)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK1)->ShowWindow(FALSE);
	GetDlgItem(IDC_FORGET)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK2)->ShowWindow(FALSE);
	GetDlgItem(IDC_CANEL)->ShowWindow(FALSE);
	GetDlgItem(IDC_REG2)->ShowWindow(TRUE);
	GetDlgItem(IDC_BACK)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_IDCARD)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_IDCARD)->ShowWindow(TRUE);
}

void CP2P_ENDDlg::OnReg2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strName;
	CString strPSW;
	CString strIDCard;
	
	this->GetDlgItem(IDC_EDIT_LOGIN)->GetWindowText(strName);
	this->GetDlgItem(IDC_EDIT_PSW)->GetWindowText(strPSW);
	this->GetDlgItem(IDC_EDIT_IDCARD)->GetWindowText(strIDCard);
	this->GetDlgItem(IDC_EDIT_SERVIP)->GetWindowText(m_UserData.strIP);
	this->GetDlgItem(IDC_EDIT_SERVPORT)->GetWindowText(m_UserData.strPort);
	if (strName.GetLength()<8)
	{
		MessageBox("�û�����������ĸ����ֻ���8���ַ���");
		return;
	}
	if (strPSW.GetLength()<5)
	{
		MessageBox("������������λ��");
		return;
	}
	if (strIDCard.GetLength()==0)
	{
		MessageBox("���������֤���룡");
		return;
	}
	if (strIDCard.GetLength()!=18)
	{
		MessageBox("��������ȷ�����֤���룡");
		return;
	}
	if(m_UserData.strIP.GetLength()==0||m_UserData.strPort.GetLength()==0)
	{
		MessageBox("������IP�Ͷ˿ں�");
		return;
	}
	strcpy(m_ClientMsg.m_UserName,strName.GetBuffer());
	strcpy(m_ClientMsg.m_PSW,strPSW.GetBuffer());
	strcpy(m_ClientMsg.m_IDCard,strIDCard.GetBuffer());
	strName.ReleaseBuffer();
	strPSW.ReleaseBuffer();
	strIDCard.ReleaseBuffer();
	m_ClientMsg.sign = REGMSG;
	m_ClientMsg.id = 1;
	m_ClientSock.SetDlg(this);
	if(!m_ClientSock.Create(0,SOCK_DGRAM))		//	0��ʾ�ͻ�������˿�
	{
		char szMsg[1024] = {0};
		sprintf(szMsg, "create faild: %d", m_ClientSock.GetLastError());
		AfxMessageBox(szMsg);
		return;
	}
	int nPort = atoi(m_UserData.strPort);
	m_ClientSock.SendTo((char*)&m_ClientMsg, sizeof(m_ClientMsg),nPort,m_UserData.strIP,0);
	this->GetDlgItem(IDC_REG2)->EnableWindow(FALSE);
	SetTimer(1,10000,NULL);   //���ö�ʱ�����жϵ�½��ʱ
	//����һ�β����ٰ��ˣ���Ϊ�ͻ��˴��������ӻ�û�ر�

}

void CP2P_ENDDlg::OnBack()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->GetDlgItem(IDC_FORGET2)->ShowWindow(FALSE);
	this->GetDlgItem(IDC_EDIT_PSW)->EnableWindow(TRUE);
	this->GetDlgItem(IDC_EDIT_PSW)->SetWindowText("");
	this->GetDlgItem(IDC_EDIT_IDCARD)->SetWindowText("");
	m_Password.SetPasswordChar('*');
	if (m_ClientSock)
	{
		m_ClientSock.Close();
	}
	
	GetDlgItem(IDC_LOGIN)->ShowWindow(TRUE);
	GetDlgItem(IDC_REG1)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK1)->ShowWindow(TRUE);
	GetDlgItem(IDC_FORGET)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK2)->ShowWindow(TRUE);
	GetDlgItem(IDC_CANEL)->ShowWindow(TRUE);
	GetDlgItem(IDC_REG2)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_IDCARD)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_IDCARD)->ShowWindow(FALSE);
	GetDlgItem(IDC_BACK)->ShowWindow(FALSE);
}

void CP2P_ENDDlg::OnForget2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strName;
	CString strPSW;
	CString strIDCard;

	this->GetDlgItem(IDC_EDIT_LOGIN)->GetWindowText(strName);
	this->GetDlgItem(IDC_EDIT_PSW)->GetWindowText(strPSW);
	this->GetDlgItem(IDC_EDIT_IDCARD)->GetWindowText(strIDCard);
	this->GetDlgItem(IDC_EDIT_SERVIP)->GetWindowText(m_UserData.strIP);
	this->GetDlgItem(IDC_EDIT_SERVPORT)->GetWindowText(m_UserData.strPort);
	if (strName.GetLength()==0)
	{
		MessageBox("�������û���");
		return;
	}
	if (strIDCard.GetLength()==0)
	{
		MessageBox("���������֤����");
		return;
	}
	if(m_UserData.strIP.GetLength()==0||m_UserData.strPort.GetLength()==0)
	{
		MessageBox("������IP�Ͷ˿ں�");
		return;
	}
	strcpy(m_ClientMsg.m_UserName,strName.GetBuffer());
	strcpy(m_ClientMsg.m_PSW,strPSW.GetBuffer());
	strcpy(m_ClientMsg.m_IDCard,strIDCard.GetBuffer());
	strName.ReleaseBuffer();
	strPSW.ReleaseBuffer();
	strIDCard.ReleaseBuffer();
	m_ClientMsg.sign = FORGETMSG;
	m_ClientMsg.id = 1;
	m_ClientSock.SetDlg(this);
	if(!m_ClientSock.Create(0,SOCK_DGRAM))		//	0��ʾ�ͻ�������˿�
	{
		char szMsg[1024] = {0};
		sprintf(szMsg, "create faild: %d", m_ClientSock.GetLastError());
		AfxMessageBox(szMsg);
		return;
	}
	int nPort = atoi(m_UserData.strPort);
	m_ClientSock.SendTo((char*)&m_ClientMsg, sizeof(m_ClientMsg),nPort,m_UserData.strIP,0);
	this->GetDlgItem(IDC_FORGET2)->EnableWindow(FALSE);
	SetTimer(1,10000,NULL);   //���ö�ʱ�����жϵ�½��ʱ
	//����һ�β����ٰ��ˣ���Ϊ�ͻ��˴��������ӻ�û�ر�
}

void CP2P_ENDDlg::OnEnChangeEditIdcard()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
