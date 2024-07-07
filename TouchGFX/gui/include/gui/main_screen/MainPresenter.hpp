#ifndef MAINPRESENTER_HPP
#define MAINPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MainView;

class MainPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MainPresenter(MainView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~MainPresenter() {}

    virtual void set_new_value(int new_value);
    virtual void set_basicinfo(DASHBOARD_BASICINFO basicinfo);

private:
    MainPresenter();

    MainView& view;
};

#endif // MAINPRESENTER_HPP
