#include "stdafx.h"
#include "BroadcastMessageChannel.h"


BroadcastMessageChannel::BroadcastMessageChannel(void)
{
}


BroadcastMessageChannel::~BroadcastMessageChannel(void)
{
}

bool BroadcastMessageChannel::publish(const Message &msg) {
	std::set<MessageSubscriber *>::iterator subscriber_iterator;

	for (subscriber_iterator = subscribers.begin();
			subscriber_iterator != subscribers.end();
			subscriber_iterator++)
	{
		(**subscriber_iterator).handle(msg);
	}

	return true;
}

bool BroadcastMessageChannel::registerSubscriber(MessageSubscriber *sub) {
	subscribers.insert(sub);
	return true;
}

bool BroadcastMessageChannel::deregisterSubscriber(MessageSubscriber *sub) {
	subscribers.erase(sub);
	return true;
}