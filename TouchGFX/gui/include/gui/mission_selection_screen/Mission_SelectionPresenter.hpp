#ifndef MISSION_SELECTIONPRESENTER_HPP
#define MISSION_SELECTIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Mission_SelectionView;

class Mission_SelectionPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Mission_SelectionPresenter(Mission_SelectionView& v);

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

    virtual ~Mission_SelectionPresenter() {}

    virtual void set_current_screen(Model::Screen screen_idx);

private:
    Mission_SelectionPresenter();

    Mission_SelectionView& view;
};

#endif // MISSION_SELECTIONPRESENTER_HPP
