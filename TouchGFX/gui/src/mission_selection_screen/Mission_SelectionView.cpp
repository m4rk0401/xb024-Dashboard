#include <gui/mission_selection_screen/Mission_SelectionView.hpp>

Mission_SelectionView::Mission_SelectionView() : selected_menu_item(MISSION)
{

}

void Mission_SelectionView::setupScreen()
{
    Mission_SelectionViewBase::setupScreen();

    presenter->set_current_screen(Model::MISSION);

    main_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	mission_box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	params_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	dv_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));

	main_box.invalidate();
	mission_box.invalidate();
	params_box.invalidate();
	dv_box.invalidate();
}

void Mission_SelectionView::tearDownScreen()
{
    Mission_SelectionViewBase::tearDownScreen();
}

void Mission_SelectionView::button_action(int8_t button_event)
{
	/* -1 = button left
	 * 0 = button select
	 * 1 = button right
	 */

	if(button_event == -1)
	{
		switch(selected_menu_item)
		{
		case MAIN:
			selected_menu_item = DV;
			break;
		case MISSION:
			selected_menu_item = MAIN;
			break;
		case PARAMS:
			selected_menu_item = MISSION;
			break;
		case DV:
			selected_menu_item = PARAMS;
			break;
		default:
			break;
		}

		set_menu_item(selected_menu_item);
	} else if(button_event == 1) {
		switch(selected_menu_item)
		{
		case MAIN:
			selected_menu_item = MISSION;
			break;
		case MISSION:
			selected_menu_item = PARAMS;
			break;
		case PARAMS:
			selected_menu_item = DV;
			break;
		case DV:
			selected_menu_item = MAIN;
			break;
		default:
			break;
		}

		set_menu_item(selected_menu_item);
	} else if(button_event == 0) {
		switch(selected_menu_item)
		{
		case MAIN:
			goToMainScreen();
			break;
		case MISSION:
			// TODO: do something in screen
			break;
		case PARAMS:
			// TODO: add switch screen
			break;
		case DV:
			// TODO: add switch screen
			break;
		default:
			break;
		}
	}
}

void Mission_SelectionView::set_menu_item(MenuBar menu_item)
{
	// Reset all
	main_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	mission_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	params_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	dv_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));

	switch(menu_item)
	{
	case MAIN:
		main_box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case MISSION:
		mission_box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case PARAMS:
		params_box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case DV:
		dv_box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	default:
		break;
	}

	main_box.invalidate();
	mission_box.invalidate();
	params_box.invalidate();
	dv_box.invalidate();
}
