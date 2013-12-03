#include "Dungeoned.h"
#include "language.h"
#include <stdio.h>
#ifdef WIN32
#include <direct.h>
#include <stdlib.h>
#endif

#ifdef LINUX
#include <unistd.h>
#endif


CLanguage CLanguage::Language;
CLanguage::CLanguage()
{
	m_xmlDoc = NULL;
}

CLanguage::~CLanguage()
{

}
int CLanguage::ReadProperty(string key, string str)
{
	if(key =="LaguageType"){
		m_languageType = str;
	}

	return 0;
}
int CLanguage::LoadLanguage(string path)
{
	try {
		char rootPath[256] = {0};
		getcwd(rootPath,256);
		path = "/" + path;
		path = rootPath + path;


		TiXmlDocument ml;

		TiXmlDocument doc(path.data()); 
		bool loadOkay = doc.LoadFile();
		if(!loadOkay)
		{
			return -1;
		}
		TiXmlNode* node = NULL;
		TiXmlElement* lanElement = NULL;
		TiXmlElement* itemElement = NULL;
		node = doc.FirstChild("Language");
		lanElement = node->ToElement();
		node = lanElement->FirstChild("LanguageType");
		if(node == NULL)
		{
			throw(new string("No LanguageType"));
		}
		itemElement = node->ToElement();
		
		W(itemElement->GetText(),m_languageType);
//		CommonFunction::UTF8ToGBK(m_languageType._Myptr());
		node = lanElement->FirstChild("LaguangeString");
		if(node == NULL)
		{
			throw(new string("No LaguangeString"));
		}

		itemElement = node->FirstChildElement();

		for( itemElement; itemElement; itemElement=itemElement->NextSiblingElement())
		{
			string str = "";
			const char *pKey=itemElement->Value();
			//W(itemElement->GetText(),str);
			str = itemElement->GetText();
			AddString(pKey,str.data());
		}

		string s = this->GetString("Title");

	}
	catch(string s)
	{
		_CALEART(s);
		return -1;
	}

	//m_dictionary.
	return 0;
}
string CLanguage::GetString(string key)
{	
	string str = "";

	map<string, string>::iterator x = m_dictionary.find(key);
	if(x != m_dictionary.end()) {
		str = x->second;
	}
	return str;
}
unsigned int CLanguage::GetCount()
{
	
	return m_dictionary.max_size();
}
int CLanguage::AddString(string key,string str)
{
	m_dictionary[key] = str;
	return 0;
}
int CLanguage::RemoveString(string key)
{	
	return m_dictionary.erase(key);
}
int CLanguage::EmptyString()
{	
	return m_dictionary.empty();
}
int CLanguage::ReplaceString(string key,string str)
{
	map<string, string>::iterator x = m_dictionary.find(key);
	if(x != m_dictionary.end()) {
		m_dictionary[key] =str;
		return 0;
	}
	return -1;
}
string& CLanguage::operator [](string key)
{
	string str = "";
	return m_dictionary[key];
}