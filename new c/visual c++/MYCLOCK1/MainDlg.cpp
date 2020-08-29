#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
��������http://www.rupeng.com����ѧ�������ѧϰ�������ṩ���������Ƶѧϰ�̳̣��ṩ���Ի�һ��һѧϰָ��
*/
BOOL WINAPI Main_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG, Main_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND, Main_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE, Main_OnClose);
    }

    return FALSE;
}
void CALLBACK MyTimerProc(HWND hwnd,UINT message,UINT iTemerID,DWORD deTime)
{

SYSTEMTIME stLocal;//����һ���ṹ�����
GetLocalTime(&stLocal);
TCHAR strTime[256];
wsprintf(strTime,"%i��%i��%i�� %i:%i:%i",stLocal.wYear,stLocal.wMonth,stLocal.wDay,stLocal.wHour,stLocal.wMinute,stLocal.wSecond);
SetDlgItemText(hwnd,IDC_EDIT1,strTime);



}
BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{

	SetTimer(hwnd,0,1000,MyTimerProc);
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
			MessageBox(hwnd,TEXT("��ӭ���������� www.RuPeng.com ��ѧ�������ѧϰ����"),TEXT("�ʺ�"),MB_OK);
        break;
        default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}