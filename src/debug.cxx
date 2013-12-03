#ifdef _DEBUG
#include <stdio.h>
#include <stdarg.h>
#include <windows.h>

void _trace(char *fmt, ...)
{
	char out[1024];
	va_list body;
	va_start(body, fmt);
	vsprintf(out, fmt, body);     // 译注：格式化输入的字符串 fmtt
	va_end(body);                 //       到输出字符串 ou
	OutputDebugStringA(out);       // 译注：输出格式化后的字符串到调试器
}
#endif