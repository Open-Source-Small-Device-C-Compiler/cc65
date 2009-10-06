/*****************************************************************************/
/*									     */
/*				   version.c				     */
/*									     */
/*	       Version information for the cc65 compiler package	     */
/*									     */
/*									     */
/*									     */
/* (C) 1998-2009, Ullrich von Bassewitz                                      */
/*                Roemerstrasse 52                                           */
/*                D-70794 Filderstadt                                        */
/* EMail:         uz@cc65.org                                                */
/*									     */
/*									     */
/* This software is provided 'as-is', without any expressed or implied	     */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.		     		     */
/*									     */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:			     */
/*									     */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.					     */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.			     */
/* 3. This notice may not be removed or altered from any source		     */
/*    distribution.							     */
/*							     		     */
/*****************************************************************************/



#include "version.h"
#include "xsprintf.h"



/*****************************************************************************/
/*				     Data		     		     */
/*****************************************************************************/



#define VER_MAJOR	2U
#define VER_MINOR      	13U
#define VER_PATCH       9U
#define VER_RC          0U




/*****************************************************************************/
/*                                   Code                                    */
/*****************************************************************************/



const char* GetVersionAsString (void)
/* Returns the version number as a string in a static buffer */
{
    static char Buf[20];
#if defined(VER_RC) && (VER_RC > 0U)
    xsnprintf (Buf, sizeof (Buf), "%u.%u.%u-rc%u", VER_MAJOR, VER_MINOR, VER_PATCH, VER_RC);
#else
    xsnprintf (Buf, sizeof (Buf), "%u.%u.%u", VER_MAJOR, VER_MINOR, VER_PATCH);
#endif
    return Buf;
}



unsigned GetVersionAsNumber (void)
/* Returns the version number as a combined unsigned for use in a #define */
{
    return ((VER_MAJOR * 0x100) + (VER_MINOR * 0x10) + VER_PATCH);
}



