// AXPFile.h: interface for the CAXPFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AXPFILE_H__1F63FE1D_32CD_4A16_A98F_9566B985CD2C__INCLUDED_)
#define AFX_AXPFILE_H__1F63FE1D_32CD_4A16_A98F_9566B985CD2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
#include <string>
using namespace std;
const DWORD AXP_SIGNATURE = 0x4B505841;

class CAXPFile  
{
	typedef struct _AXPHeader
	{
		int signature;				// Axp�ļ���־
		int nUnknow0;				
		int nUnknow1;
		int nHashTableOffset;		// ��ϣ���ļ�ƫ��
		int nIndexTableOffset;		// �ļ�������Ϣƫ��
		int nFileCount;				// �ļ�����
		int nSizeOfIndexTable;		// �ļ��������С
		int nDataOffset;
		int nUnknow3;
		int nUnknow4;
	}AXPHeader;
	
	typedef struct _AXPHashTable
	{
		DWORD nHashA;					
		DWORD nHashB;
		DWORD bExists;
	}AXPHashTable;
	
	typedef struct _AXPFileInfo
	{
		int nFileOffset;				// �ļ�ƫ��
		int nFileSize;					// �ļ���С
		int nFileFlag;					// �ļ���־ 
	}AXPFileInfo;

public:
	BOOL GetHashTablePos(const char *lpszString, int *lpFileOffset, int *lpFileSize);
	DWORD HashString(const char *lpszFileName, DWORD dwCryptIndex);
	void SetFileName(LPCTSTR lpFileName);
	void UnLoad();
	BOOL LoadFile();
	BOOL GenerateFile(int i, CString &strFileName);
	CAXPFile();
	virtual ~CAXPFile();
	
private:
	DWORD	m_CryptTable[0x500];


private:
	AXPHeader		*m_lpAxPHeader;
	AXPHashTable	**m_lpAxpHashTable;
	AXPFileInfo		**m_lpAxpFileInfo;

	CString			m_FileName;
	HANDLE			m_hFile;
	HANDLE			m_hFileMap;
	LPVOID			m_hMapView;
	DWORD			m_dwFileSize;
public:
    vector<string>  m_FileList;
protected:
	BOOL GetFileList();
	void Release();
	void ShowErrorMessage();
	BOOL MappingFile();
	void PrepareCryptTable();
};

#endif // !defined(AFX_AXPFILE_H__1F63FE1D_32CD_4A16_A98F_9566B985CD2C__INCLUDED_)
