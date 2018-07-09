#include "EMailLibrary.h"

typedef bool(*_SendMail)(char* Mail, char* Pass, char* Tittle, char* Body);
_SendMail mSendMail = NULL;

void *dllHandle = nullptr;

bool UEMailLibrary::SendEMail(const FString& EMail, const FString& Pass, const FString& Tittle, const FString& Body)
{
	if (!dllHandle)
	{
		FString filePath = TEXT("EMailSharp.dll");
		dllHandle = FPlatformProcess::GetDllHandle(*filePath); // Retrieve the DLL.
		if (!dllHandle)
		{
			UE_LOG(LogTemp, Error, TEXT("cant find fll"));
			return false;
		}
	}

	if (mSendMail == NULL)
	{
		FString procName = "SendEmail";	// Needs to be the exact name of the DLL method.
		mSendMail = (_SendMail)FPlatformProcess::GetDllExport(dllHandle, *procName);
		if (mSendMail == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("cant find method"));
			return false;
		}
	}
	return (bool)mSendMail(TCHAR_TO_UTF8(*EMail), TCHAR_TO_UTF8(*Pass), TCHAR_TO_UTF8(*Tittle), TCHAR_TO_UTF8(*Body));
}

