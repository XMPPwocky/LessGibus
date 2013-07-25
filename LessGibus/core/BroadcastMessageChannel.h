#pragma once
#include "messagechannel.h"
#include "BadArgumentException.h"
#include <vector>
#include <memory>

using std::shared_ptr;

class BroadcastMessageChannel :
	public MessageChannel
{
		std::vector<shared_ptr<MessageSubscriber>> subscribers;

public:
	BroadcastMessageChannel(void);
	virtual ~BroadcastMessageChannel(void);

	virtual void publish(const Message& msg);
	virtual void registerSubscriber(shared_ptr<MessageSubscriber> sub);
	virtual void deregisterSubscriber(shared_ptr<MessageSubscriber> sub);
};

