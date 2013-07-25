#pragma once
#include <memory>

#include "Message.h"

class  MessageSubscriber
{
public:
	MessageSubscriber(void);
	virtual ~MessageSubscriber(void);
	
	virtual bool handle(const Message &msg) =0;
};
 