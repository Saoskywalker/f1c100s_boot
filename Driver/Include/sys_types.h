#ifndef __ARM64_TYPES_H__
#define __ARM64_TYPES_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define __O volatile
#define __IO volatile

	typedef signed char s8_t;
	typedef unsigned char u8_t;

	typedef signed short s16_t;
	typedef unsigned short u16_t;

	typedef signed int s32_t;
	typedef unsigned int u32_t;

	typedef signed long long s64_t;
	typedef unsigned long long u64_t;

	typedef signed long long intmax_t;
	typedef unsigned long long uintmax_t;

	// typedef signed long	long		ptrdiff_t;
	// typedef signed long	long		intptr_t;
	// typedef unsigned long long		uintptr_t;

	typedef signed long off_t;
	typedef signed long long loff_t;

	typedef signed int bool_t;

	typedef signed long register_t;
	typedef unsigned long irq_flags_t;

	typedef unsigned long long virtual_addr_t;
	typedef unsigned long long virtual_size_t;
	typedef unsigned long long physical_addr_t;
	typedef unsigned long long physical_size_t;

	typedef void *PVOID; ///< Define void pointer data type
	typedef void VOID;	 ///< Define void data type
	typedef char BOOL;	 ///< Define bool data type
	typedef char *PBOOL; ///< Define bool pointer data type

	typedef char INT8;			   ///< Define 8-bit singed data type
	typedef char CHAR;			   ///< Define char data type
	typedef char *PINT8;		   ///< Define 8-bit singed pointer data type
	typedef char *PCHAR;		   ///< Define char pointer data type
	typedef unsigned char UINT8;   ///< Define 8-bit unsigned data type
	typedef unsigned char UCHAR;   ///< Define char unsigned data type
	typedef unsigned char *PUINT8; ///< Define 8-bit unsigned pointer data type
	typedef unsigned char *PUCHAR; ///< Define char unsigned pointer data type
	typedef char *PSTR;			   ///< Define string pointer data type
	typedef const char *PCSTR;	   ///< Define constant string pointer data type

	typedef short SHORT;			 ///< Define short signed data type
	typedef short *PSHORT;			 ///< Define short signed pointer data type
	typedef unsigned short USHORT;	 ///< Define short unsigned data type
	typedef unsigned short *PUSHORT; ///< Define short unsigned pointer data type

	typedef short INT16;			 ///< Define 16-bit signed data type
	typedef short *PINT16;			 ///< Define 16-bit signed pointer data type
	typedef unsigned short UINT16;	 ///< Define 16-bit unsigned data type
	typedef unsigned short *PUINT16; ///< Define 16-bit unsigned pointer data type

	typedef int INT;			 ///< Define integer signed data type
	typedef int *PINT;			 ///< Define integer signed pointer data type
	typedef unsigned int UINT;	 ///< Define integer unsigned data type
	typedef unsigned int *PUINT; ///< Define integer unsigned pointer data type

	typedef int INT32;			   ///< Define 32-bit signed data type
	typedef int *PINT32;		   ///< Define 32-bit signed pointer data type
	typedef unsigned int UINT32;   ///< Define 32-bit unsigned data type
	typedef unsigned int *PUINT32; ///< Define 32-bit unsigned pointer data type

	typedef __int64 INT64;			 ///< Define 64-bit signed data type
	typedef unsigned __int64 UINT64; ///< Define 64-bit unsigned data type

	typedef float FLOAT;   ///< Define float data type
	typedef float *PFLOAT; ///< Define float pointer data type

	typedef double DOUBLE;	 ///< Define double data type
	typedef double *PDOUBLE; ///< Define double pointer data type

	typedef int SIZE_T; ///< Define size of data type

	typedef unsigned char REG8;	  ///< Define 8-bit register data type
	typedef unsigned short REG16; ///< Define 16-bit register data type
	typedef unsigned int REG32;	  ///< Define 32-bit register data type

	// add by qlqcect
	typedef volatile unsigned char u8;	 ///< Define 8-bit register data type
	typedef volatile unsigned short u16; ///< Define 16-bit register data type
	typedef volatile unsigned int u32;	 ///< Define 32-bit register data type

	typedef volatile char s8;	///< Define 8-bit register data type
	typedef volatile short s16; ///< Define 16-bit register data type
	typedef volatile int s32;	///< Define 32-bit register data type
	// end add

#ifndef NULL
#define NULL (0) ///< NULL pointer
#endif

#define TRUE (1)  ///< Boolean true, define to use in API parameters or return value
#define FALSE (0) ///< Boolean false, define to use in API parameters or return value

#define ENABLE (1)	///< Enable, define to use in API parameters
#define DISABLE (0) ///< Disable, define to use in API parameters

#define Successful 0 ///< Function return value success
#define Fail 1		 ///< Function return value failed

/* Define one bit mask */
#define BIT0 (0x00000001)  ///< Bit 0 mask of an 32 bit integer
#define BIT1 (0x00000002)  ///< Bit 1 mask of an 32 bit integer
#define BIT2 (0x00000004)  ///< Bit 2 mask of an 32 bit integer
#define BIT3 (0x00000008)  ///< Bit 3 mask of an 32 bit integer
#define BIT4 (0x00000010)  ///< Bit 4 mask of an 32 bit integer
#define BIT5 (0x00000020)  ///< Bit 5 mask of an 32 bit integer
#define BIT6 (0x00000040)  ///< Bit 6 mask of an 32 bit integer
#define BIT7 (0x00000080)  ///< Bit 7 mask of an 32 bit integer
#define BIT8 (0x00000100)  ///< Bit 8 mask of an 32 bit integer
#define BIT9 (0x00000200)  ///< Bit 9 mask of an 32 bit integer
#define BIT10 (0x00000400) ///< Bit 10 mask of an 32 bit integer
#define BIT11 (0x00000800) ///< Bit 11 mask of an 32 bit integer
#define BIT12 (0x00001000) ///< Bit 12 mask of an 32 bit integer
#define BIT13 (0x00002000) ///< Bit 13 mask of an 32 bit integer
#define BIT14 (0x00004000) ///< Bit 14 mask of an 32 bit integer
#define BIT15 (0x00008000) ///< Bit 15 mask of an 32 bit integer
#define BIT16 (0x00010000) ///< Bit 16 mask of an 32 bit integer
#define BIT17 (0x00020000) ///< Bit 17 mask of an 32 bit integer
#define BIT18 (0x00040000) ///< Bit 18 mask of an 32 bit integer
#define BIT19 (0x00080000) ///< Bit 19 mask of an 32 bit integer
#define BIT20 (0x00100000) ///< Bit 20 mask of an 32 bit integer
#define BIT21 (0x00200000) ///< Bit 21 mask of an 32 bit integer
#define BIT22 (0x00400000) ///< Bit 22 mask of an 32 bit integer
#define BIT23 (0x00800000) ///< Bit 23 mask of an 32 bit integer
#define BIT24 (0x01000000) ///< Bit 24 mask of an 32 bit integer
#define BIT25 (0x02000000) ///< Bit 25 mask of an 32 bit integer
#define BIT26 (0x04000000) ///< Bit 26 mask of an 32 bit integer
#define BIT27 (0x08000000) ///< Bit 27 mask of an 32 bit integer
#define BIT28 (0x10000000) ///< Bit 28 mask of an 32 bit integer
#define BIT29 (0x20000000) ///< Bit 29 mask of an 32 bit integer
#define BIT30 (0x40000000) ///< Bit 30 mask of an 32 bit integer
#define BIT31 (0x80000000) ///< Bit 31 mask of an 32 bit integer

	typedef struct
	{
		volatile long counter;
	} atomic_t;

	typedef struct
	{
		volatile long lock;
	} spinlock_t;

#ifdef __cplusplus
}
#endif

#endif /* __ARM64_TYPES_H__ */
