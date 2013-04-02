/*
 BEPluginUtilities.h
 BaseElements Plug-In
	
 Copyright 2010-2012 Goya. All rights reserved.
 For conditions of distribution and use please see the copyright notice in BEPlugin.cpp
 
 http://www.goya.com.au/baseelements/plugin

 */


#if !defined(BEPLUGINUTILITIES_H)
	#define BEPLUGINUTILITIES_H


#include "BEPluginGlobalDefines.h"


#include <vector>
#include <stdint.h>


typedef std::auto_ptr<std::string> StringAutoPtr;
typedef std::auto_ptr<std::wstring> WStringAutoPtr;


fmx::errcode TextConstantFunction ( std::wstring text, fmx::Data& results );
fmx::errcode TextConstantFunction ( WStringAutoPtr text, fmx::Data& results );

void SetResult ( const intmax_t number, fmx::Data& results );
void SetResultAsDouble ( const double number, fmx::Data& results );
void SetResult ( const fmx::Text& text, fmx::Data& results );
void SetResult ( const std::string text, fmx::Data& results );
void SetResult ( const StringAutoPtr text, fmx::Data& results );
void SetResult ( const WStringAutoPtr text, fmx::Data& results );
void SetResult ( std::vector<char> data, fmx::Data& results );
void SetResult ( const std::string filename, const std::vector<char> data, fmx::Data& results );

bool ParameterAsBoolean ( const fmx::DataVect& parameters, const FMX_UInt32 which, const bool default_value = true );
long ParameterAsLong ( const fmx::DataVect& parameters, const FMX_UInt32 which, const unsigned long default_value );
StringAutoPtr ParameterAsUTF8String ( const fmx::DataVect& parameters, FMX_UInt32 which );
WStringAutoPtr ParameterAsWideString ( const fmx::DataVect& parameters, FMX_UInt32 which );

StringAutoPtr ReadFileAsUTF8 ( WStringAutoPtr path );
std::vector<char> ConvertTextTo ( char * in, const size_t length, const std::string& encoding );
StringAutoPtr ConvertTextTo ( StringAutoPtr in, const std::string& encoding );
StringAutoPtr ConvertTextToUTF8 ( char * in, const size_t length );

void SetTextEncoding ( const std::string& encoding );

fmx::errcode NoError ( void );
fmx::errcode MapError ( const fmx::errcode error = kNoError, const bool map = false );


bool AllowUserAbort ( const fmx::ExprEnv& environment );

// extract localised strings from the plug-in resources

void Do_GetString ( unsigned long whichString, FMX_PtrType winLangID, FMX_PtrType resultsize, FMX_Unichar* string );
void Do_GetString ( unsigned long whichString,  fmx::TextAutoPtr& intoHere, bool stripFunctionParams = false );

// used by Do_GetString
#if defined(FMX_MAC_TARGET)
	unsigned long  Sub_OSXLoadString ( unsigned long stringID, FMX_Unichar* intoHere, long intoHereMax );
#endif


#endif // BEPLUGINUTILITIES_H
