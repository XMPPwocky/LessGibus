#pragma once

#include "Message.h"
#include "MessageSubscriber.h"
#include <memory>
using std::shared_ptr;

class  MessageChannel
{
public:
	MessageChannel(void);
	virtual ~MessageChannel(void);

	virtual void publish(const Message &msg) =0;
	virtual void registerSubscriber(shared_ptr<MessageSubscriber> sub) =0;
	virtual void deregisterSubscriber(shared_ptr<MessageSubscriber> sub) =0;
};

