//////////////////////////////////////////////////////////////////////
//	Implemented by Samuel Gonzalo 
//
//	You may freely use or modify this code 
//////////////////////////////////////////////////////////////////////
//
// Path.h: interface for the CPath class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(__PATH_H__)
#define __PATH_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>

/* calin - added */
#define VERINFO_ProductName			"ProductName"
#define VERINFO_CompanyName			"CompanyName"
#define VERINFO_ProductVersion		"ProductVersion"
#define VERINFO_comments			"Comments"
#define VERINFO_FileDescrib			"FileDescription"
#define VERINFO_FileVersion			"FileVersion"
#define VERINFO_InternalName		"InternalName"
#define VERINFO_LegalCopyright		"LegalCopyright"
#define VERINFO_LegalTrademarks		"LegalTrademarks"
#define VERINFO_OriginalFilename	"OriginalFilename"
#define VERINFO_PrivateBuild		"PrivateBuild"
#define VERINFO_SpecialBuild		"SpecialBuild"

struct LANGANDCODEPAGE 
{
	WORD wLanguage;
	WORD wCodePage;
};
/* calin - added */

const TCHAR	sCEmptyString = 0x0;
enum		{PATH_CMDLINE, PATH_MODULE};
enum		{FILE_CREATION, FILE_ACCESS, FILE_WRITE};

class CPath  
{
public:
	CPath();
	CPath(LPCTSTR szPath, BOOL bIsFolderPath = FALSE);
	CPath(DWORD dwSpecial);
	virtual ~CPath();

	// Parses a path or PATH_CMDLINE, PATH_MODULE
	void	SetPath(LPCTSTR szPath, BOOL bIsFolderPath = FALSE);
	CString	GetPath(BOOL bAppendArgs = FALSE, BOOL bOriginal = FALSE);
	CString	GetShortPath();
	CString	GetLongPath();

	BOOL IsLocalPath();
	BOOL IsRelativePath();
	BOOL IsFilePath();

	BOOL ExistFile();
	BOOL ExistLocation();


	// If the path set in the object is not a relative one returns empty
	CString	GetAbsolutePath(LPCTSTR szBaseFolder);

	// If the path set in the object is a relative one returns empty
	CString	GetRelativePath(LPCTSTR szBaseFolder);


	// Get drive string (empty for a network path) [e.g.: "c:"]
	CString	GetDrive();

	// Get drive label (pc name for a network path) [e.g.: "MAIN_HD"]
	CString	GetDriveLabel(BOOL bPCNameIfNetwork = FALSE);

	// Get folder count in path [e.g.: 2 for "c:\folder\subfolder\file.ext"]
	int		GetDirCount();

	// Get 0 based nIndex folder string [e.g.: "folder" for nIndex = 0]
	// If nIndex = -1 the return string is the full dir string 
	// [e.g.: "\folder\subfolder\" or "\\pcname\folder\" for non-local]
	// If it's a relative path no "\" is added at the beginning [e.g.: "..\sub\"]
	CString	GetDir(int nIndex = -1);

	// File location or directory path [e.g.: "c:\folder\subfolder\"]
	CString	GetFolderPath();

	// File title string (without extension) [e.g.: "file" for "..\file.ext"]
	CString	GetFileTitle();

	// Filename = File title + extension [e.g.: "file.ext"]
	CString	GetFileName();

	// Extension string (dot included) [e.g.: ".ext"]
	CString	GetExtension();

	// Extension name (dot not included) [e.g.: "ext"]
	CString	GetExtName();

	/* CALIN - added */
	//get the version information
	CString GetFileVersionInfoString(LPCSTR verInfoString);
	/* CALIN - added */

	
	// Get the size in bytes of the current file
	BOOL	GetFileSize(__int64 &nSize);

	// Get the size in bytes of the current file
	// values: FILE_CREATION, FILE_ACCESS, FILE_WRITE
	BOOL	GetFileTime(CTime &time, DWORD dwType = FILE_WRITE);


	// Return a temporary character pointer to the path data.
	operator LPCTSTR ();

	// Same as SetPath(szPath, FALSE, FALSE)
	const CPath& operator = (LPCTSTR szPath);

	// Makes a copy of the object
	const CPath& operator = (CPath &ref);

	// Add a back slash ('\' or '/' if bInverted is TRUE) if necessary
	static CString AddBackSlash(LPCTSTR szFolderPath, BOOL bInverted = FALSE);

	// Removes a trailing back slash if found
	static CString RemoveBackSlash(LPCTSTR szFolderPath);
	static CString CastItoXBytes(double count,  UINT decimal = 2)	;

private:
	void FillDirArray();
	BOOL FillFileInfoStruct();

	CString			_strOriginalPath;

	CString			_strDrive;
	CString			_strDriveLabel;
	CStringArray	_arrDir;
	CString			_strDir;
	CString			_strFileTitle;
	CString			_strExtName;

	BOOL			_bIsRelative;

	BY_HANDLE_FILE_INFORMATION _fis;

	CString			_sLPCTSTRPath;
};

#endif // !defined(__PATH_H__)
