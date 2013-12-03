#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H

// 是否启用map转换，建议启用
// 使用map转换的话，同一个常量字符串不会做两次转换
#define TEST_TYPE_MAP

#ifdef TEST_TYPE_MAP
#include <map>
using namespace std;
#endif

typedef map<const char*, const char*> strmap;

class CUtf8String
{
public:
	inline CUtf8String(const char* gb2312)
	{
		m_bIsConst = true;
#ifdef TEST_TYPE_MAP
		if (m[gb2312])
		{
			m_utf8 = m[gb2312];
			return ;
		}
#endif
		int buffLen = 0;
		WCHAR wbuff[5120];
		MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wbuff, 5120);
		buffLen = WideCharToMultiByte(CP_UTF8, 0, wbuff, -1, NULL, 0, 0, 0);
		m_utf8 = new char[buffLen+1];
		WideCharToMultiByte(CP_UTF8, 0, wbuff, -1, (LPSTR)m_utf8, buffLen, 0, 0);
#ifdef TEST_TYPE_MAP
		m[gb2312] = m_utf8;
#endif
	}

	inline CUtf8String(char* gb2312)
	{
		m_bIsConst = false;
		int buffLen = 0;
		WCHAR wbuff[5120];
		MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wbuff, 5120);
		buffLen = WideCharToMultiByte(CP_UTF8, 0, wbuff, -1, NULL, 0, 0, 0);
		m_utf8 = new char[buffLen+1];
		WideCharToMultiByte(CP_UTF8, 0, wbuff, -1, (LPSTR)m_utf8, buffLen, 0, 0);
	}

	inline ~CUtf8String()
	{
#ifndef TEST_TYPE_MAP
		if (m_utf8)
		{
			delete m_utf8;
			m_utf8 = 0;
		}
#else
		if (!m_bIsConst)
		{
			if (m_utf8)
			{
				delete m_utf8;
				m_utf8 = 0;
			}
		}
#endif
	}

	inline operator char*()
	{
		return (char*)m_utf8;
	}
private:
	const char* m_utf8;
	bool m_bIsConst;
#ifdef TEST_TYPE_MAP
	static strmap m;
#endif
};

class CGb2312String
{
public:
	inline CGb2312String(const char* utf8)
	{
#ifdef TEST_TYPE_MAP
		if (m[utf8])
		{
			m_gb2312 = 0;
			m_gb2312 = m[utf8];
		}
#endif
		int buffLen = 0;
		WCHAR wbuff[5120];
		MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wbuff, 5120);
		buffLen = WideCharToMultiByte(CP_ACP, 0, wbuff, -1, NULL, 0, 0, 0);
		m_gb2312 = new char[buffLen+1];
		WideCharToMultiByte(CP_ACP, 0, wbuff, -1, (LPSTR)m_gb2312, buffLen, 0, 0);
#ifdef TEST_TYPE_MAP
		m[utf8] = m_gb2312;
#endif
	}

	inline CGb2312String(char* utf8)
	{
#ifdef TEST_TYPE_MAP
		if (m[utf8])
		{
			m_gb2312 = 0;
			m_gb2312 = m[utf8];
		}
#endif
		int buffLen = 0;
		WCHAR wbuff[5120];
		MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wbuff, 5120);
		buffLen = WideCharToMultiByte(CP_ACP, 0, wbuff, -1, NULL, 0, 0, 0);
		m_gb2312 = new char[buffLen+1];
		WideCharToMultiByte(CP_ACP, 0, wbuff, -1, (LPSTR)m_gb2312, buffLen, 0, 0);
#ifdef TEST_TYPE_MAP
		m[utf8] = m_gb2312;
#endif
	}

	inline ~CGb2312String()
	{
#ifndef TEST_TYPE_MAP
		if (m_gb2312)
		{
			delete m_gb2312;
			m_gb2312 = 0;
		}
#endif
	}

	inline operator char*()
	{
		return (char*)m_gb2312;
	}
private:
	const char* m_gb2312;
#ifdef TEST_TYPE_MAP
	strmap m;
#endif
};





//=========================================无聊的分割线=============================================

//#define U   (CUtf8String)

//#define W   (CGb2312String)


class CommonFunction
{
public:
	CommonFunction();
	~CommonFunction();
protected:
private:
public:
	static int MessageBox(TCHAR* lpText,TCHAR* lpCaption = _T(""),UINT uType = MB_OK );
	static int MessageBox(std::string lpText,std::string lpCaption = "",UINT uType = MB_OK );
	// 用于显示中文字符
	static char* G2U(const char* gb2312);
	static bool UTF8ToGB2312(string utf8, string& retGB2312);
};

#define _CG2U(a)  CommonFunction::G2U(a)
#define _CALEART CommonFunction::MessageBox
#define W(utf8,gb2312)   CommonFunction::UTF8ToGB2312(utf8,gb2312)
#endif