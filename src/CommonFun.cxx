#include "Dungeoned.h"
#include "CommonFun.h"
CommonFunction::CommonFunction()
{

}
CommonFunction::~CommonFunction()
{

}
char* CommonFunction::G2U(const char* gb2312)
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);    
	wchar_t* wstr = new wchar_t[len+1];    
	memset(wstr, 0, len+1);    
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);    
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);    
	char* str = new char[len+1];    
	memset(str, 0, len+1);    
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);    
	if(wstr) delete[] wstr;    
	return str;
	MessageBoxA(NULL,"","",0);
}
bool CommonFunction::UTF8ToGB2312(string utf8, string& retGB2312)
{
	string wStr = "";

	MultiByteToWideChar(CP_UTF8, 0, (LPSTR)utf8.data(), -1, (LPWSTR)wStr.data(), utf8.size()*2);
	int buffLen = WideCharToMultiByte(CP_ACP, 0, (LPWSTR)wStr.data(), -1, NULL, 0, 0, 0);
	WideCharToMultiByte(CP_ACP, 0, (LPWSTR)wStr.data(), -1, (LPSTR)retGB2312.data(), buffLen, 0, 0);
	return true;
}


int CommonFunction::MessageBox(TCHAR* lpText,TCHAR* lpCaption ,UINT uType)
{
	if(lpText == NULL) {
		return NULL;
	}
	return ::MessageBox(NULL,lpText,lpCaption,uType);
}
int CommonFunction::MessageBox(string lpText,string lpCaption ,UINT uType)
{
	return CommonFunction::MessageBox(lpText.data(),lpCaption.data(),uType);
}

