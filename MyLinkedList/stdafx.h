// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <stdlib.h>
#include <string.h>
#include <time.h>


#ifndef _STRING_DEFAULT
#define _STRING_DEFAULT "00000000"
#endif // !_STRING_DEFAULT



#ifndef _INDEX_MAX
#define _INDEX_MAX 256
#endif // !_INDEX_MAX


#ifdef _INDEX_MAX

// student(sno, sname, sex, age, nation)
typedef struct _unnamed_struct_0001_1
{
	int	sno;
	char sname[_INDEX_MAX];
	char sex;
	int age;
	char nation[_INDEX_MAX];
} student;

// class_s(cno, cname,credit)
typedef struct _unnamed_struct_0001_2
{
	int cno;
	char cname[_INDEX_MAX];
	double credit;
} class_s;

// grade_s(sno, cno, grade)
typedef struct _unnamed_struct_0001_3
{
	int sno;
	int cno;
	double grade;
} grade_s;

#endif // _INDEX_MAX


// Nodes containing student, class_s, grade
typedef class _unnamed_class_0001_1
{
public:
	student *sinfo;
	class_s *cinfo;
	grade_s *ginfo;
	class _unnamed_class_0001_1 *back;
	class _unnamed_class_0001_1 *next;
} node;



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Random Default Values
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#ifndef _SNO_MAX
#define _SNO_MAX 1000
#endif // !_SNO_MAX


#ifndef _SNAME_DEFAULT
#define	_SNAME_DEFAULT "Default"
#ifndef _NATION_DEFAULT
#ifdef _SNAME_DEFAULT
#define _NATION_DEFAULT _SNAME_DEFAULT
#ifndef _CNAME_DEFAULT
#if defined _NATION_DEFAULT && defined _SNAME_DEFAULT
#define _CNAME_DEFAULT _NATION_DEFAULT
#endif
#endif // !_CNAME_DEFAULT
#endif // _SNAME_DEFAULT
#endif // !_NATION_DEFAULT
#endif // !_SNAME_DEFAULT


#ifndef _SEX_OPTION
#define _SEX_OPTION 2
#ifndef _SEX_STEP
#ifdef _SEX_OPTION
#define _SEX_STEP 7
#endif // _SEX_OPTION
#endif // !_SEX_STEP
#endif // !_SEX_OPTION


#ifndef _AGE_MAX
#define _AGE_MAX 100
#endif // !_AGE_MAX


#ifndef _CNO_MAX
#define _CNO_MAX 1000
#endif // !_CNO_MAX


#ifndef _CREDIT_MAX
#define _CREDIT_MAX 100
#endif // !_CREDIT_MAX


#ifndef _GRADE_MAX
#define _GRADE_MAX 100
#endif // !_GRADE_MAX


#ifndef _DEFAULT_RANDOM
#if defined _SNO_MAX && defined _CNO_MAX
#if defined _AGE_MAX && defined _CREDIT_MAX && defined _GRADE_MAX
#if defined _SNAME_DEFAULT && defined _NATION_DEFAULT && defined _CNAME_DEFAULT
#if defined _SEX_OPTION && defined _SEX_STEP
#define _DEFAULT_RANDOM(_DEFAULT_OPTION, _DEFAULT_STEP, _DEFAULT_OFFSET) (rand() % (_DEFAULT_OPTION) * (_DEFAULT_STEP) + (_DEFAULT_OFFSET)) 
#endif
#endif
#endif
#endif
#endif // !_DEFAULT_RANDOM(_DEFAULT_OPTION, _DEFAULT_STEP)


#ifdef _DEFAULT_RANDOM
#ifndef _STEP_DEFAULT
#define _STEP_DEFAULT 1
#ifndef _OFFSET_DEFAULT
#ifdef _STEP_DEFAULT
#define _OFFSET_DEFAULT 0
#endif // _STEP_DEFAULT
#endif // !_OFFSET_DEFAULT
#endif // !_STEP_DEFAULT
#endif // _DEFAULT_RANDOM(_DEFAULT_OPTION, _DEFAULT_STEP, _DEFAULT_OFFSET)



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Error Codes
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#ifndef ERROR_ILLEGAL_PARAMETERS
#define ERROR_ILLEGAL_PARAMETERS 87
#endif // !ERROR_ILLEGAL_PARAMETERS


#ifndef ERROR_USER_DISCARDS
#define ERROR_USER_DISCARDS 88
#endif // !ERROR_USER_DISCARDS


#ifndef ERROR_SNO_CNO_NOT_FOUND
#define ERROR_SNO_CNO_NOT_FOUND 89
#endif // !ERROR_SNO_CNO_NOT_FOUND



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Submenu Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
node * __cdecl InputStudent(
	_Inout_   node *phead,
	_In_      char confirm
);

node * __cdecl InputClass_s(
	_Inout_   node *phead,
	_In_      char confirm
);

node * __cdecl InputGrade_s(
	_Inout_   node *phead,
	_In_      char confirm
);

size_t __cdecl InquireNumber(
	_In_ node *phead
);

double __cdecl InquireGrade_s(
	_In_ node *phead,
	_In_ int sno,
	_In_ int cno
);

int * __cdecl InquireMinority(
	_In_    node *phead,
	_Inout_ node *Mphead,
	_Inout_ int *count
);

int * __cdecl InquireFail(
	_In_    node *phead,
	_Inout_ int *sno,
	_In_    int cno
);

double __cdecl ModifyGrade_s(
	_Inout_ node *phead,
	_In_    int sno,
	_In_    int cno,
	_In_    double grade
);

node * __cdecl DeleteStudent(
	_Inout_ node *phead,
	_In_    node *ptail,
	_In_    int sno
);

node * __cdecl DeleteClass_s(
	_Inout_ node *phead,
	_In_    node *ptail,
	_In_    int cno
);



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Default Values Assignment Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
node * __cdecl SAssign(
	_Inout_ node *current,
	_In_    int sno,
	_In_z_  char *sname,
	_In_    char sex,
	_In_    int age,
	_In_z_  char *nation
);

node * __cdecl CAssign(
	_Inout_ node *current,
	_In_    int cno,
	_In_z_  char *cname,
	_In_    double credit
);

node * __cdecl GAssign(
	_Inout_ node *current,
	_In_    int sno,
	_In_    int cno,
	_In_    double grade
);



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Optimization Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
node * __cdecl FreeAll(
	_In_ node *phead
);

char * __cdecl Alignment(
	_Out_writes_z_(_String_length_(sour) + 1) char *dest,
	_In_z_									  char *sour
);


