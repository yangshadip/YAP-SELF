// dllmain.cpp : Defines the entry point for the DLL application.
#include "Implement/LogUserImpl.h"
#include "Implement/YapImplement.h"
#include "Implement/ContainerImpl.h"
#include "DicomReader.h"

#ifdef _DEBUG
#pragma comment(lib,"ITKCommon-4.12.lib")
#pragma comment(lib,"ITKIOGDCM-4.12.lib")
#pragma comment(lib,"ITKIOImageBase-4.12.lib")
#pragma comment(lib,"itkvnl-4.12.lib")
#pragma comment(lib,"itkvcl-4.12.lib")
#pragma comment(lib,"itksys-4.12.lib")
#pragma comment(lib,"itknetlib-4.12.lib")
#pragma comment(lib,"itkv3p_netlib-4.12.lib")
#pragma comment(lib,"itkvnl_algo-4.12.lib")
#else
	#pragma comment(lib,"..\\release\\LedCtrlBoard.lib")
#endif

using namespace Yap;

BEGIN_DECL_PROCESSORS
	ADD_PROCESSOR(DicomReader)
END_DECL_PROCESSORS


//BOOL APIENTRY DllMain(HMODULE hModule,
//	DWORD  ul_reason_for_call,
//	LPVOID lpReserved
//)
//{
//	switch (ul_reason_for_call)
//	{
//	case DLL_PROCESS_ATTACH:
//
//		break;
//	case DLL_THREAD_ATTACH:
//		break;
//	case DLL_THREAD_DETACH:
//		break;
//	case DLL_PROCESS_DETACH:
//		break;
//	}
//	return TRUE;

