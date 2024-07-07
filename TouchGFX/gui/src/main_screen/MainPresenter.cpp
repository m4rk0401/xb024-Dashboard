#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{

}

void MainPresenter::activate()
{

}

void MainPresenter::deactivate()
{

}

void MainPresenter::set_current_screen(Model::Screen screen_idx)
{
	model->set_current_screen(screen_idx);
}

void MainPresenter::set_new_value(int new_value)
{
	view.set_new_value(new_value);
}

void MainPresenter::set_basicinfo(DASHBOARD_BASICINFO basicinfo)
{
	view.set_basicinfo(basicinfo);
}

void MainPresenter::set_menu_item(Model::Screen menu_item)
{
	view.set_menu_item(menu_item);
}
