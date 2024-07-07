#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

#ifndef SIMULATOR
#include "main.h"
#endif

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void set_current_screen(Model::Screen screen_idx) {}

    virtual void set_new_value(int new_value) {}
    virtual void set_basicinfo(DASHBOARD_BASICINFO basicinfo) {}

    virtual void set_menu_item(Model::Screen menu_item) {}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
