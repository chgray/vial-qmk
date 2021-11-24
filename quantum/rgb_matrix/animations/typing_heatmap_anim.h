#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)

#define RGB_MATRIX_EFFECT_TYPING_HEATMAP
RGB_MATRIX_EFFECT(TYPING_HEATMAP)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#        ifndef RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS
#            define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 25
#        endif

void process_rgb_matrix_typing_heatmap(uint8_t row, uint8_t col) {

    uint8_t myLed = g_led_config.matrix_co[row][col];
    uint8_t myX = g_led_config.point[myLed].x;
    uint8_t myY = g_led_config.point[myLed].y;

    for(uint8_t ledIdx = 0; ledIdx < DRIVER_LED_TOTAL; ++ledIdx)
    {
        int32_t dx   = g_led_config.point[ledIdx].x - myX;
        int32_t dy   = g_led_config.point[ledIdx].y - myY;
        uint8_t dist = sqrt16(dx * dx + dy * dy);

        if (!HAS_ANY_FLAGS(g_led_config.flags[ledIdx], (LED_FLAG_KEYLIGHT | LED_FLAG_UNDERGLOW)))
            continue;

        if(dist > 30)
            continue;

        int32_t amt = ((-dist)/20) + 16;
        uprintf("  LED:%d  x=%d, y=%d, dist=%d,  amt=%d\r\n", ledIdx, g_led_config.point[ledIdx].x,g_led_config.point[ledIdx].y, dist,amt);
        g_rgb_led_frame_buffer[ledIdx] = qadd8(g_rgb_led_frame_buffer[ledIdx], amt);
    }
}

// A timer to track the last time we decremented all heatmap values.
static uint16_t heatmap_decrease_timer;
// Whether we should decrement the heatmap values during the next update.
static bool decrease_heatmap_values;

bool TYPING_HEATMAP(effect_params_t* params) {

    // Modified version of RGB_MATRIX_USE_LIMITS to work off of matrix row / col size
    uint8_t led_min = RGB_MATRIX_LED_PROCESS_LIMIT * params->iter;
    uint8_t led_max = led_min + RGB_MATRIX_LED_PROCESS_LIMIT;
    if (led_max > sizeof(g_rgb_led_frame_buffer)) led_max = sizeof(g_rgb_led_frame_buffer);

    if (params->init) {
        rgb_matrix_set_color_all(0, 0, 0);
        memset(g_rgb_led_frame_buffer, 0, sizeof g_rgb_led_frame_buffer);
    }

    // The heatmap animation might run in several iterations depending on
    // `RGB_MATRIX_LED_PROCESS_LIMIT`, therefore we only want to update the
    // timer when the animation starts.
    if (params->iter == 0) {
        decrease_heatmap_values = timer_elapsed(heatmap_decrease_timer) >= RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS;

        // Restart the timer if we are going to decrease the heatmap this frame.
        if (decrease_heatmap_values) {
            heatmap_decrease_timer = timer_read();
        }
    }

    // Render heatmap & decrease
    for (int i = led_min; i < led_max; i++) {
         uint8_t val = g_rgb_led_frame_buffer[i];

         //if(val != 0)
         //   uprintf("LED: %d=%d\r\n", i, val);

        // set the pixel colour
        if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) continue;

        HSV hsv = {170 - qsub8(val, 85), rgb_matrix_config.hsv.s, scale8((qadd8(170, val) - 170) * 3, rgb_matrix_config.hsv.v)};
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);

        //uprintf("SPEED: %d\r\n", rgblight_get_speed());
//gb_matrix_config.speed
        if (decrease_heatmap_values) {
            uint8_t s = rgblight_get_speed()/20;
            if(s <= 1)
                s = 1;
            g_rgb_led_frame_buffer[i] = qsub8(val, s);
        }
    }

    return led_max < sizeof(g_rgb_led_frame_buffer);
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && !defined(DISABLE_RGB_MATRIX_TYPING_HEATMAP)
