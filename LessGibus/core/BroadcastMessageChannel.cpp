#include "stdafx.h"
#include "BroadcastMessageChannel.h"


BroadcastMessageChannel::BroadcastMessageChannel(void)
{
}


BroadcastMessageChannel::~BroadcastMessageChannel(void)
{
}

bool BroadcastMessageChannel::publish(const Message &msg) {
	std::vector<MessageSubscriber *>::iterator subscriber_iterator;

	for (subscriber_iterator = subscribers.begin();
			subscriber_iterator != subscribers.end();
			subscriber_iterator++)
	{
		(**subscriber_iterator).handle(msg);
	}

	return true;
}

bool BroadcastMessageChannel::registerSubscriber(MessageSubscriber *sub_ptr) {
	std::vector<MessageSubscriber *>::const_iterator i;
	for (
		i = subscribers.begin();
		i != subscribers.end();
		i++
	) {
		if (*i == sub_ptr) {
			// can't register the same subscriber multiple times
			throw BadArgumentException("Tried to register subscriber, but it was already registered!");
		}
		
	}
	// okay, it wasn't in there, add it
	subscribers.push_back(sub_ptr);
	return true;
}
bool BroadcastMessageChannel::deregisterSubscriber(MessageSubscriber *sub_ptr) {
	std::vector<MessageSubscriber *>::const_iterator i;
	
	for (
		i = subscribers.begin();
		i != subscribers.end();
		i++
	) {
		if (*i == sub_ptr) {
			subscribers.erase(i);
		}		
	}
	return true;
}
