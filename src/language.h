#ifndef LANGUAGE_H
#define LANGUAGE_H

using namespace std;
class CLanguage
{
private:
	map<string,string> m_dictionary;
	TiXmlDocument* m_xmlDoc;
	string m_languageType;

	int ReadProperty(string key, string str);
public:
	CLanguage();
	~CLanguage();
	int LoadLanguage(string path);
	string GetString(string key);
	unsigned int GetCount();
	int AddString(string key,string str);
	int RemoveString(string key);
	int EmptyString();
	int ReplaceString(string key,string str);
	string& operator [](string key);
public:
	static CLanguage Language;
};

#define _Language CLanguage::Language

#endif