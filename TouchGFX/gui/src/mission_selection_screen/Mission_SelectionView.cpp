#include <gui/mission_selection_screen/Mission_SelectionView.hpp>

Mission_SelectionView::Mission_SelectionView() : selected_menu_item(MISSION), selected_mission(SKIDPAD)
{

}

void Mission_SelectionView::setupScreen()
{
    Mission_SelectionViewBase::setupScreen();

    presenter->set_current_screen(Model::MISSION);

    // Menu bar
    main_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	mission_box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	params_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	dv_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));

	main_box.invalidate();
	mission_box.invalidate();
	params_box.invalidate();
	dv_box.invalidate();

	// Mission selection
	set_mission_item(selected_mission);

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
		prev_mission();
	} else if(button_event == 1)
	{
		next_mission();
	} else if(button_event == 0)
	{
		presenter->request_mission((uint8_t)selected_mission);
	}

	return;

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

void Mission_SelectionView::next_mission(void)
{
	// Increase mission for next
	selected_mission = (Mission) (selected_mission + 1);

	// Reset back to first mission
	if(selected_mission > 13) selected_mission = (Mission) 1;

	set_mission_item(selected_mission);
}

void Mission_SelectionView::prev_mission(void)
{
	// Decrease mission for next
	selected_mission = (Mission) (selected_mission - 1);

	// Set to last mission
	if(selected_mission < 1) selected_mission = (Mission) 13;

	set_mission_item(selected_mission);
}

void Mission_SelectionView::set_mission_item(Mission mission_idx)
{
	// Reset all boxes
	skidpad_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	accel_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	autox_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	endu_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	base_mode_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	dv_track_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	dv_accel_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	dv_skidpad_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	dv_autox_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	dv_ebs_test_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	brake_test_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	ev_scruti_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	dv_insp_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

	skidpad_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	accel_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	autox_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	endu_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	base_mode_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	dv_track_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	dv_accel_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	dv_skidpad_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	dv_autox_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	dv_ebs_test_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	brake_test_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	ev_scruti_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	dv_insp_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

	switch(mission_idx)
	{
	case SKIDPAD:
		skidpad_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		skidpad_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case ACCEL:
		accel_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		accel_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case AUTOX:
		autox_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		autox_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case ENDU:
		endu_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		endu_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case BASEMODE:
		base_mode_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		base_mode_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case DV_TRACKDRIVE:
		dv_track_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		dv_track_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case DV_ACCEL:
		dv_accel_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		dv_accel_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case DV_SKIDPAD:
		dv_skidpad_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		dv_skidpad_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case DV_AUTOX:
		dv_autox_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		dv_autox_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case DV_EBSTEST:
		dv_ebs_test_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		dv_ebs_test_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case BRAKETEST:
		brake_test_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		brake_test_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case EV_SCRUTI:
		ev_scruti_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		ev_scruti_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case DV_INSPECTION:
		dv_insp_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
		dv_insp_label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	default:
		break;
	}

	skidpad_box.invalidate();
	skidpad_label.invalidate();

	accel_box.invalidate();
	accel_label.invalidate();

	autox_box.invalidate();
	autox_label.invalidate();

	endu_box.invalidate();
	endu_label.invalidate();

	base_mode_box.invalidate();
	base_mode_label.invalidate();

	dv_track_box.invalidate();
	dv_track_label.invalidate();

	dv_accel_box.invalidate();
	dv_accel_label.invalidate();

	dv_skidpad_box.invalidate();
	dv_skidpad_label.invalidate();

	dv_autox_box.invalidate();
	dv_autox_label.invalidate();

	dv_ebs_test_box.invalidate();
	dv_ebs_test_label.invalidate();

	brake_test_box.invalidate();
	brake_test_label.invalidate();

	ev_scruti_box.invalidate();
	ev_scruti_label.invalidate();

	dv_insp_box.invalidate();
	dv_insp_label.invalidate();
}

void Mission_SelectionView::confirm_mission(void)
{
	goToMainScreen();
}
