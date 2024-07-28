#ifndef __ZHYLIB_H__
#define __ZHYLIB_H__

#ifndef DLL_EXPORT
#define API __declspec(dllexport)
#else 
#define API __declspec(dllimport)
#endif

extern "C" API void ZhyPrint();

#endif // !__ZHYLIB_H__
