#ifndef COMENT_MANAGER_H
#define COMENT_MANAGER_H

namespace coment
{
	class World;

	class Manager
	{
	public:
		// Constructors
		Manager();

		// Initialise this manager
		virtual void initialise(World* world);

		// Indicates that this manager has been registered with the world
		virtual void onRegistered();

		// Get whether or not we are already initialised
		bool getInitialised();

	protected:
		// Friends
		friend class ManagerManager;

		// The parent world.
		World* _world;

	private:
		// Whether or not we are initialized.
		bool _initialised;
	};
}

#endif /* COMENT_MANAGER_H */
