#include "stdafx.h"
#include "BroadcastMessageChannel.h"


BroadcastMessageChannel::BroadcastMessageChannel(void)
{
}


BroadcastMessageChannel::~BroadcastMessageChannel(void)
{
}

void BroadcastMessageChannel::publish(const Message &msg) {
	std::vector<shared_ptr<MessageSubscriber>>::iterator subscriber_iterator;
	for (subscriber_iterator = subscribers.begin();
			subscriber_iterator != subscribers.end();
			subscriber_iterator++)
	{
		(**subscriber_iterator).handle(msg);
	}
}


void BroadcastMessageChannel::registerSubscriber(shared_ptr<MessageSubscriber> sub_ptr) {
	std::vector<shared_ptr<MessageSubscriber>>::const_iterator i;
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
}
void BroadcastMessageChannel::deregisterSubscriber(shared_ptr<MessageSubscriber> sub_ptr) {
	std::vector<shared_ptr<MessageSubscriber>>::const_iterator i;
	
	for (
		i = subscribers.begin();
		i != subscribers.end();
		i++
	) {
		if (*i == sub_ptr) {
			subscribers.erase(i);
		}		
	}
}
