#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include <cmsis_os2.h>

extern "C"
{
	extern osMessageQueueId_t test_queueHandle;
	extern osMessageQueueId_t basicinfo_queue_handle;
}
#endif

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	#ifndef SIMULATOR
	static int tmp;
	// if the message is read successfully
	if(osMessageQueueGet(test_queueHandle, &tmp, 0, 0) == osOK)
	{
		modelListener->set_new_value(tmp);
	}

	static DASHBOARD_BASICINFO basicinfo_struct;

	if(osMessageQueueGet(basicinfo_queue_handle, &basicinfo_struct, 0, 0) == osOK)
	{
		modelListener->set_basicinfo(basicinfo_struct);
	}
	#endif
}
