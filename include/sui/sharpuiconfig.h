// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����sharpuiinc.h
// ��  �ܣ���������������ļ���Ϣ��
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _SHARPUICONFIG_H_
# define _SHARPUICONFIG_H_

#ifdef SHARPUI_EXPORTS
#define SHARPUI_API __declspec(dllexport)
#else
#define SHARPUI_API __declspec(dllimport)
#endif

#include <suicore/suicoreinc.h>

# endif