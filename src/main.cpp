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

    bn::vector<bn::sprite_ptr, 300> circles = {};
    for (int y = -40; y <= 40; y += 10)
    {
        for (int x = -40; x <= 40; x += 10)
        {
            circles.push_back(bn::sprite_items::dot.create_sprite(x, y));
        }
    }

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