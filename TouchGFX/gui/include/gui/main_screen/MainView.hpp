#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void set_new_value(int new_value);
    virtual void set_basicinfo(DASHBOARD_BASICINFO basicinfo);

    virtual void button_action(int8_t button_event);
protected:

private:
    enum MenuBar
	{
		MAIN,
		MISSION,
		PARAMS,
		DV
	} selected_menu_item;

	void set_menu_item(MenuBar menu_item);
};

#endif // MAINVIEW_HPP
