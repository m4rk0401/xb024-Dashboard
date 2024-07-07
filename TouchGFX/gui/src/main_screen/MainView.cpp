#include <gui/main_screen/MainView.hpp>
#include <touchgfx/Color.hpp>

MainView::MainView()
{

}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();

    presenter->set_current_screen(Model::MAIN);

    main_box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	mission_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	params_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	dv_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));

	main_box.invalidate();
	mission_box.invalidate();
	params_box.invalidate();
	dv_box.invalidate();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::set_new_value(int new_value)
{
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", new_value);
	textArea1.invalidate();
}

void MainView::set_basicinfo(DASHBOARD_BASICINFO basicinfo)
{
	// TEXT: SOC
	Unicode::snprintf(soc_valBuffer, SOC_VAL_SIZE, "%d", basicinfo.soc_val);

	if(basicinfo.soc_val > 40)
	{
		soc_val.setColor(Color::getColorFromRGB(0x00, 0xFF, 0x00));
	} else if(basicinfo.soc_val > 20 && basicinfo.soc_val <= 40)
	{
		soc_val.setColor(Color::getColorFromRGB(0xFF, 0xCD, 0x00));
	}
	else
	{
		soc_val.setColor(Color::getColorFromRGB(0xFF, 0x00, 0x00));
	}

	Unicode::UnicodeChar buffer1[12];
	// Subtract 1 because can message starts counting at 1
	Unicode::strncpy(buffer1, basicinfo.mission_text, 12);
	Unicode::snprintf(mission_valBuffer, MISSION_VAL_SIZE, "%s", buffer1);

	// SDC value
	Unicode::UnicodeChar buffer2[12];
	Unicode::strncpy(buffer2, basicinfo.sdc_text, 12);	// Subtract 1 because can message starts counting at 1
	Unicode::snprintf(sdc_valBuffer, SDC_VAL_SIZE, "%s", buffer2);

	if(basicinfo.sdc_val == 1)
	{
		sdc_lightPainter.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		sdc_light_borderPainter.setColor(touchgfx::Color::getColorFromRGB(156, 0, 0));
	}
	else
	{
		sdc_lightPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		sdc_light_borderPainter.setColor(touchgfx::Color::getColorFromRGB(156, 156, 156));
	}

	sdc_light.setPainter(sdc_lightPainter);
	sdc_light_border.setPainter(sdc_light_borderPainter);

	soc_val.invalidate();
	mission_val.invalidate();
	sdc_val.invalidate();

	sdc_light.invalidate();
	sdc_light_border.invalidate();

}

void MainView::set_menu_item(Model::Screen menu_item)
{
	// Reset all
	main_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	mission_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	params_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));
	dv_box.setColor(touchgfx::Color::getColorFromRGB(255, 104, 1));

	switch(menu_item)
	{
	case Model::Screen::MAIN:
		main_box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case Model::Screen::MISSION:
		mission_box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case Model::Screen::PARAMS:
		params_box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	case Model::Screen::DV:
		dv_box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
		break;
	default:
		break;
	}

	main_box.invalidate();
	mission_box.invalidate();
	params_box.invalidate();
	dv_box.invalidate();
}
