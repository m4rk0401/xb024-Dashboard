#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include <cmsis_os2.h>

extern "C"
{
	extern osMessageQueueId_t test_queueHandle;
	extern osMessageQueueId_t basicinfo_queue_handle;
	extern osMessageQueueId_t menuselect_queue_handle;
}
#endif

Model::Model() : modelListener(0), current_screen(MAIN), menu_selection_item(MAIN)
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

	static int8_t menu_direction;
	if(osMessageQueueGet(menuselect_queue_handle, &menu_direction, 0, 0) == osOK)
	{
		// Iterate left
		if(menu_direction == -1)
		{
			switch(menu_selection_item)
			{
			case MAIN:
				menu_selection_item = DV;
				break;
			case MISSION:
				menu_selection_item = MAIN;
				break;
			case PARAMS:
				menu_selection_item = MISSION;
				break;
			case DV:
				menu_selection_item = PARAMS;
				break;
			default:
				break;
			}
		// Iterate right
		} else if(menu_direction == 1)
		{
			switch(menu_selection_item)
			{
			case MAIN:
				menu_selection_item = MISSION;
				break;
			case MISSION:
				menu_selection_item = PARAMS;
				break;
			case PARAMS:
				menu_selection_item = DV;
				break;
			case DV:
				menu_selection_item = MAIN;
				break;
			default:
				break;
			}
		}
		modelListener->set_menu_item(menu_selection_item);
	}
	#endif
}

void Model::set_current_screen(Screen screen_idx)
{
	current_screen = screen_idx;
}
