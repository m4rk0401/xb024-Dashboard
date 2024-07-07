#ifndef PRECHARGEVIEW_HPP
#define PRECHARGEVIEW_HPP

#include <gui_generated/precharge_screen/PrechargeViewBase.hpp>
#include <gui/precharge_screen/PrechargePresenter.hpp>

class PrechargeView : public PrechargeViewBase
{
public:
    PrechargeView();
    virtual ~PrechargeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PRECHARGEVIEW_HPP
