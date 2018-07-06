#include <windows.h>
#include <tchar.h>
#include <string>
#include <string.h>
#include <time.h>
#include <ctime>
#include <vector>
#include "resource.h"

using namespace std;

HWND hListRand, hEditRez, hButStart, hRad1, hRad2, hRad3;
TCHAR text[255], data1[100];
INT Radix = 10, number;
vector<int> arr;
int first, second, third, fouth, fifth;


BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	// создаём главное окно приложения на основе модального диалога
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0); // закрываем модальный диалог
		return TRUE;
	case WM_INITDIALOG:
		hListRand = GetDlgItem(hWnd, IDC_LIST_RAND);
		hEditRez = GetDlgItem(hWnd, IDC_EDIT1);
		hButStart = GetDlgItem(hWnd, IDC_BUTTON_START);
		hRad1 = GetDlgItem(hWnd, IDC_RADIO1);
		hRad2 = GetDlgItem(hWnd, IDC_RADIO2);
		hRad3 = GetDlgItem(hWnd, IDC_RADIO3);
		//CheckDlgButton(hWnd, IDC_RADIO1, BST_CHECKED);
		SetWindowText(hEditRez, TEXT(" результат"));

		return TRUE;
	case WM_COMMAND:
		srand(time(0));
		if ((LOWORD(wp) == IDC_BUTTON_START))
		{
			SendMessage(hListRand, LB_RESETCONTENT, 0, 0);
			for (int i = 0; i < 2; i++)
			{	
				number = rand() % 21 -10;
				if (number == 0)
				{
					break;
				}
				arr.push_back(number);
				_itow_s(number, text, Radix);
				SendMessage(hListRand, LB_ADDSTRING, 0, LPARAM(text));
				//


			}
			first = arr[1];
			_itow_s(first, data1, Radix);
			SetWindowText(hEditRez, data1);
		}
		return TRUE;
		if (IsDlgButtonChecked(hWnd, IDC_RADIO2))
		{
			GetWindowText(hListRand, text, 255);
			MessageBox(hWnd, text, NULL, MB_OK | MB_ICONINFORMATION);
			return TRUE;
		}
	}
	return FALSE;
}