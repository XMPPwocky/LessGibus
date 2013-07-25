#pragma once
#include "messagechannel.h"
#include <set>
#include <memory>

using std::shared_ptr;

class BroadcastMessageChannel :
	public MessageChannel
{
	std::set<shared_ptr<MessageSubscriber>> subscribers;
public:
	BroadcastMessageChannel(void);
	virtual ~BroadcastMessageChannel(void);

	virtual bool publish(const Message& msg);
	virtual bool registerSubscriber(shared_ptr<MessageSubscriber> sub);
	virtual bool deregisterSubscriber(shared_ptr<MessageSubscriber> sub);
};

