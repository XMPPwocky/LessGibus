#pragma once
#include <coment\managers\manager.h>

#include <map>

class SignalManager :
	public coment::Manager
{
protected:
	typedef std::map<const std::string, boost::any> SignalMap;
	typedef std::map<decltype(typeid(void).name()), SignalMap> SignalTypeMap;

private:
	SignalTypeMap _signals;

protected:
	friend class coment::ManagerManager;
	void onRegistered();

public:
	SignalManager(void);
	~SignalManager(void);
	
	template <typename Signature>
	std::shared_ptr<boost::signals2::signal<Signature>> mutable_signal(const std::string &signal_name)
	{
		SignalMap &signal_map = _signals[typeid(Signature).name()];
		if (signal_map.find(signal_name) != signal_map.end()) // if we already have this signal...
			return boost::any_cast<std::shared_ptr<boost::signals2::signal<Signature>>>(_signals[typeid(Signature).name()][signal_name]); // return it

		// otherwise make a new one
		boost::signals2::signal<Signature> *sig_rawptr = new boost::signals2::signal<Signature>;
		std::shared_ptr<boost::signals2::signal<Signature>> sig_ptr = std::shared_ptr<boost::signals2::signal<Signature>>(sig_rawptr);
		signal_map[signal_name] = boost::any(sig_ptr);
		return sig_ptr;
	}

	template <typename Signature>
	std::shared_ptr<const boost::signals2::signal<Signature>> signal(const std::string &signal_name)
	{
		return mutable_signal<Signature>(signal_name); // implicit cast
	}

};

