#include "stdafx.h"
#include "BroadcastMessageChannelTester.h"


BroadcastMessageChannelTester::BroadcastMessageChannelTester(void)
{
}


BroadcastMessageChannelTester::~BroadcastMessageChannelTester(void)
{
}

void BroadcastMessageChannelTester::test(void)
{
	shared_ptr<BroadcastMessageChannel> channel_ptr(new BroadcastMessageChannel);
	BroadcastMessageChannel channel = *channel_ptr;


}

std::wstring BroadcastMessageChannelTester::getTestName(void) const {
	return L"BroadcastMessageChannel";
}