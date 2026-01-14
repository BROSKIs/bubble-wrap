#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>

int main()
{
    bn::core::init();

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