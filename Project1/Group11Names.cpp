#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#define ScreenWidth  800
#define ScreenHeight 600


int main(void)
{
	if (!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not initialise allegro 5", NULL, NULL);

		return -1;
	}

	al_set_new_display_flags(ALLEGRO_WINDOWED);
	ALLEGRO_DISPLAY *display = al_create_display(ScreenWidth, ScreenHeight);
	al_set_window_position(display, 200, 100);
	al_set_window_title(display, "display my name");

	if (!display)
	{
		al_show_native_message_box(display, "Sample Title", "Display setting", "Display window was not created successfully", NULL, ALLEGRO_MESSAGEBOX_WARN);
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font = al_load_font("orbitron-black.ttf", 36, NULL);

	al_draw_text(font, al_map_rgb(44, 117, 255), ScreenWidth / 2, ScreenHeight / 2, ALLEGRO_ALIGN_LEFT, "Mandisi");

	al_flip_display();
	al_rest(10.0);
	al_destroy_font(font);
	al_destroy_display(display);

	return 0;

	// platform dimensions definition for the game
#define gridHeight 16     // rows
#define gridWidth 10      //columns

	//This is still to be implemented as a class, so that everyone could just use the ".h" file for this
	//meanwhile this serves the purpose of the platform creation of the game.Dimensions shall reamin as they are!!, so feel free to
	//incorporate them in your sections.>>>Peace!

	// int const gridHeight = 16;
	//int const gridWidth = 10;

	int tetrisPlatform[gridHeight][gridWidth] = {			//Here I'm just defining the 16 by 10 matrix to map out the platform
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};

}