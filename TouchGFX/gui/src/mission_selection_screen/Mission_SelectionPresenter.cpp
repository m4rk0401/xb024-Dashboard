#include <gui/mission_selection_screen/Mission_SelectionView.hpp>
#include <gui/mission_selection_screen/Mission_SelectionPresenter.hpp>

Mission_SelectionPresenter::Mission_SelectionPresenter(Mission_SelectionView& v)
    : view(v)
{

}

void Mission_SelectionPresenter::activate()
{

}

void Mission_SelectionPresenter::deactivate()
{

}

void Mission_SelectionPresenter::set_current_screen(Model::Screen screen_idx)
{
	model->set_current_screen(screen_idx);
}
