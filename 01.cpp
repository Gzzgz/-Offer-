/*
������1����ֵ���������
��Ŀ������Ϊ����CMyString����������Ϊ��������Ӹ�ֵ�����������
class CMyString{
public:
CMyString(char* pData = nullptr);
CMyString(const CMyString& str);
~CMyString(void);

private:
char* m_pData;
};

*/
#include <iostream>
#include <string>


class CMyString{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString();
public:
	CMyString& operator = (const CMyString& str);

	void Print();

private:
	char* m_pData;
};

CMyString::CMyString(char* pData) {

	if (pData == nullptr) {
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else {
		int len = strlen(pData);
		m_pData = new char[len + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str) {

	int len = strlen(str.m_pData);
	m_pData = new char[len + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString& CMyString:: operator = (const CMyString& str) {

	if (this == &str) {
		return *this;
	}
	if (m_pData != nullptr) {
		delete[] m_pData;
		m_pData = nullptr;
	}
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	/*
		if (this != &str) {
		CMyString strTemp(str);//new �µ��ڴ棬��ʧ�ܲ���ı�֮ǰ������
		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;//���þֲ������ͷ�ָ����ڴ�
		m_pData = pTemp;
	}
	*/
	return *this;
}

CMyString::~CMyString() {

	if (m_pData != nullptr) {
		delete[] m_pData;
	}
	m_pData = nullptr;
}

void CMyString::Print(){

	printf("%s", m_pData);
}

/*test cases*/

void Test1()
{
	printf("Test1 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
}
// ��ֵ���Լ�
void Test2()
{
	printf("Test2 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.Print();
	printf(".\n");
}
// ������ֵ
void Test3()
{
	printf("Test3 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.Print();
	printf(".\n");
}

int main() {

	Test3();

	return 0;
}