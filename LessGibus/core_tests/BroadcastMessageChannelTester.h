#pragma once
#include "tester.h"
#include <memory>
#include "../core/BroadcastMessageChannel.h"

using std::shared_ptr;

class BroadcastMessageChannelTester :
	public Tester
{
public:
	BroadcastMessageChannelTester(void);
	virtual ~BroadcastMessageChannelTester(void);
	void test(void);
	std::wstring getTestName() const;
};

