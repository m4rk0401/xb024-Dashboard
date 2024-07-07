#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    enum Screen {
    	MAIN,
		MISSION,
		PARAMS,
		DV,
    };

    void set_current_screen(Screen screen_idx);

protected:
    ModelListener* modelListener;

private:
    Screen current_screen;
};

#endif // MODEL_HPP
