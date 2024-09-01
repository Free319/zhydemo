#ifndef __ZHYLIB_H__
#define __ZHYLIB_H__

#ifdef DLL_EXPORT
#define API __declspec(dllexport)
#else 
#define API __declspec(dllimport)
#endif

API void ZhyPrint();
API int ZhyAdd(int a,int b);

#endif // !__ZHYLIB_H__
