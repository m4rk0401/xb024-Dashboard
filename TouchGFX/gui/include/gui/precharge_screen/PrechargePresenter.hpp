#ifndef PRECHARGEPRESENTER_HPP
#define PRECHARGEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class PrechargeView;

class PrechargePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    PrechargePresenter(PrechargeView& v);

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

    virtual ~PrechargePresenter() {}

private:
    PrechargePresenter();

    PrechargeView& view;
};

#endif // PRECHARGEPRESENTER_HPP
