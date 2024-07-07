#ifndef MISSION_SELECTIONVIEW_HPP
#define MISSION_SELECTIONVIEW_HPP

#include <gui_generated/mission_selection_screen/Mission_SelectionViewBase.hpp>
#include <gui/mission_selection_screen/Mission_SelectionPresenter.hpp>

class Mission_SelectionView : public Mission_SelectionViewBase
{
public:
    Mission_SelectionView();
    virtual ~Mission_SelectionView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void menu_left();
	virtual void menu_right();
protected:
};

#endif // MISSION_SELECTIONVIEW_HPP
