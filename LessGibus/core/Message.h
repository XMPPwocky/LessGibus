#pragma once

typedef enum
{
	MSGTYPE_CONSOLEOUTPUT,
	MSGTYPE_CONSOLEINPUT
} msgtype_t;

class Message
{
public:
	Message(void);

	virtual ~Message(void);
	virtual msgtype_t getType(void) =0;
};