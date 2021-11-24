#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)


//uint8_t g_rgb_led_frame_buffer[DRIVER_LED_TOTAL] = {{0}};

#define RGB_MATRIX_EFFECT_TYPING_HEATMAP
RGB_MATRIX_EFFECT(TYPING_HEATMAP)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#        ifndef RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS
#            define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 25
#        endif

void process_rgb_matrix_typing_heatmap(uint8_t row, uint8_t col) {
    //uint8_t m_row = row - 1;
    //uint8_t p_row = row + 1;
    //uint8_t m_col = col - 1;
    //uint8_t p_col = col + 1;

    uprintf("Typing Heatmap : %d, %d = %d\r\n", row, col, g_led_config.matrix_co[row][col]);

    uint8_t myLed = g_led_config.matrix_co[row][col];
    uint8_t myX = g_led_config.point[myLed].x;
    uint8_t myY = g_led_config.point[myLed].y;

    for(uint8_t mRow = 0; mRow < MATRIX_ROWS; ++mRow)
    {
        for(uint8_t mCol = 0; mCol < MATRIX_COLS; ++mCol)
        {
            int8_t ledIdx = g_led_config.matrix_co[mRow][mCol];
            int16_t dx   = g_led_config.point[ledIdx].x - myX;
            int16_t dy   = g_led_config.point[ledIdx].y - myY;
            uint8_t dist = sqrt16(dx * dx + dy * dy);

             if (!HAS_ANY_FLAGS(g_led_config.flags[ledIdx], (LED_FLAG_KEYLIGHT | LED_FLAG_UNDERGLOW)))
                continue;

            uprintf("  LED:%d  mRow=%d, mCol=%d, dist=%d,  flag=%d\r\n", ledIdx, mRow, mCol, dist);

            if(dist < 20)
            {
                g_rgb_frame_buffer[mRow][mCol] = qadd8(g_rgb_frame_buffer[mRow][mCol], 32);
            }
        }
    }


    // Modified version of RGB_MATRIX_USE_LIMITS to work off of matrix row / col size
    /*uint8_t led_min = RGB_MATRIX_LED_PROCESS_LIMIT * params->iter;
    uint8_t led_max = led_min + RGB_MATRIX_LED_PROCESS_LIMIT;
    if (led_max > sizeof(g_rgb_frame_buffer)) led_max = sizeof(g_rgb_frame_buffer);

    for (int i = led_min; i < led_max; i++) {
        uint8_t row = i % MATRIX_ROWS;
        uint8_t col = i / MATRIX_ROWS;
        uint8_t val = g_rgb_frame_buffer[row][col];

        // set the pixel colour
        uint8_t led[LED_HITS_TO_REMEMBER];
        uint8_t led_count = rgb_matrix_map_row_column_to_led(row, col, led);
        for (uint8_t j = 0; j < led_count; ++j) {
            if (!HAS_ANY_FLAGS(g_led_config.flags[led[j]], params->flags)) continue;

            HSV hsv = {170 - qsub8(val, 85), rgb_matrix_config.hsv.s, scale8((qadd8(170, val) - 170) * 3, rgb_matrix_config.hsv.v)};
            RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(led[j], rgb.r, rgb.g, rgb.b);
        }

        if (decrease_heatmap_values) {
            g_rgb_frame_buffer[row][col] = qsub8(val, 1);
        }
    }

*/

    //row = 5;
    //col = 5;
/*
    if (m_col < col)
        g_rgb_frame_buffer[row][m_col] = qadd8(g_rgb_frame_buffer[row][m_col], 16);
*/
    g_rgb_frame_buffer[row][col] = qadd8(g_rgb_frame_buffer[row][col], 32);
/*
    if (p_col < MATRIX_COLS)
        g_rgb_frame_buffer[row][p_col] = qadd8(g_rgb_frame_buffer[row][p_col], 16);

    if (p_row < MATRIX_ROWS) {
        if (m_col < col) g_rgb_frame_buffer[p_row][m_col] = qadd8(g_rgb_frame_buffer[p_row][m_col], 13);
        g_rgb_frame_buffer[p_row][col] = qadd8(g_rgb_frame_buffer[p_row][col], 16);
        if (p_col < MATRIX_COLS) g_rgb_frame_buffer[p_row][p_col] = qadd8(g_rgb_frame_buffer[p_row][p_col], 13);
    }

    if (m_row < row) {
        if (m_col < col) g_rgb_frame_buffer[m_row][m_col] = qadd8(g_rgb_frame_buffer[m_row][m_col], 13);
        g_rgb_frame_buffer[m_row][col] = qadd8(g_rgb_frame_buffer[m_row][col], 16);
        if (p_col < MATRIX_COLS) g_rgb_frame_buffer[m_row][p_col] = qadd8(g_rgb_frame_buffer[m_row][p_col], 13);
    }*/
}

// A timer to track the last time we decremented all heatmap values.
static uint16_t heatmap_decrease_timer;
// Whether we should decrement the heatmap values during the next update.
static bool decrease_heatmap_values;

bool TYPING_HEATMAP(effect_params_t* params) {

    //uprintf("HEATMAP CALLED\r\n");


    // Modified version of RGB_MATRIX_USE_LIMITS to work off of matrix row / col size
    uint8_t led_min = RGB_MATRIX_LED_PROCESS_LIMIT * params->iter;
    uint8_t led_max = led_min + RGB_MATRIX_LED_PROCESS_LIMIT;
    if (led_max > sizeof(g_rgb_frame_buffer)) led_max = sizeof(g_rgb_frame_buffer);

    if (params->init) {
        rgb_matrix_set_color_all(0, 0, 0);
        memset(g_rgb_frame_buffer, 0, sizeof g_rgb_frame_buffer);
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
        uint8_t row = i % MATRIX_ROWS;
        uint8_t col = i / MATRIX_ROWS;
        uint8_t val = g_rgb_frame_buffer[row][col];

        // set the pixel colour
        uint8_t led[LED_HITS_TO_REMEMBER];
        uint8_t led_count = rgb_matrix_map_row_column_to_led(row, col, led);
        for (uint8_t j = 0; j < led_count; ++j) {
            if (!HAS_ANY_FLAGS(g_led_config.flags[led[j]], params->flags)) continue;

            HSV hsv = {170 - qsub8(val, 85), rgb_matrix_config.hsv.s, scale8((qadd8(170, val) - 170) * 3, rgb_matrix_config.hsv.v)};
            RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(led[j], rgb.r, rgb.g, rgb.b);
        }

        if (decrease_heatmap_values) {
            g_rgb_frame_buffer[row][col] = qsub8(val, 1);
        }
    }

    return led_max < sizeof(g_rgb_frame_buffer);
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && !defined(DISABLE_RGB_MATRIX_TYPING_HEATMAP)
