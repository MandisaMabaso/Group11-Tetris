#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>


int main(void)
{
	ALLEGRO_DISPLAY *display = NULL;
	display = al_create_display(640, 480);

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font2 = al_load_font("Arimo-Bold.ttf", 20, 0);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font2, al_map_rgb(255, 0, 255),50,50,0, "Perfect M. Madondo");
	al_flip_display();
	al_rest(5.0);
	return 0;
}