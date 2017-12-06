#include<stdio.h>
#include<allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5\allegro_font.h>

int const menu_screen_w = 800;
int const menu_screen_h = 450;
int const tutorial_screen_w = 1250;
int const tutorial_screen_h = 650;

int main()
{
	al_init();
	if (!al_init())
	{
		printf("Failed to initialize allegro5!\n");
		return 1;
	}

	ALLEGRO_DISPLAY *menu_display = al_create_display(menu_screen_w, menu_screen_h);
	if (!menu_display)
	{
		printf("Failed to create menu display!\n");
		return 1;
	}

	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_BITMAP *menu_logo = al_load_bitmap("logomenu.png");
	
	ALLEGRO_FONT *font_main_menu = al_load_font("calibri.ttf", 55, ALLEGRO_ALIGN_CENTER);
	ALLEGRO_FONT *font_choose_menu = al_load_font("calibri.ttf", 35, ALLEGRO_ALIGN_CENTER);

	ALLEGRO_EVENT_QUEUE *mouse_queue = al_create_event_queue();
	al_register_event_source(mouse_queue, al_get_mouse_event_source());

	bool exit_menu = false;
	bool mouse_over_ng = false;
	bool mouse_over_t = false;
	bool mouse_over_e = false;
	bool click_ng = false;
	bool click_t = false;
	bool click_e = false;
	int mouse_x;
	int mouse_y;
	int r_ng = 255;
	int r_t = 255;
	int r_e = 255;
	int g_ng = 255;
	int g_t = 255;
	int g_e = 255;
	int b_ng = 255;
	int b_t = 255;
	int b_e = 255;

	while (!exit_menu)
	{
		ALLEGRO_EVENT menu_event;
		al_wait_for_event(mouse_queue, &menu_event);

		if (menu_event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			mouse_x = menu_event.mouse.x;
			mouse_y = menu_event.mouse.y;


			if ((mouse_y >= 280) && (mouse_y <= 305) && (mouse_x >= 328) && (mouse_x <= 474))
			{
				r_ng = 20;
				g_ng = 167;
				b_ng = 230;
				mouse_over_ng = true;
			}
			else
			{
				r_ng = 255;
				g_ng = 255;
				b_ng = 255;
				mouse_over_ng = false;
			}

			if ((mouse_y >= 312) && (mouse_y <= 337) && (mouse_x >= 349) && (mouse_x <= 451))
			{
				r_t = 20;
				g_t = 167;
				b_t = 230;
				mouse_over_t = true;
			}
			else
			{
				r_t = 255;
				g_t = 255;
				b_t = 255;
				mouse_over_t = false;
			}

			if ((mouse_y >= 354) && (mouse_y <= 374) && (mouse_x >= 374) && (mouse_x <= 424))
			{
				r_e = 20;
				g_e = 167;
				b_e = 230;
				mouse_over_e = true;
			}
			else
			{
				r_e = 255;
				g_e = 255;
				b_e = 255;
				mouse_over_e = false;
			}
		}
		if (menu_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (mouse_over_e == true)
			{
				click_e = true;
				exit_menu = true;
			}
			if (mouse_over_t == true)
			{
				click_t = true;
				exit_menu = true;
			}
		}

			printf("x: %d\n", mouse_x);
			printf("y: %d\n", mouse_y);
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_get_target_bitmap(menu_logo);
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(menu_logo, 0, 0, NULL);
			al_get_target_bitmap(al_get_backbuffer(menu_display));
			al_draw_text(font_main_menu, al_map_rgb(255, 255, 255), menu_screen_w / 2, 200, ALLEGRO_ALIGN_CENTER, "MAIN MENU");
			al_draw_text(font_choose_menu, al_map_rgb(r_ng, g_ng, b_ng), menu_screen_w / 2, 270, ALLEGRO_ALIGN_CENTER, "new game");
			al_draw_text(font_choose_menu, al_map_rgb(r_t, g_t, b_t), menu_screen_w / 2, 310, ALLEGRO_ALIGN_CENTER, "tutorial");
			al_draw_text(font_choose_menu, al_map_rgb(r_e, g_e, b_e), menu_screen_w / 2, 350, ALLEGRO_ALIGN_CENTER, "exit");
			al_flip_display();
		
	}
	if (click_e == true)
	{
		al_destroy_bitmap(menu_logo);
		al_destroy_event_queue(mouse_queue);
		al_destroy_font(font_choose_menu);
		al_destroy_font(font_main_menu);
		al_destroy_display(menu_display);
	}
	if (click_t == true)
	{
		al_destroy_bitmap(menu_logo);
		al_destroy_font(font_choose_menu);
		al_destroy_font(font_main_menu);
		al_destroy_display(menu_display);

		ALLEGRO_DISPLAY *tutorial_display = al_create_display(tutorial_screen_w, tutorial_screen_h);
		if (!tutorial_display)
		{
			printf("Failed to create tutorial display!\n");
			return 1;
		}

		ALLEGRO_BITMAP *tutorial_background = al_load_bitmap("tut_background.png");
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(tutorial_background, 0, 0, NULL);

		ALLEGRO_BITMAP *ground = al_load_bitmap("ground.png");
		al_draw_bitmap(ground, 65, 545, NULL);
		al_draw_bitmap(ground, 65, 375, NULL);
		al_draw_bitmap(ground, 65, 205, NULL);

		ALLEGRO_BITMAP *ladder = al_load_bitmap("ladder.png");
		al_draw_bitmap(ladder, 1035, 400, NULL);

		ALLEGRO_BITMAP *champion = al_load_bitmap("champion.png");

		ALLEGRO_FONT *tutorial_font = al_load_font("ARIALNB.TTF", 25, NULL);
		

		int x_position = 75;
		int y_position = 455;
		bool end_of_tutorial = false;
		bool champion_over_ladder = false;
		bool champion_on_ladder = false;
		while (!end_of_tutorial)
		{
			ALLEGRO_EVENT_QUEUE *tutorial_queue = al_create_event_queue();
			al_register_event_source(tutorial_queue, al_get_mouse_event_source());
			al_register_event_source(tutorial_queue, al_get_keyboard_event_source());

			ALLEGRO_EVENT tutorial_event;
			al_wait_for_event(tutorial_queue, &tutorial_event);
			if (tutorial_event.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				mouse_x = tutorial_event.mouse.x;
				mouse_y = tutorial_event.mouse.y;
			}



			if (tutorial_event.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_bitmap(tutorial_background, 0, 0, NULL);
				al_draw_bitmap(ground, 65, 545, NULL);
				al_draw_bitmap(ground, 65, 375, NULL);
				al_draw_bitmap(ground, 65, 205, NULL);
				al_draw_bitmap(ladder, 1035, 400, NULL);
				
				switch (tutorial_event.keyboard.keycode)
				{
				case ALLEGRO_KEY_LEFT:
				{
					printf("left\n");
					if ((x_position-20>=35)&&(champion_on_ladder==false))
					{
						x_position = x_position - 20;
					}
					break;
				}
				case ALLEGRO_KEY_RIGHT:
				{
					printf("right\n");
					if ((x_position+20<=1135)&&(champion_on_ladder==false))
					{
						x_position = x_position + 20;
					}
					break;
				}
				case ALLEGRO_KEY_UP:
				{
					printf("up\n");
					if (champion_over_ladder == true)
					{
					y_position = y_position - 34;
					}
					break;
				}
				}
			}
			al_draw_bitmap(champion, x_position, y_position, NULL);

			// text 01 -> hello!
			if (x_position < 900)
			{
				al_draw_text(tutorial_font, al_map_rgb(53, 72, 94), 700, 30, ALLEGRO_ALIGN_CENTER, "Hello! This is your champion. Use your cursor keys to move him!");
			}
			// text 02
			if (x_position >= 915)
			{
				al_draw_text(tutorial_font, al_map_rgb(53, 72, 94), 700, 30, ALLEGRO_ALIGN_CENTER, "Ooo! You have found a ladder! Ladders are the only way to go higher. Let's check it! Use your up key!");
			}

			if ((x_position == 1035) && (y_position > 285))
			{
				champion_over_ladder = true;
			}
			else
			{
				champion_over_ladder = false;
			}
			

			if (y_position == 455)
			{
				champion_on_ladder = false;
			}
			else if (y_position == 285)
			{
				champion_on_ladder = false;
			}
			else
			{
				champion_on_ladder = true;
			}





			printf("x: %d\n", mouse_x);
			printf("y: %d\n", mouse_y);
			printf("x_position: %d\n", x_position);
			printf("y_position: %d\n", y_position);
			al_flip_display();
		}
	}
	system("pause");
	return 0;
}