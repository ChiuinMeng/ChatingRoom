#define MAXUSERS 100
#define LOGINMSG 1
#define MULCHATMSG 2
#define P2PCHATMSG 3
#define P2PHOLETO 4
#define ISALIVEMSG 5
#define PEERLOGINMSG 6
#define REGMSG 7
#define FORGETMSG 8
#define EXITMSG 0

#ifndef FUN_H				//�����������һ��		�ṹ���ͷ��Ҫ�Զ������ ������ض���
#define FUN_H

class CP2PChatDlg;

typedef struct UserData
{
	int id;
	char userName[20];
	bool isAlive;
	int servACK;
	CString strIP;
	CString strPort;
	CString ServChat;
	//sockaddr_in addr;
	//struct UserData *FNode;  //ȡ�����ѻ���
	int idFlag ;   // 0��ʾ��ͨ�û���1��ʾ��ʱ������
	bool selFlag ;   //�Ƿ��Ѿ�ͶƱ

};

typedef struct Message
{
	int sign;				//��Ϣ����       1��ʾ��½  2��ʾ������Ϣ
	int id;
	int userNum;
	int servACK;
	int peerACK;
	char chat[100];			//�û����ݵ���Ϣ
	char m_UserName[20];
	char m_PSW[20];
	char m_IDCard[20];
	sockaddr_in userAddr;
	char OLUserList[MAXUSERS][20];
};

typedef struct ServerData
{
	int userNum;				//OL
	bool state;
	CString servLog;
	sockaddr_in addrServ;		//�������ĵ�ַ��Ϣ
	SOCKET ClientSock;        //�ͻ�����������
	SOCKET ServerSock;                 
	UserData OLUserList[MAXUSERS];	//�����û��б�
};

typedef struct PeerData
{
	char peerName[20];				
	bool state;
	BOOL isRead;  //�Ƿ��Ѷ�
	CString peerMsgLog;			//	��Ϣ��¼
	sockaddr_in peerAddr;		//Peer�ĵ�ַ��Ϣ
	CP2PChatDlg *peerChatDlg;
	
};

#endif