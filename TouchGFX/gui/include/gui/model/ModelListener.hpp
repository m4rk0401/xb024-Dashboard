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
    virtual void request_mission(uint8_t mission_idx) {}

    virtual void set_new_value(int new_value) {}
    virtual void set_basicinfo(DASHBOARD_BASICINFO basicinfo) {}

    virtual void button_action(int8_t button_event) {}
    virtual void confirm_mission(void) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
