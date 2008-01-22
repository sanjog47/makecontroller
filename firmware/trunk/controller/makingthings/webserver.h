/*
	FreeRTOS V4.0.1 - copyright (C) 2003-2006 Richard Barry.

	This file is part of the FreeRTOS distribution.

	FreeRTOS is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	FreeRTOS is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with FreeRTOS; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

	A special exception to the GPL can be applied should you wish to distribute
	a combined work that includes FreeRTOS, without being obliged to provide
	the source code for any proprietary components.  See the licensing section
	of http://www.FreeRTOS.org for full details of how and when the exception
	can be applied.

	***************************************************************************
	See http://www.FreeRTOS.org for documentation, latest information, license
	and contact details.  Please ensure to read the configuration and relevant
	port sections of the online documentation.
	***************************************************************************
*/

#ifndef BASIC_WEB_SERVER_H
#define BASIC_WEB_SERVER_H

#define MAX_FORM_ELEMENTS 10

typedef struct
{
  char *key;
  char *value;
} HttpFormElement;

typedef struct
{
  HttpFormElement elements[MAX_FORM_ELEMENTS];
  int count;
} HttpForm;

// Web Server Task
int WebServer_SetActive( int active );
int WebServer_GetActive( void );

int WebServer_Route( char* address, int (*handler)( char* requestType, char* request, char* requestBuffer, int request_maxsize, void* socket, char* responseBuffer, int len )  );

// HTTP Helpers
int WebServer_WriteResponseOkHTML( void* socket );
int WebServer_WriteResponseOkPlain( void* socket );

// HTML Helpers
int WebServer_WriteHeader( int includeCSS, void* socket, char* buffer, int len );
int WebServer_WriteBodyStart( char* reloadAddress, void* socket, char* buffer, int len );
int WebServer_WriteBodyEnd( void* socket );

bool WebServer_GetPostData( void *socket, char *requestBuffer, int maxSize );
int WebServer_ParseFormElements( char *request, HttpForm *form );

#endif  // BASIC_WEB_SERVER_H

