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

    virtual void set_menu_item(Model::Screen menu_item);
protected:

private:
};

#endif // MAINVIEW_HPP
