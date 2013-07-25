#pragma once

#include "Message.h"
#include "MessageSubscriber.h"

class  MessageChannel
{
public:
	MessageChannel(void);
	virtual ~MessageChannel(void);

	virtual bool publish(const Message &msg) =0;
	virtual bool registerSubscriber(MessageSubscriber *sub) =0;
	virtual bool deregisterSubscriber(MessageSubscriber *sub) =0;
};

