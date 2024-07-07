#include <gui/mission_selection_screen/Mission_SelectionView.hpp>

Mission_SelectionView::Mission_SelectionView()
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
