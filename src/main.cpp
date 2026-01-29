#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_vector.h>

int main()
{
    bn::core::init();

    bn::vector<bn::sprite_ptr, 90> circles = {};
    for (int y = -40; y <= 40; y += 10)
    {
        for (int x = -40; x <= 40; x += 10)
        {
            circles.push_back(bn::sprite_items::dot.create_sprite(x, y));
        }
    }

    for (int i = 0; i < circles.size(); i++)
    {
        if (i == 0 || i == 8 || i == 72 || i == 80)
        {
            circles[i].set_scale(1.8);
        }
        if (i < 8 && i > 0 || i < 80 && i > 72)
        {
            circles[i].set_vertical_scale(0.6);
            circles[i].set_horizontal_scale(1.5);
        }
        if (((i - 8) % 9 == 0 || i % 9 == 0) && i != 0 && i != 72 && i != 8 && i != 80)
        {
            circles[i].set_vertical_scale(1.5);
            circles[i].set_horizontal_scale(0.6);
        }
    }

    // circles[0].set_scale(1.8);
    // circles[1].set_scale(0.5);
    // circles[8].set_scale(1.8);
    // circles[9].set_horizontal_scale(0.6);

    bn::backdrop::set_color(bn::color(20, 20, 31));

    while (true)
    {

        if (bn::keypad::a_pressed())
        {
            if (bn::backdrop::color() == bn::color(31, 21, 22))
            {
                bn::backdrop::set_color(bn::color(20, 20, 31));
            }
            else
            {
                bn::backdrop::set_color(bn::color(31, 21, 22));
            }
        }
        if (bn::keypad::b_pressed())
        {
            if (bn::backdrop::color() == bn::color(21, 31, 23))
            {
                bn::backdrop::set_color(bn::color(20, 20, 31));
            }
            else
            {
                bn::backdrop::set_color(bn::color(21, 31, 23));
            }
        }

        bn::core::update();
    }
}