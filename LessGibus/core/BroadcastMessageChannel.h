#pragma once
#include "messagechannel.h"
#include "BadArgumentException.h"
#include <vector>
#include <memory>

using std::shared_ptr;

class BroadcastMessageChannel :
	public MessageChannel
{
	std::vector<MessageSubscriber *> subscribers;
public:
	BroadcastMessageChannel(void);
	virtual ~BroadcastMessageChannel(void);

	virtual bool publish(const Message& msg);
	virtual bool registerSubscriber(MessageSubscriber *sub_ptr);
	virtual bool deregisterSubscriber(MessageSubscriber *sub_ptr);
};

