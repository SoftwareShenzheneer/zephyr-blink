#include <zephyr/kernel.h>
#include <zephyr/drivers/led_strip.h>
#include <zephyr/sys/printk.h>

#define STRIP_NODE DT_ALIAS(led_strip)

static const struct device *strip = DEVICE_DT_GET(STRIP_NODE);

int main(void) {
    printk("We're starting ..\r\n");

    if (!device_is_ready(strip)) {
        printk("LED strip device not ready\n");
        return 0;
    }

    struct led_rgb color_off   = { 0,  0,  0};
    struct led_rgb color_red   = { 0, 10,  0};
    struct led_rgb color_green = {10,  0,  0};
    struct led_rgb color_blue  = { 0,  0, 10};

    int state = 0;

    while (true) {
        switch (state) {
        case 0:
            led_strip_update_rgb(strip, &color_red, 1);
            printk("RED\n");
            break;
        case 1:
            led_strip_update_rgb(strip, &color_green, 1);
            printk("GREEN\n");
            break;
        case 2:
            led_strip_update_rgb(strip, &color_blue, 1);
            printk("BLUE\n");
            break;
        default:
            led_strip_update_rgb(strip, &color_off, 1);
            printk("OFF\n");
            break;
        }

        state = (state + 1) % 4;
        k_msleep(500);
    }
}
