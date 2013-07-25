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

	virtual bool publish(const Message& msg);
	virtual bool registerSubscriber(shared_ptr<MessageSubscriber> sub);
	virtual bool deregisterSubscriber(shared_ptr<MessageSubscriber> sub);
};

