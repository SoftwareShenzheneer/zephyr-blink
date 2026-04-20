using default app.overlay:
west build -p always -b esp32c6_devkitc/esp32c6/hpcore

using custom overlay:
west build -p always -b esp32c6_devkitc/esp32c6/hpcore -- -DDTC_OVERLAY_FILE="C:/Users/Fujikon/Desktop/zephyr-test/zephyrproject/zephyr/samples/basic/blinky/boards/esp32c6_devkitc.overlay"
