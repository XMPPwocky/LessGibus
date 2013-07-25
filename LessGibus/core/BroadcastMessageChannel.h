#pragma once
#include "messagechannel.h"
#include <set>
#include <memory>

using std::unique_ptr;

class BroadcastMessageChannel :
	public MessageChannel
{
	std::set<MessageSubscriber *> subscribers;
public:
	BroadcastMessageChannel(void);
	virtual ~BroadcastMessageChannel(void);

	virtual bool publish(const Message& msg);
	virtual bool registerSubscriber(MessageSubscriber *sub);
	virtual bool deregisterSubscriber(MessageSubscriber *sub);
};

