#include<stdio.h>
#include<allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5\allegro_font.h>

int const menu_screen_w = 800;
int const menu_screen_h = 450;
int const tutorial_screen_w = 1250;
int const tutorial_screen_h = 650;
int const new_game_choose_w = 800;
int const new_game_choose_h = 450;
int const lvls_screen_w = 1250;
int const lvls_screen_h = 650;

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
			if (mouse_over_ng == true)
			{
				click_ng = true;
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
		al_draw_bitmap(ladder, 415, 230, NULL);

		ALLEGRO_BITMAP *champion = al_load_bitmap("champion.png");

		ALLEGRO_BITMAP *key = al_load_bitmap("key.png");
		al_draw_bitmap(key, 750, 295, NULL);

		ALLEGRO_BITMAP *closed_door = al_load_bitmap("closed_door.png");
		al_draw_bitmap(closed_door, 235, 225, NULL);

		ALLEGRO_BITMAP *opened_door = al_load_bitmap("opened_door.png");

		ALLEGRO_BITMAP *artifact = al_load_bitmap("artifact.png");
		al_draw_bitmap(artifact, 105, 295, NULL);

		ALLEGRO_BITMAP *portal_closed = al_load_bitmap("portal_closed.png");
		al_draw_bitmap(portal_closed, 1000, 45, NULL);

		ALLEGRO_BITMAP *portal_opened = al_load_bitmap("portal_opened.png");

		ALLEGRO_FONT *tutorial_font = al_load_font("ARIALNB.TTF", 25, NULL);
		

		int x_position = 75;
		int y_position = 455;
		bool end_of_tutorial = false;
		bool champion_over_ladder = false;
		bool champion_on_ladder = false;
		bool key_owned = false;
		bool door_opened = false;
		bool artifact_owned = false;
		bool champion_over_portal = false;
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
				al_draw_bitmap(ladder, 415, 230, NULL);
				if (key_owned == false)
				{
					al_draw_bitmap(key, 750, 295, NULL);
				}
				else
				{
					al_draw_bitmap(key, 15, 15, NULL);
				}
				if (door_opened == false)
				{
					al_draw_bitmap(closed_door, 235, 225, NULL);
				}
				else
				{
					al_draw_bitmap(opened_door, 235, 225, NULL);
				}
				if (artifact_owned == false)
				{
					al_draw_bitmap(artifact, 105, 295, NULL);
				}
				else
				{
					al_draw_bitmap(artifact, 15, 65, NULL);
				}
				if (artifact_owned == false)
				{
					al_draw_bitmap(portal_closed, 1000, 45, NULL);
				}
				else if (artifact_owned == true)
				{
					al_draw_bitmap(portal_opened, 1000, 45, NULL);
				}
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
			if ((x_position < 900)&&(y_position==455))
			{
				al_draw_text(tutorial_font, al_map_rgb(53, 72, 94), 700, 30, ALLEGRO_ALIGN_CENTER, "Hello! This is your champion. Use your cursor keys to move him!");
			}
			// text 02
			if ((x_position >= 915)&&(y_position==455))
			{
				al_draw_text(tutorial_font, al_map_rgb(53, 72, 94), 700, 30, ALLEGRO_ALIGN_CENTER, "Ooo! You have found a ladder! Ladders are the only way to go higher. Let's check it! Use your up key!");
			}
			// text 03
			if ((x_position <= 895) && (x_position > 735) && (y_position == 285))
			{
				al_draw_text(tutorial_font, al_map_rgb(53, 72, 94), 700, 30, ALLEGRO_ALIGN_CENTER, "Do you see the door in front of you? You need a key to open them!");
			}
			//text 04
			if ((x_position == 735) && (y_position == 285))
			{
				al_draw_text(tutorial_font, al_map_rgb(53, 72, 94), 700, 30, ALLEGRO_ALIGN_CENTER, "OK! You have found the key, you can see it in the left corner.");
			}
			//text 05
			if ((x_position <=595) && (x_position>275) && (y_position == 285) && (artifact_owned==false))
			{
				al_draw_text(tutorial_font, al_map_rgb(53, 72, 94), 700, 30, ALLEGRO_ALIGN_CENTER, "This ladder is tempting, but keep going left, please. :)");
			}
			//text 06
			if ((x_position == 275) && (y_position == 285) && (artifact_owned == false))
			{
				al_draw_multiline_text(tutorial_font, al_map_rgb(53, 72, 94), 700, 30, 1000, 25, ALLEGRO_ALIGN_CENTER, "Oh, yeah! The door is open! And look, there is artifact behind a door. You need to take it, if you want to finish this level. Then, go higher by the ladder.");
			}
			//text 07
			if ((x_position >= 535) && (y_position == 115))
			{
				al_draw_text(tutorial_font, al_map_rgb(53, 72, 94), 700, 30, ALLEGRO_ALIGN_CENTER, "You have got the artifact, so portal is activated! This is the end of our tutorial!");
			}

			if ((x_position==1035)&&(y_position<=455)&&(y_position>285))
			{
				champion_over_ladder = true;
			}
			else if ((x_position == 415) && (y_position <= 285) && (y_position > 115))
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
			else if (y_position == 115)
			{
				champion_on_ladder = false;
			}
			else
			{
				champion_on_ladder = true;
			}

			if ((x_position == 735) && (y_position == 285))
			{
				key_owned = true;
			}

			if ((x_position == 275) && (y_position == 285))
			{
				if (key_owned == true)
				{
					door_opened = true;
				}
			}

			if ((x_position == 75) && (y_position == 285))
			{
				artifact_owned = true;
			}

			if ((x_position == 1015) && (y_position == 115) && (artifact_owned == true))
			{
				champion_over_portal = true;
			}

			if (champion_over_portal == true)
			{
				end_of_tutorial = true;
			}

			printf("x: %d\n", mouse_x);
			printf("y: %d\n", mouse_y);
			printf("x_position: %d\n", x_position);
			printf("y_position: %d\n", y_position);
			al_flip_display();
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_destroy_bitmap(artifact);
		al_destroy_bitmap(champion);
		al_destroy_bitmap(closed_door);
		al_destroy_bitmap(ground);
		al_destroy_bitmap(key);
		al_destroy_bitmap(ladder);
		al_destroy_bitmap(opened_door);
		al_destroy_bitmap(portal_closed);
		al_destroy_bitmap(portal_opened);
		al_destroy_bitmap(tutorial_background);
		al_destroy_font(tutorial_font);
		al_destroy_display(tutorial_display);
		//al_destroy_event_queue(tutorial_queue);
	}

	if (click_ng == true)
	{
		al_destroy_bitmap(menu_logo);
		al_destroy_font(font_choose_menu);
		al_destroy_font(font_main_menu);
		al_destroy_display(menu_display);

		ALLEGRO_DISPLAY *new_game_choose_display = al_create_display(new_game_choose_w, new_game_choose_h);
		if (!new_game_choose_display)
		{
			printf("Failed to create new game choose display!\n");
			return 1;
		}

		ALLEGRO_BITMAP *new_game_choose_menu = al_load_bitmap("choosemenu.png");

		ALLEGRO_FONT *font_new_game_choose_menu = al_load_font("calibri.ttf", 35, ALLEGRO_ALIGN_CENTER);

		bool exit_choose_menu = false;
		bool mouse_over_lvl1 = false;
		bool mouse_over_lvl2 = false;
		bool mouse_over_lvl3 = false;
		bool mouse_over_lvl4 = false;
		bool mouse_over_lvl5 = false;
		bool click_lvl1 = false;
		bool click_lvl2 = false;
		bool click_lvl3 = false;
		bool click_lvl4 = false;
		bool click_lvl5 = false;
		int r_lvl1 = 255;
		int r_lvl2 = 255;
		int r_lvl3 = 255;
		int r_lvl4 = 255;
		int r_lvl5 = 255;
		int g_lvl1 = 255;
		int g_lvl2 = 255;
		int g_lvl3 = 255;
		int g_lvl4 = 255;
		int g_lvl5 = 255;
		int b_lvl1 = 255;
		int b_lvl2 = 255;
		int b_lvl3 = 255;
		int b_lvl4 = 255;
		int b_lvl5 = 255;

		while (!exit_choose_menu)
		{
			ALLEGRO_EVENT_QUEUE *new_game_choose_menu_queue = al_create_event_queue();
			al_register_event_source(new_game_choose_menu_queue, al_get_mouse_event_source());

			ALLEGRO_EVENT new_game_choose_menu_event;
			al_wait_for_event(new_game_choose_menu_queue, &new_game_choose_menu_event);

			if (new_game_choose_menu_event.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				mouse_x = new_game_choose_menu_event.mouse.x;
				mouse_y = new_game_choose_menu_event.mouse.y;
			
				if ((mouse_y >= 195) && (mouse_y <= 230) && (mouse_x >= 355) && (mouse_x <= 445))
				{
					r_lvl1 = 20;
					g_lvl1 = 167;
					b_lvl1 = 230;
					mouse_over_lvl1 = true;
				}
				else
				{
					r_lvl1 = 255;
					g_lvl1 = 255;
					b_lvl1 = 255;
					mouse_over_lvl1 = false;
				}

				if ((mouse_y >= 240) && (mouse_y <= 275) && (mouse_x >= 355) && (mouse_x <= 445))
				{
					r_lvl2 = 20;
					g_lvl2 = 167;
					b_lvl2 = 230;
					mouse_over_lvl2 = true;
				}
				else
				{
					r_lvl2 = 255;
					g_lvl2 = 255;
					b_lvl2 = 255;
					mouse_over_lvl2 = false;
				}

				if ((mouse_y >= 285) && (mouse_y <= 315) && (mouse_x >= 355) && (mouse_x <= 445))
				{
					r_lvl3 = 20;
					g_lvl3 = 167;
					b_lvl3 = 230;
					mouse_over_lvl3 = true;
				}
				else
				{
					r_lvl3 = 255;
					g_lvl3 = 255;
					b_lvl3 = 255;
					mouse_over_lvl3 = false;
				}
			
				if ((mouse_y >= 325) && (mouse_y <= 365) && (mouse_x >= 355) && (mouse_x <= 445))
				{
					r_lvl4 = 20;
					g_lvl4 = 167;
					b_lvl4 = 230;
					mouse_over_lvl4 = true;
				}
				else
				{
					r_lvl4 = 255;
					g_lvl4 = 255;
					b_lvl4 = 255;
					mouse_over_lvl4 = false;
				}

				if ((mouse_y >= 375) && (mouse_y <= 405) && (mouse_x >= 355) && (mouse_x <= 445))
				{
					r_lvl5 = 20;
					g_lvl5 = 167;
					b_lvl5 = 230;
					mouse_over_lvl5 = true;
				}
				else
				{
					r_lvl5 = 255;
					g_lvl5 = 255;
					b_lvl5 = 255;
					mouse_over_lvl5 = false;
				}
			}

			if (new_game_choose_menu_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (mouse_over_lvl1 == true)
				{
					click_lvl1 = true;
					exit_choose_menu = true;
				}

				if (mouse_over_lvl2 == true)
				{
					click_lvl2 = true;
					exit_choose_menu = true;
				}

				if (mouse_over_lvl3 == true)
				{
					click_lvl3 = true;
					exit_choose_menu = true;
				}

				if (mouse_over_lvl4 == true)
				{
					click_lvl4 = true;
					exit_choose_menu = true;
				}

				if (mouse_over_lvl5 == true)
				{
					click_lvl5 = true;
					exit_choose_menu = true;
				}
			}
			printf("x: %d\n", mouse_x);
			printf("y: %d\n", mouse_y);
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(new_game_choose_menu, 0, 0, NULL);
			al_draw_text(font_new_game_choose_menu, al_map_rgb(r_lvl1, g_lvl1, b_lvl1), new_game_choose_w / 2, 200, ALLEGRO_ALIGN_CENTER, "level 1");
			al_draw_text(font_new_game_choose_menu, al_map_rgb(r_lvl2, g_lvl2, b_lvl2), new_game_choose_w / 2, 240, ALLEGRO_ALIGN_CENTER, "level 2");
			al_draw_text(font_new_game_choose_menu, al_map_rgb(r_lvl3, g_lvl3, b_lvl3), new_game_choose_w / 2, 280, ALLEGRO_ALIGN_CENTER, "level 3");
			al_draw_text(font_new_game_choose_menu, al_map_rgb(r_lvl4, g_lvl4, b_lvl4), new_game_choose_w / 2, 320, ALLEGRO_ALIGN_CENTER, "level 4");
			al_draw_text(font_new_game_choose_menu, al_map_rgb(r_lvl5, g_lvl5, b_lvl5), new_game_choose_w / 2, 360, ALLEGRO_ALIGN_CENTER, "level 5");
			al_flip_display();
		}

		if (click_lvl1 == true)
		{
			al_destroy_bitmap(new_game_choose_menu);
			al_destroy_font(font_new_game_choose_menu);
			al_destroy_display(new_game_choose_display);

			ALLEGRO_DISPLAY *lvl1_display = al_create_display(lvls_screen_w, lvls_screen_h);
			if (!lvl1_display)
			{
				printf("Failed to create new level display!\n");
				return 1;
			}
			
			ALLEGRO_BITMAP *lvl1_background = al_load_bitmap("tut_background.png");











			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(lvl1_background, 0, 0, NULL);
			al_flip_display();

		}
		
		
	









	}



	system("pause");
	return 0;
}