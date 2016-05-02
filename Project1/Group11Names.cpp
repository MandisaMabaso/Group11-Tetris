#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include<iostream>
using namespace std;


int main()
{
	int ScreenWidth = 600;
	int ScreenHeight = 600;
	if (!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not initialise allegro 5", NULL, NULL);

		return -1;
	}

	al_set_new_display_flags(ALLEGRO_WINDOWED);
	ALLEGRO_DISPLAY *display = al_create_display(ScreenWidth, ScreenHeight);
	//al_set_window_position(display, 200, 100);
	//al_set_window_title(display, "display my name");
	enum direction { UP, DOWN, LEFT, RIGHT };
	int dir = DOWN;

	al_set_window_position(display, 400, 400);
	al_set_window_title(display, "Tetris");
	if (!display)
	{
		al_show_native_message_box(display, "Sample Title", "Display setting", "Display window was not created successfully", NULL, ALLEGRO_MESSAGEBOX_WARN);
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font = al_load_font("orbitron-black.ttf", 36, NULL);

	//al_draw_text(font, al_map_rgb(44, 117, 255), ScreenWidth / 2, ScreenHeight / 2, ALLEGRO_ALIGN_LEFT, "Mandisi");

	//al_flip_display();
	//al_rest(10.0);
	//al_destroy_font(font);
	//al_destroy_display(display);

	// Part 4 of the game: Displaying game over on the screen 

	//int ScreenHeight;
	int rows = 0;
	//cout << "Please enter the screen height and the last row" << endl;
	//cin >> screenHeight;
	//cin >> rows;
	//keyboard initialisation,game play wile loop and time initialisation


	al_init_primitives_addon();
	al_install_keyboard();
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60);
	ALLEGRO_EVENT_QUEUE *events = al_create_event_queue();
	al_register_event_source(events, al_get_keyboard_event_source());
	al_register_event_source(events, al_get_timer_event_source(timer));
	bool done = false, draw = true;
	int x = 225, y = 10;
	int velocity = 2;
	int hieght = 600;

	int boxWidth = 80;
	int boxHeight = 50;
	al_start_timer(timer);
	while (!done)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(events, &event);
		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (event.keyboard.keycode){

			case ALLEGRO_KEY_UP:
				if (boxWidth == 80) {
					boxWidth = 50;
					boxHeight = 80;
				}
				else {
					boxWidth = 80;
					boxHeight = 50;
				}
				//al_draw_rectangle(x, y, x + 50, y + 80, al_map_rgb(255, 255, 255), 1.0);
				//al_flip_display();
				//al_clear_to_color(al_map_rgb(0, 0, 0));
			case ALLEGRO_KEY_DOWN:

				dir = DOWN;
				break;
			case ALLEGRO_KEY_LEFT:
				x -= 20;
				dir = DOWN;
				break;
			case ALLEGRO_KEY_RIGHT:
				x += 20;
				dir = DOWN;
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}


		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			switch (dir)
			{
			case DOWN:
				y += velocity;
				break;
			case LEFT:
				x -= velocity;
				break;
			case RIGHT:
				x += velocity;
				break;
			}
		}
		
		
			al_draw_filled_rectangle(x, y, x + boxWidth, y + boxHeight, al_map_rgb(255, 255, 255));
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_line(0, ScreenHeight, ScreenWidth, ScreenHeight, al_map_rgb(255, 0, 0), 15);
			al_draw_line(0, 0, 0, ScreenHeight, al_map_rgb(255, 0, 0), 15);
			al_draw_line(450, 0, 450, ScreenHeight - 10, al_map_rgb(255, 0, 0), 15);
		
	
	}
	
	//al_flip_display();
	//al_clear_to_color(al_map_rgb(0, 0, 0));
	//}*/


	//al_draw_line(0, ScreenHeight, ScreenWidth,ScreenHeight , al_map_rgb(255, 0, 0),10);
	//al_flip_display();
	//al_clear_to_color(al_map_rgb(0, 0, 0));
	//al_draw_rectangle(35,35,100,100,al_map_rgb(155,155,155),1.0);
	//al_destroy_display(display);


	if (ScreenHeight == rows)
	{
		ALLEGRO_DISPLAY *displayGameOverMessage = NULL;
		if (!al_init())
		{
			al_show_native_message_box(NULL, NULL, NULL, "Failed to initialize allegro 5", NULL, NULL);
			return -1;
		}
		al_set_new_display_flags(ALLEGRO_WINDOWED);
		displayGameOverMessage = al_create_display(480, 340);
		al_set_window_position(displayGameOverMessage, 100, 200);
		al_set_window_title(displayGameOverMessage, "Tetris");

		if (!displayGameOverMessage)
		{
			al_show_native_message_box(NULL, NULL, NULL, "Failed to initialize display", NULL, NULL);
			return -1;
		}
		al_init_font_addon();
		al_init_ttf_addon();

		ALLEGRO_FONT *font40 = al_load_font("alex-brush.ttf", 40, NULL);
		al_draw_text(font40, al_map_rgb(117, 234, 255), 240, 170, ALLEGRO_ALIGN_CENTER, "GAME OVER");

		al_flip_display();
		al_rest(10.0);
		al_destroy_font(font40);
		al_destroy_display(displayGameOverMessage);
		return 0;
	}
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

