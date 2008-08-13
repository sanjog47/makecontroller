/*
	atestee.h

*/

#ifndef ATESTEE_H
#define ATESTEE_H

#ifdef FACTORY_TESTING

int ATestee_SetTest( int pattern );
int ATestee_GetTest( void );

int ATestee_GetTestResult( void );

/* OSC Interface */
const char* ATesteeOsc_GetName( void );
int ATesteeOsc_ReceiveMessage( int channel, char* message, int length );

#endif // FACTORY_TESTING

#endif
