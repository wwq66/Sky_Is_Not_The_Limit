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
			al_clear_to_color(al_map_rgb(0, 0, 0));

			ALLEGRO_BITMAP *lvl1_background = al_load_bitmap("tut_background.png");
			al_draw_bitmap(lvl1_background, 0, 0, NULL);

			ALLEGRO_BITMAP *lvl1_ground = al_load_bitmap("ground_lvls.png");
			al_draw_bitmap(lvl1_ground, 65, 360, NULL);
			al_draw_bitmap(lvl1_ground, 65, 240, NULL);
			al_draw_bitmap(lvl1_ground, 65, 120, NULL);

			ALLEGRO_BITMAP *lvl1_broken_ground = al_load_bitmap("broken_ground_lvl1.png");
			al_draw_bitmap(lvl1_broken_ground, 65, 600, NULL);
			al_draw_bitmap(lvl1_broken_ground, 65, 480, NULL);

			ALLEGRO_BITMAP *lvl1_champion = al_load_bitmap("champion_lvls.png");

			ALLEGRO_BITMAP *lvl1_ladder = al_load_bitmap("ladder_lvls.png");
			al_draw_bitmap(lvl1_ladder, 325, 492, NULL);
			al_draw_bitmap(lvl1_ladder, 1105, 492, NULL);
			al_draw_bitmap(lvl1_ladder, 165, 372, NULL);
			al_draw_bitmap(lvl1_ladder, 545, 372, NULL);
			al_draw_bitmap(lvl1_ladder, 985, 372, NULL);
			al_draw_bitmap(lvl1_ladder, 365, 252, NULL);
			al_draw_bitmap(lvl1_ladder, 925, 132, NULL);

			ALLEGRO_BITMAP *lvl1_closed_door = al_load_bitmap("closed_door_lvls.png");
			al_draw_bitmap(lvl1_closed_door, 770, 252, NULL);

			ALLEGRO_BITMAP *lvl1_opened_door = al_load_bitmap("opened_door_lvls.png");

			ALLEGRO_BITMAP *lvl1_key = al_load_bitmap("key_lvls.png");
			al_draw_bitmap(lvl1_key, 95, 80, NULL);

			ALLEGRO_BITMAP *lvl1_artifact = al_load_bitmap("artifact_lvls.png");
			al_draw_bitmap(lvl1_artifact, 1000, 560, NULL);

			ALLEGRO_BITMAP *lvl1_stone = al_load_bitmap("stone_lvls.png");
			al_draw_bitmap(lvl1_stone, 825, 132, NULL);
			al_draw_bitmap(lvl1_stone, 235, 372, NULL);

			ALLEGRO_BITMAP *lvl1_pickaxe = al_load_bitmap("pick_lvls.png");
			al_draw_bitmap(lvl1_pickaxe, 95, 440, NULL);

			ALLEGRO_BITMAP *lvl1_closed_portal = al_load_bitmap("closed_portal_lvls.png");
			al_draw_bitmap(lvl1_closed_portal, 1050, 15, NULL);

			ALLEGRO_BITMAP *lvl1_destroyed_stone = al_load_bitmap("destroyed_stone_lvls.png");

			ALLEGRO_BITMAP *lvl1_opened_portal = al_load_bitmap("opened_portal_lvls.png");

			int x_position = 65;
			int y_position = 555;
			bool left_key_locked = false;
			bool right_key_locked = false;
			bool up_key_locked = false;
			bool down_key_locked = false;
			bool champion_on_ladder = false;
			bool pick_owned = false;
			bool stone1_destroyed = false;
			bool stone2_destroyed = false;
			bool key_owned = false;
			bool door_opened = false;
			bool artifact_owned = false;
			bool champion_over_portal = false;
			bool end_of_lvl1 = false;
			while (!end_of_lvl1)
			{
				ALLEGRO_EVENT_QUEUE *lvl1_queue = al_create_event_queue();
				al_register_event_source(lvl1_queue, al_get_mouse_event_source());
				al_register_event_source(lvl1_queue, al_get_keyboard_event_source());

				ALLEGRO_EVENT lvl1_event;
				al_wait_for_event(lvl1_queue, &lvl1_event);

				if (lvl1_event.type == ALLEGRO_EVENT_MOUSE_AXES)
				{
					mouse_x = lvl1_event.mouse.x;
					mouse_y = lvl1_event.mouse.y;
				}

				if (lvl1_event.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					al_clear_to_color(al_map_rgb(0, 0, 0));
					al_draw_bitmap(lvl1_background, 0, 0, NULL);
					al_draw_bitmap(lvl1_ground, 65, 360, NULL);
					al_draw_bitmap(lvl1_ground, 65, 240, NULL);
					al_draw_bitmap(lvl1_ground, 65, 120, NULL);
					al_draw_bitmap(lvl1_broken_ground, 65, 600, NULL);
					al_draw_bitmap(lvl1_broken_ground, 65, 480, NULL);
					al_draw_bitmap(lvl1_ladder, 325, 492, NULL);
					al_draw_bitmap(lvl1_ladder, 1105, 492, NULL);
					al_draw_bitmap(lvl1_ladder, 165, 372, NULL);
					al_draw_bitmap(lvl1_ladder, 545, 372, NULL);
					al_draw_bitmap(lvl1_ladder, 985, 372, NULL);
					al_draw_bitmap(lvl1_ladder, 365, 252, NULL);
					al_draw_bitmap(lvl1_ladder, 925, 132, NULL);
					if (artifact_owned == false)
					{
						al_draw_bitmap(lvl1_closed_portal, 1050, 15, NULL);
					}
					else
					{
						al_draw_bitmap(lvl1_opened_portal, 1050, 15, NULL);
					}
					if (door_opened == false)
					{
						al_draw_bitmap(lvl1_closed_door, 770, 252, NULL);
					}
					else
					{
						al_draw_bitmap(lvl1_opened_door, 770, 252, NULL);
					}
					if (pick_owned == false)
					{
						al_draw_bitmap(lvl1_pickaxe, 95, 440, NULL);
					}
					else
					{
						al_draw_bitmap(lvl1_pickaxe, 15, 15, NULL);
					}
					if (stone1_destroyed == false)
					{
						al_draw_bitmap(lvl1_stone, 235, 372, NULL);
					}
					else
					{
						al_draw_bitmap(lvl1_destroyed_stone, 235, 372, NULL);
					}
					if (stone2_destroyed == false)
					{
						al_draw_bitmap(lvl1_stone, 825, 132, NULL);
					}
					else
					{
						al_draw_bitmap(lvl1_destroyed_stone, 825, 132, NULL);
					}
					if (key_owned == false)
					{
						al_draw_bitmap(lvl1_key, 95, 80, NULL);
					}
					else
					{
						al_draw_bitmap(lvl1_key, 60, 15, NULL);
					}
					if (artifact_owned == false)
					{
						al_draw_bitmap(lvl1_artifact, 1000, 560, NULL);
					}
					else
					{
						al_draw_bitmap(lvl1_artifact, 105, 15, NULL);
					}
					switch (lvl1_event.keyboard.keycode)
					{
					case ALLEGRO_KEY_LEFT:
					{
						printf("left\n");
						if ((left_key_locked==false)&&(champion_on_ladder==false))
						{
							x_position = x_position - 20;
						}
						break;
					}
					case ALLEGRO_KEY_RIGHT:
					{
						printf("right\n");
						if ((right_key_locked == false)&&(champion_on_ladder==false))
						{
							x_position = x_position + 20;
						}
						break;
					}
					case ALLEGRO_KEY_UP:
					{
						printf("up\n");
						if (up_key_locked == false)
						{
							y_position = y_position - 40;
						}
						break;
					}
					case ALLEGRO_KEY_DOWN:
					{
						printf("down\n");
						if (down_key_locked == false)
						{
							y_position = y_position + 40;
						}
						break;
					}
					}
				}
				al_draw_bitmap(lvl1_champion, x_position, y_position, NULL);

				//RIGHT CLICK LOCKED
				if (x_position == 1145)
				{
					right_key_locked = true;
				}
				else if ((x_position == 605) && (y_position == 555))
				{
					right_key_locked = true;
				}
				else if ((x_position == 605) && (y_position == 435))
				{
					right_key_locked = true;
				}
				else if ((x_position == 725) && (y_position == 315)&&(door_opened==false))
				{
					right_key_locked = true;
				}
				else if ((x_position == 185) && (y_position == 435)&&(stone1_destroyed==false))
				{
					right_key_locked = true;
				}
				else if ((x_position == 765) && (y_position == 195)&&(stone2_destroyed==false))
				{
					right_key_locked = true;
				}
				else
				{
					right_key_locked = false;
				}

				//LEFT KLICK LOCKED
				if (x_position == 65)
				{
					left_key_locked = true;
				}
				else if ((x_position == 945) && (y_position == 555))
				{
					left_key_locked = true;
				}
				else if ((x_position == 945) && (y_position == 435))
				{
					left_key_locked = true;
				}
				else if ((x_position == 265) && (y_position == 435)&&(stone1_destroyed==false))
				{
					left_key_locked = true;
				}
				else if ((x_position == 805) && (y_position == 315)&&(door_opened==false))
				{
					left_key_locked = true;
				}
				else if ((x_position == 865) && (y_position == 195)&&(stone2_destroyed==false))
				{
					left_key_locked = true;
				}
				else
				{
					left_key_locked = false;
				}

				//CHAMPION ON LADDER
				if ((y_position == 555) || (y_position == 435) || (y_position == 315) || (y_position == 195) || (y_position == 75))
				{
					champion_on_ladder = false;
				}
				else
				{
					champion_on_ladder = true;
				}

				//UP KEY LOCKED
				if ((x_position == 325) && (y_position > 435) && (y_position <= 555))
				{
					up_key_locked = false;
				}
				else if ((x_position == 165) && (y_position > 315) && (y_position <= 435))
				{
					up_key_locked = false;
				}
				else if ((x_position == 545) && (y_position > 315) && (y_position <= 435))
				{
					up_key_locked = false;
				}
				else if ((x_position == 365) && (y_position > 195) && (y_position <= 315))
				{
					up_key_locked = false;
				}
				else if ((x_position == 925) && (y_position > 75) && (y_position <= 195))
				{
					up_key_locked = false;
				}
				else if ((x_position == 985) && (y_position > 315) && (y_position <= 435))
				{
					up_key_locked = false;
				}
				else if ((x_position == 1105) && (y_position > 435) && (y_position <= 555))
				{
					up_key_locked = false;
				}
				else
				{
					up_key_locked = true;
				}

				//DOWN KEY LOCKED
				if ((x_position == 325) && (y_position >= 435) && (y_position < 555))
				{
					down_key_locked = false;
				}
				else if ((x_position == 165) && (y_position >= 315) && (y_position < 435))
				{
					down_key_locked = false;
				}
				else if ((x_position == 545) && (y_position >= 315) && (y_position < 435))
				{
					down_key_locked = false;
				}
				else if ((x_position == 365) && (y_position >= 195) && (y_position < 315))
				{
					down_key_locked = false;
				}
				else if ((x_position == 925) && (y_position >= 75) && (y_position < 195))
				{
					down_key_locked = false;
				}
				else if ((x_position == 985) && (y_position >= 315) && (y_position < 435))
				{
					down_key_locked = false;
				}
				else if ((x_position == 1105) && (y_position >= 435) && (y_position < 555))
				{
					down_key_locked = false;
				}
				else
				{
					down_key_locked = true;
				}

				//PICK
				if ((x_position == 105) && (y_position == 435))
				{
					pick_owned = true;
				}

				//STONE1 DESTROYED
				if ((pick_owned == true) && (x_position == 185) && (y_position == 435))
				{
					stone1_destroyed = true;
				}
				else if ((pick_owned == true) && (x_position == 265) && (y_position == 435))
				{
					stone1_destroyed = true;
				}

				//STONE2 DESTROYED
				if ((pick_owned == true) && (x_position == 765) && (y_position == 195))
				{
					stone2_destroyed = true;
				}
				else if ((pick_owned == true) && (x_position == 865) && (y_position == 195))
				{
					stone2_destroyed = true;
				}

				//KEY OWNED
				if ((x_position == 105) && (y_position == 75))
				{
					key_owned = true;
				}

				//DOOR OPENED
				if ((x_position == 725) && (y_position == 315) && (key_owned == true))
				{
					door_opened = true;
				}

				//ARTIFACT OWNED
				if ((x_position == 1005) && (y_position == 555))
				{
					artifact_owned = true;
				}

				//CHAMPION OVER PORTAL
				if ((x_position == 1065) && (y_position == 75)&&(artifact_owned==true))
				{
					champion_over_portal = true;
				}
				if (champion_over_portal == true)
				{
					end_of_lvl1 = true;
				}



				printf("x: %d\n", mouse_x);
				printf("y: %d\n", mouse_y);
				printf("x_position: %d\n", x_position);
				printf("y_position: %d\n", y_position);
				al_flip_display();
			} //while end lvl 1 = false
			al_destroy_bitmap(lvl1_artifact);
			al_destroy_bitmap(lvl1_background);
			al_destroy_bitmap(lvl1_broken_ground);
			al_destroy_bitmap(lvl1_champion);
			al_destroy_bitmap(lvl1_closed_door);
			al_destroy_bitmap(lvl1_closed_portal);
			al_destroy_bitmap(lvl1_destroyed_stone);
			al_destroy_bitmap(lvl1_stone);
			al_destroy_bitmap(lvl1_ground);
			al_destroy_bitmap(lvl1_key);
			al_destroy_bitmap(lvl1_ladder);
			al_destroy_bitmap(lvl1_opened_door);
			al_destroy_bitmap(lvl1_opened_portal);
			al_destroy_bitmap(lvl1_pickaxe);
			al_destroy_display(lvl1_display);
		} //click lvl1=true


		if (click_lvl2 == true)
		{
			al_destroy_bitmap(new_game_choose_menu);
			al_destroy_font(font_new_game_choose_menu);
			al_destroy_display(new_game_choose_display);

			ALLEGRO_DISPLAY *lvl2_display = al_create_display(lvls_screen_w, lvls_screen_h);
			if (!lvl2_display)
			{
				printf("Failed to create lvl 2 display!\n");
				return 1;
			}

			ALLEGRO_BITMAP *lvl2_background = al_load_bitmap("tut_background.png");
			al_draw_bitmap(lvl2_background, 0, 0, NULL);

			ALLEGRO_BITMAP *lvl2_ground_1 = al_load_bitmap("ground_lvl2_1.png");
			al_draw_bitmap(lvl2_ground_1, 65, 600, NULL);

			ALLEGRO_BITMAP *lvl2_ground_2 = al_load_bitmap("ground_lvl2_2.png");
			al_draw_bitmap(lvl2_ground_2, 65, 480, NULL);

			ALLEGRO_BITMAP *lvl2_ground_3 = al_load_bitmap("ground_lvl2_3.png");
			al_draw_bitmap(lvl2_ground_3, 65, 360, NULL);

			ALLEGRO_BITMAP *lvl2_ground_4 = al_load_bitmap("ground_lvl2_4.png");
			al_draw_bitmap(lvl2_ground_4, 65, 240, NULL);

			ALLEGRO_BITMAP *lvl2_ground_5 = al_load_bitmap("ground_lvl2_5.png");
			al_draw_bitmap(lvl2_ground_5, 65, 120, NULL);

			ALLEGRO_BITMAP *lvl2_champion = al_load_bitmap("champion_lvls.png");

			ALLEGRO_BITMAP *lvl2_ladder = al_load_bitmap("ladder_lvls.png");
			al_draw_bitmap(lvl2_ladder, 205, 492, NULL);
			al_draw_bitmap(lvl2_ladder, 505, 492, NULL);
			al_draw_bitmap(lvl2_ladder, 925, 492, NULL);
			al_draw_bitmap(lvl2_ladder, 365, 372, NULL);
			al_draw_bitmap(lvl2_ladder, 105, 252, NULL);
			al_draw_bitmap(lvl2_ladder, 105, 132, NULL);
			al_draw_bitmap(lvl2_ladder, 565, 132, NULL);
			al_draw_bitmap(lvl2_ladder, 805, 132, NULL);
			al_draw_bitmap(lvl2_ladder, 805, 252, NULL);

			ALLEGRO_BITMAP *lvl2_closed_door = al_load_bitmap("closed_door_lvls.png");
			al_draw_bitmap(lvl2_closed_door, 1030, 252, NULL);

			ALLEGRO_BITMAP *lvl2_opened_door = al_load_bitmap("opened_door_lvls.png");

			ALLEGRO_BITMAP *lvl2_key = al_load_bitmap("key_lvls.png");
			al_draw_bitmap(lvl2_key, 1025, 80, NULL);

			ALLEGRO_BITMAP *lvl2_artifact = al_load_bitmap("artifact_lvls.png");
			al_draw_bitmap(lvl2_artifact, 1100, 320, NULL);

			ALLEGRO_BITMAP *lvl2_stone = al_load_bitmap("stone_lvls.png");
			al_draw_bitmap(lvl2_stone, 150, 372, NULL); // stone 1
			al_draw_bitmap(lvl2_stone, 325, 15, NULL); // stone 2

			ALLEGRO_BITMAP *lvl2_pickaxe = al_load_bitmap("pick_lvls.png");
			al_draw_bitmap(lvl2_pickaxe, 1060, 560, NULL);

			ALLEGRO_BITMAP *lvl2_closed_portal = al_load_bitmap("closed_portal_lvls.png");
			al_draw_bitmap(lvl2_closed_portal, 1080, 15, NULL);

			ALLEGRO_BITMAP *lvl2_destroyed_stone = al_load_bitmap("destroyed_stone_lvls.png");
			al_draw_bitmap(lvl2_destroyed_stone, 150, 372, NULL); // stone 1
			al_draw_bitmap(lvl2_destroyed_stone, 325, 15, NULL); // stone 2

			ALLEGRO_BITMAP *lvl2_opened_portal = al_load_bitmap("opened_portal_lvls.png");

			ALLEGRO_BITMAP *lvl2_bucket = al_load_bitmap("bucket_lvls.png");
			al_draw_bitmap(lvl2_bucket, 630, 560, NULL); //bucket 1
			al_draw_bitmap(lvl2_bucket, 85, 440, NULL); //bucket 2
			al_draw_bitmap(lvl2_bucket, 690, 200, NULL); //bucket 3

			ALLEGRO_BITMAP *lvl2_fire = al_load_bitmap("fire_lvls.png");
			al_draw_bitmap(lvl2_fire, 850, 372, NULL);
			al_draw_bitmap(lvl2_fire, 260, 252, NULL);
			al_draw_bitmap(lvl2_fire, 890, 15, NULL);

			ALLEGRO_BITMAP *lvl2_ash = al_load_bitmap("ash_lvls.png");

			int x_position = 65;
			int y_position = 555;
			bool left_key_locked = false;
			bool right_key_locked = false;
			bool up_key_locked = false;
			bool down_key_locked = false;
			bool champion_on_ladder = false;
			bool pick_owned = false;
			bool stone1_destroyed = false;
			bool stone2_destroyed = false;
			bool key_owned = false;
			bool door_opened = false;
			bool artifact_owned = false;
			bool champion_over_portal = false;
			bool bucket_owned = false;
			bool bucket1_exists = true;
			bool bucket2_exists = true;
			bool bucket3_exists = true;
			bool fire1_burning = true;
			bool fire2_burning = true;
			bool fire3_burning = true;
			bool end_of_lvl2 = false;

			while (!end_of_lvl2)
			{
				ALLEGRO_EVENT_QUEUE *lvl2_queue = al_create_event_queue();
				al_register_event_source(lvl2_queue, al_get_mouse_event_source());
				al_register_event_source(lvl2_queue, al_get_keyboard_event_source());

				ALLEGRO_EVENT lvl2_event;
				al_wait_for_event(lvl2_queue, &lvl2_event);

				if (lvl2_event.type == ALLEGRO_EVENT_MOUSE_AXES)
				{
					mouse_x = lvl2_event.mouse.x;
					mouse_y = lvl2_event.mouse.y;
				}

				if (lvl2_event.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					al_clear_to_color(al_map_rgb(0, 0, 0));
					al_draw_bitmap(lvl2_background, 0, 0, NULL);
					al_draw_bitmap(lvl2_ground_1, 65, 600, NULL);
					al_draw_bitmap(lvl2_ground_2, 65, 480, NULL);
					al_draw_bitmap(lvl2_ground_3, 65, 360, NULL);
					al_draw_bitmap(lvl2_ground_4, 65, 240, NULL);
					al_draw_bitmap(lvl2_ground_5, 65, 120, NULL);
					al_draw_bitmap(lvl2_ladder, 205, 492, NULL);
					al_draw_bitmap(lvl2_ladder, 505, 492, NULL);
					al_draw_bitmap(lvl2_ladder, 925, 492, NULL);
					al_draw_bitmap(lvl2_ladder, 365, 372, NULL);
					al_draw_bitmap(lvl2_ladder, 105, 252, NULL);
					al_draw_bitmap(lvl2_ladder, 105, 132, NULL);
					al_draw_bitmap(lvl2_ladder, 565, 132, NULL);
					al_draw_bitmap(lvl2_ladder, 805, 132, NULL);
					al_draw_bitmap(lvl2_ladder, 805, 252, NULL);
					if (bucket1_exists == true)
					{
						al_draw_bitmap(lvl2_bucket, 630, 560, NULL); //bucket 1
					}
					if (bucket2_exists == true)
					{
						al_draw_bitmap(lvl2_bucket, 85, 440, NULL); //bucket 2
					}
					if (bucket3_exists == true)
					{
						al_draw_bitmap(lvl2_bucket, 690, 200, NULL); //bucket 3
					}
					if (bucket_owned == true)
					{
						al_draw_bitmap(lvl2_bucket, 15, 50, NULL);
					}
					if (stone1_destroyed == false)
					{
						al_draw_bitmap(lvl2_stone, 150, 372, NULL);
					}
					else
					{
						al_draw_bitmap(lvl2_destroyed_stone, 150, 372, NULL);
					}
					if (stone2_destroyed == false)
					{
						al_draw_bitmap(lvl2_stone, 325, 15, NULL);
					}
					else
					{
						al_draw_bitmap(lvl2_destroyed_stone, 325, 15, NULL);
					}
					if (pick_owned == false)
					{
						al_draw_bitmap(lvl2_pickaxe, 1060, 560, NULL);
					}
					else
					{
						al_draw_bitmap(lvl2_pickaxe, 15, 15, NULL);
					}
					if (door_opened == false)
					{
						al_draw_bitmap(lvl2_closed_door, 1030, 252, NULL);
					}
					else
					{
						al_draw_bitmap(lvl2_opened_door, 1030, 252, NULL);
					}
					if (artifact_owned == false)
					{
						al_draw_bitmap(lvl2_artifact, 1100, 320, NULL);
					}
					else
					{
						al_draw_bitmap(lvl2_artifact, 105, 15, NULL);
					}
					if (key_owned == false)
					{
						al_draw_bitmap(lvl2_key, 1025, 80, NULL);
					}
					else
					{
						al_draw_bitmap(lvl2_key, 60, 15, NULL);
					}
					if (artifact_owned == false)
					{
						al_draw_bitmap(lvl2_closed_portal, 1080, 15, NULL);
					}
					else
					{
						al_draw_bitmap(lvl2_opened_portal, 1080, 15, NULL);
					}
					if (fire1_burning == true)
					{
						al_draw_bitmap(lvl2_fire, 850, 372, NULL);
					}
					else
					{
						al_draw_bitmap(lvl2_ash, 850, 372, NULL);
					}
					if (fire2_burning == true)
					{
						al_draw_bitmap(lvl2_fire, 260, 252, NULL);
					}
					else
					{
						al_draw_bitmap(lvl2_ash, 260, 252, NULL);
					}
					if (fire3_burning == true)
					{
						al_draw_bitmap(lvl2_fire, 890, 15, NULL);
					}
					else
					{
						al_draw_bitmap(lvl2_ash, 890, 15, NULL);
					}
					switch (lvl2_event.keyboard.keycode)
					{
					case ALLEGRO_KEY_LEFT:
					{
						printf("left\n");
						if ((left_key_locked == false) && (champion_on_ladder == false))
						{
							x_position = x_position - 20;
						}
						break;
					}
					case ALLEGRO_KEY_RIGHT:
					{
						printf("right\n");
						if ((right_key_locked == false) && (champion_on_ladder == false))
						{
							x_position = x_position + 20;
						}
						break;
					}
					case ALLEGRO_KEY_UP:
					{
						printf("up\n");
						if (up_key_locked == false)
						{
							y_position = y_position - 40;
						}
						break;
					}
					case ALLEGRO_KEY_DOWN:
					{
						printf("down\n");
						if (down_key_locked == false)
						{
							y_position = y_position + 40;
						}
						break;
					}
					}//switch
				}//if event key down
				al_draw_bitmap(lvl2_champion, x_position, y_position, NULL);

				//LEFT KEY LOCKED
				if (x_position == 65)
				{
					left_key_locked = true;
				}
				else if ((x_position == 465) && (y_position == 555))
				{
					left_key_locked = true; // przep
				}
				else if ((x_position == 905) && (y_position == 555))
				{
					left_key_locked = true; // przep
				}
				else if ((x_position == 905) && (y_position == 435)&&(fire1_burning==true))
				{
					left_key_locked = true; // fire1
				}
				else if ((x_position == 185) && (y_position == 435)&&(stone1_destroyed==false))
				{
					left_key_locked = true; // stone1
				}
				else if ((x_position == 325) && (y_position == 315)&&(fire2_burning==true))
				{
					left_key_locked = true; // fire2
				}
				else if ((x_position == 1065) && (y_position == 315)&&(door_opened==false))
				{
					left_key_locked = true; // door
				}
				else if ((x_position == 745) && (y_position == 315))
				{
					left_key_locked = true; // przep
				}
				else if ((x_position == 545) && (y_position == 195))
				{
					left_key_locked = true; // przep
				}
				else if ((x_position == 365) && (y_position == 75)&&(stone2_destroyed==false))
				{
					left_key_locked = true; // stone
				}
				else if ((x_position == 765) && (y_position == 75))
				{
					left_key_locked = true; // przep
				}
				else if ((x_position == 945) && (y_position == 75)&&(fire3_burning==true))
				{
					left_key_locked = true; // fire3
				}
				else
				{
					left_key_locked = false;
				}

				//RIGHT KEY LOCKED
				if (x_position == 1145)
				{
					right_key_locked = true;
				}
				else if ((x_position == 245) && (y_position == 555))
				{
					right_key_locked = true; //przep
				}
				else if ((x_position == 685) && (y_position == 555))
				{
					right_key_locked = true; //przep
				}
				else if ((x_position == 105) && (y_position == 435)&&(stone1_destroyed==false))
				{
					right_key_locked = true; //stone
				}
				else if ((x_position == 805) && (y_position == 435)&&(fire1_burning==true))
				{
					right_key_locked = true; //fire1
				}
				else if ((x_position == 985) && (y_position == 315)&&(door_opened==false))
				{
					right_key_locked = true; //door
				}
				else if ((x_position == 205) && (y_position == 315)&&(fire2_burning==true))
				{
					right_key_locked = true; //fire2
				}
				else if ((x_position == 165) && (y_position == 195))
				{
					right_key_locked = true; //przep
				}
				else if ((x_position == 845) && (y_position == 195))
				{
					right_key_locked = true; //przep
				}
				else if ((x_position == 265) && (y_position == 75)&&(stone2_destroyed==false))
				{
					right_key_locked = true; //stone
				}
				else if ((x_position == 605) && (y_position == 75))
				{
					right_key_locked = true; //przep
				}
				else if ((x_position == 845) && (y_position == 75)&&(fire3_burning==true))
				{
					right_key_locked = true; //fire3
				}
				else if ((x_position == 985) && (y_position == 435))
				{
					right_key_locked = true; //przep
				}
				else if ((x_position == 405) && (y_position == 315))
				{
					right_key_locked = true; //przep
				}
				else
				{
					right_key_locked = false;
				}

				//CHAMPION ON LADDER
				if ((y_position == 555) || (y_position == 435) || (y_position == 315) || (y_position == 195) || (y_position == 75))
				{
					champion_on_ladder = false;
				}
				else
				{
					champion_on_ladder = true;
				}

				//UP KEY LOCKED
				if ((x_position == 205) && (y_position > 435) && (y_position <= 555))
				{
				up_key_locked = false;
				}
				else if ((x_position == 505) && (y_position > 435) && (y_position <= 555))
				{
				up_key_locked = false;
				}
				else if ((x_position == 925) && (y_position > 435) && (y_position <= 555))
				{
				up_key_locked = false;
				}
				else if ((x_position == 365) && (y_position > 315) && (y_position <= 435))
				{
				up_key_locked = false;
				}
				else if ((x_position == 105) && (y_position > 195) && (y_position <= 315))
				{
				up_key_locked = false;
				}
				else if ((x_position == 805) && (y_position > 195) && (y_position <= 315))
				{
				up_key_locked = false;
				}
				else if ((x_position == 105) && (y_position > 75) && (y_position <= 195))
				{
				up_key_locked = false;
				}
				else if ((x_position == 565) && (y_position > 75) && (y_position <= 195))
				{
				up_key_locked = false;
				}
				else if ((x_position == 805) && (y_position > 75) && (y_position <= 195))
				{
				up_key_locked = false;
				}
				else
				{
				up_key_locked = true;
				}

				//DOWN KEY LOCKED
				if ((x_position == 205) && (y_position >= 435) && (y_position < 555))
				{
				down_key_locked = false;
				}
				else if ((x_position == 505) && (y_position >= 435) && (y_position < 555))
				{
				down_key_locked = false;
				}
				else if ((x_position == 925) && (y_position >= 435) && (y_position < 555))
				{
				down_key_locked = false;
				}
				else if ((x_position == 365) && (y_position >= 315) && (y_position < 435))
				{
				down_key_locked = false;
				}
				else if ((x_position == 105) && (y_position >= 195) && (y_position < 315))
				{
				down_key_locked = false;
				}
				else if ((x_position == 805) && (y_position >= 195) && (y_position < 315))
				{
				down_key_locked = false;
				}
				else if ((x_position == 105) && (y_position >= 75) && (y_position < 195))
				{
				down_key_locked = false;
				}
				else if ((x_position == 565) && (y_position >= 75) && (y_position < 195))
				{
				down_key_locked = false;
				}
				else if ((x_position == 805) && (y_position >= 75) && (y_position < 195))
				{
				down_key_locked = false;
				}
				else
				{
				down_key_locked = true;
				}

				//bucket1
				if ((bucket1_exists == true) && (x_position == 625) && (y_position == 555))
				{
				bucket1_exists = false;
				bucket_owned = true;
				}

				//fire1
				if ((x_position == 805) && (y_position == 435) && (bucket_owned == true))
				{
				fire1_burning = false;
				bucket_owned = false;
				}

				//pick owned
				if ((x_position == 1065) && (y_position == 555))
				{
				pick_owned = true;
				}

				//stone destroyed
				if ((x_position == 185) && (y_position == 435) && (pick_owned == true))
				{
					stone1_destroyed = true;
				}

				//bucket2
				if ((bucket2_exists == true) && (x_position == 85) && (y_position == 435))
				{
					bucket2_exists = false;
					bucket_owned = true;
				}

				//fire2
				if ((bucket_owned == true) && (x_position == 325) && (y_position == 315))
				{
					fire2_burning = false;
					bucket_owned = false;
				}

				//stone
				if ((pick_owned == true) && (x_position == 265) && (y_position == 75))
				{
					stone2_destroyed = true;
				}

				//bucket3
				if ((bucket3_exists == true) && (x_position == 685) && (y_position == 195))
				{
					bucket3_exists = false;
					bucket_owned = true;
				}

				//fire3
				if ((bucket_owned == true) && (x_position == 845) && (y_position == 75))
				{
					fire3_burning = false;
					bucket_owned = false;
				}

				//key owned
				if ((x_position == 1025) && (y_position == 75))
				{
					key_owned = true;
				}

				//door opened
				if ((key_owned == true) && (x_position == 985) && (y_position == 315))
				{
					door_opened = true;
				}

				//artifact owned
				if ((x_position == 1085) && (y_position == 315))
				{
					artifact_owned = true;
				}

				//champion over portal
				if ((artifact_owned == true) && (x_position == 1085) && (y_position == 75))
				{
					champion_over_portal = true;
				}

				if (champion_over_portal == true)
				{
					end_of_lvl2 = true;
				}

				printf("x: %d\n", mouse_x);
				printf("y: %d\n", mouse_y);
				printf("x_position: %d\n", x_position);
				printf("y_position: %d\n", y_position);
				al_flip_display();
			}//while end of lvl2 = false
			al_destroy_bitmap(lvl2_artifact);
			al_destroy_bitmap(lvl2_background);
			al_destroy_bitmap(lvl2_ash);
			al_destroy_bitmap(lvl2_bucket);
			al_destroy_bitmap(lvl2_fire);
			al_destroy_bitmap(lvl2_ground_1);
			al_destroy_bitmap(lvl2_ground_2);
			al_destroy_bitmap(lvl2_ground_3);
			al_destroy_bitmap(lvl2_ground_4);
			al_destroy_bitmap(lvl2_ground_5);
			al_destroy_bitmap(lvl2_champion);
			al_destroy_bitmap(lvl2_closed_door);
			al_destroy_bitmap(lvl2_closed_portal);
			al_destroy_bitmap(lvl2_destroyed_stone);
			al_destroy_bitmap(lvl2_stone);
			al_destroy_bitmap(lvl2_key);
			al_destroy_bitmap(lvl2_ladder);
			al_destroy_bitmap(lvl2_opened_door);
			al_destroy_bitmap(lvl2_opened_portal);
			al_destroy_bitmap(lvl2_pickaxe);
			al_destroy_display(lvl2_display);
		} // click lvl2 =true

		if (click_lvl3 == true)
		{
			al_destroy_bitmap(new_game_choose_menu);
			al_destroy_font(font_new_game_choose_menu);
			al_destroy_display(new_game_choose_display);

			ALLEGRO_DISPLAY *lvl3_display = al_create_display(lvls_screen_w, lvls_screen_h);
			if (!lvl3_display)
			{
				printf("Failed to create lvl 3 display!\n");
				return 1;
			}

			al_clear_to_color(al_map_rgb(0, 0, 0));

			ALLEGRO_BITMAP *lvl3_background = al_load_bitmap("tut_background.png");
			al_draw_bitmap(lvl3_background, 0, 0, NULL);
			
			//******************ADD A COMMIT!********************






			int x_position = 65;
			int y_position = 555;
			bool left_key_locked = false;
			bool right_key_locked = false;
			bool up_key_locked = false;
			bool down_key_locked = false;
			bool champion_on_ladder = false;
			bool pick_owned = false;
		//	bool stone1_destroyed = false;
		//	bool stone2_destroyed = false;
			bool key_owned = false;
			bool door_opened = false;
			bool artifact_owned = false;
			bool champion_over_portal = false;
			bool bucket_owned = false;
		//	bool bucket1_exists = true;
		//	bool bucket2_exists = true;
		//	bool bucket3_exists = true;
		//	bool fire1_burning = true;
		//	bool fire2_burning = true;
		//	bool fire3_burning = true;
			bool end_of_lvl3 = false;

			while (!end_of_lvl3)
			{
				ALLEGRO_EVENT_QUEUE *lvl3_queue = al_create_event_queue();
				al_register_event_source(lvl3_queue, al_get_keyboard_event_source());
				al_register_event_source(lvl3_queue, al_get_mouse_event_source());

				ALLEGRO_EVENT lvl3_event;
				al_wait_for_event(lvl3_queue, &lvl3_event);

				if (lvl3_event.type == ALLEGRO_EVENT_MOUSE_AXES)
				{
					mouse_x = lvl3_event.mouse.x;
					mouse_y = lvl3_event.mouse.y;
				}
			
				if (lvl3_event.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					al_clear_to_color(al_map_rgb(0, 0, 0));




				} //event key down
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
				printf("x: %d\n", mouse_x);
				printf("y: %d\n", mouse_y);
				printf("x_position: %d\n", x_position);
				printf("y_position: %d\n", y_position);
				al_flip_display();
			}//while end of lvl3 = false
		}//click lvl3 = true
	} // click ng=true
	system("pause");
	return 0;
}