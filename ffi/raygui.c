#include <lean/lean.h>
#include "include/raylib_lean.h"

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

LEAN_EXPORT lean_obj_res lean_raygui__GuiEnable(lean_obj_arg world) {
    GuiEnable();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiDisable(lean_obj_arg world) {
    GuiDisable();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiLock(lean_obj_arg world) {
    GuiLock();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiUnlock(lean_obj_arg world) {
    GuiUnlock();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiIsLocked(lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(GuiIsLocked()));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiSetAlpha(float alpha, lean_obj_arg world) {
    GuiSetAlpha(alpha);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiSetState(uint32_t state, lean_obj_arg world) {
    GuiSetState(state);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiGetState(lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GuiGetState()));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiSetFont(b_lean_obj_arg font, lean_obj_arg world) {
    GuiSetFont(lean_raylib_Font_fromRepr(font)->font);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiGetFont(lean_obj_arg ctx, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Font_box(GuiGetFont(), ctx));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiSetStyle(uint32_t control, uint32_t property, uint32_t value, lean_obj_arg world) {
    GuiSetStyle(control, property, value);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiGetStyle(uint32_t control, uint32_t property, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GuiGetStyle(control, property)));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiLoadStyle(b_lean_obj_arg fileName, lean_obj_arg world) {
    GuiLoadStyle(lean_string_cstr(fileName));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiLoadStyleDefault(lean_obj_arg world) {
    GuiLoadStyleDefault();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiEnableTooltip(lean_obj_arg world) {
    GuiEnableTooltip();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiDisableTooltip(lean_obj_arg world) {
    GuiDisableTooltip();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiSetTooltip(b_lean_obj_arg tooltip, lean_obj_arg world) {
    GuiSetTooltip(lean_string_cstr(tooltip));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiIconText(uint8_t iconId, b_lean_obj_arg text, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_mk_string(GuiIconText(iconId, lean_string_cstr(text))));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiSetIconScale(uint32_t scale, lean_obj_arg world) {
    GuiSetIconScale(scale);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiLoadIcons(b_lean_obj_arg fileName, lean_obj_arg world) {
    GuiLoadIcons(lean_string_cstr(fileName), false);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiDrawIcon(uint8_t iconId, uint32_t posX, uint32_t posY, uint32_t pixelSize, uint32_t color, lean_obj_arg world) {
    GuiDrawIcon(iconId, posX, posY, pixelSize, lean_raylib_Color_fromRepr(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiWindowBox(b_lean_obj_arg bounds, b_lean_obj_arg title) {
    return lean_io_result_mk_ok(lean_box(
        GuiWindowBox(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(title))
    ));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiGroupBox(b_lean_obj_arg bounds, b_lean_obj_arg text, lean_obj_arg world) {
    GuiGroupBox(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiLine(b_lean_obj_arg bounds, b_lean_obj_arg text, lean_obj_arg world) {
    GuiLine(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiPanel(b_lean_obj_arg bounds, b_lean_obj_arg text, lean_obj_arg world) {
    GuiPanel(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiTabBar(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t active, lean_obj_arg world) {
    size_t count = lean_array_size(text);
    const char** text_ = malloc(count * sizeof(const char*));
    for (size_t i = 0; i < count; ++i) {
        text_[i] = lean_string_cstr(lean_array_get_core(text, i));
    }
    int active_ = active;
    GuiTabBar(lean_raylib_Rectangle_fromRepr(bounds), text_, count, &active_);
    free(text_);
    return lean_io_result_mk_ok(active_ < 0 ? lean_mk_option_none() : lean_mk_option_some(lean_box_uint32(active_)));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiScrollPanel(b_lean_obj_arg bounds, b_lean_obj_arg text, b_lean_obj_arg content, lean_obj_arg scroll, lean_obj_arg view, lean_obj_arg world) {
    Vector2 scroll_ = lean_raylib_Vector2_fromRepr(scroll);
    Rectangle view_ = lean_raylib_Rectangle_fromRepr(view);
    GuiScrollPanel(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), lean_raylib_Rectangle_fromRepr(content), &scroll_, &view_);
    if (lean_is_exclusive(scroll)) {
        lean_dec_ref(scroll);
        scroll = lean_raylib_Vector2_box(scroll_);
    }
    else {
        lean_raylib_Vector2_set(scroll, scroll_);
    }
    if (lean_is_exclusive(view)) {
        lean_dec_ref(view);
        view = lean_raylib_Rectangle_box(view_);
    }
    else {
        lean_raylib_Rectangle_set(view, view_);
    }
    return lean_io_result_mk_ok(lean_mk_tuple2(scroll, view));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiLabel(b_lean_obj_arg bounds, b_lean_obj_arg text, lean_obj_arg world) {
    GuiLabel(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiButton(b_lean_obj_arg bounds, b_lean_obj_arg text, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(
        GuiButton(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text))
    ));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiLabelButton(b_lean_obj_arg bounds, b_lean_obj_arg text, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(GuiLabelButton(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text))));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiToggle(b_lean_obj_arg bounds, b_lean_obj_arg text, uint8_t active, lean_obj_arg world) {
    bool active_ = active;
    GuiToggle(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &active_);
    return lean_io_result_mk_ok(lean_box(active_));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiToggleGroup(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t active, lean_obj_arg world) {
    int active_ = active;
    GuiToggleGroup(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &active_);
    return lean_io_result_mk_ok(lean_box_uint32(active_));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiToggleSlider(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t active, lean_obj_arg world) {
    int active_ = active;
    int result = GuiToggleSlider(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &active_);
    return lean_io_result_mk_ok(lean_mk_tuple2(lean_box(result), lean_box_uint32(active_)));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiCheckBox(b_lean_obj_arg bounds, b_lean_obj_arg text, uint8_t checked, lean_obj_arg world) {
    bool checked_ = checked;
    GuiCheckBox(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &checked_);
    return lean_io_result_mk_ok(lean_box(checked_));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiComboBox(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t active, lean_obj_arg world) {
    int active_ = active;
    GuiComboBox(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &active_);
    return lean_io_result_mk_ok(lean_box_uint32(active_));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiDropdownBox(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t active, uint8_t editMode, lean_obj_arg world) {
    int active_ = active;
    int result = GuiDropdownBox(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &active_, editMode);
    return lean_io_result_mk_ok(lean_mk_tuple2(lean_box(result), lean_box_uint32(active_)));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiSpinner(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t value, uint32_t minValue, uint32_t maxValue, uint8_t editMode, lean_obj_arg world) {
    int value_ = value;
    int result = GuiSpinner(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &value_, minValue, maxValue, editMode);
    return lean_io_result_mk_ok(lean_mk_tuple2(lean_box(result), lean_box_uint32(value_)));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiValueBox(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t value, uint32_t minValue, uint32_t maxValue, uint8_t editMode, lean_obj_arg world) {
    int value_ = value;
    int result = GuiValueBox(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &value_, minValue, maxValue, editMode);
    return lean_io_result_mk_ok(lean_mk_tuple2(lean_box(result), lean_box_uint32(value_)));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiTextBox(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t textSize, uint8_t editMode, lean_obj_arg world) {
    char* text_ = malloc(textSize + 1);
    strncpy(text_, lean_string_cstr(text), textSize);
    text_[textSize] = '\0';
    int result = GuiTextBox(lean_raylib_Rectangle_fromRepr(bounds), text_, textSize, editMode);
    lean_object* res = lean_mk_tuple2(lean_box(result), lean_mk_string(text_));
    free(text_);
    return lean_io_result_mk_ok(res);
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiSlider(b_lean_obj_arg bounds, b_lean_obj_arg textLeft, b_lean_obj_arg textRight, float value, float minValue, float maxValue, lean_obj_arg world) {
    GuiSlider(
        lean_raylib_Rectangle_fromRepr(bounds),
        lean_string_cstr(textLeft),
        lean_string_cstr(textRight),
        &value,
        minValue,
        maxValue
    );
    return lean_io_result_mk_ok(lean_box_float32(value));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiSliderBar(b_lean_obj_arg bounds, b_lean_obj_arg textLeft, b_lean_obj_arg textRight, float value, float minValue, float maxValue, lean_obj_arg world) {
    GuiSliderBar(
        lean_raylib_Rectangle_fromRepr(bounds),
        lean_string_cstr(textLeft),
        lean_string_cstr(textRight),
        &value,
        minValue,
        maxValue
    );
    return lean_io_result_mk_ok(lean_box_float32(value));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiProgressBar(b_lean_obj_arg bounds, b_lean_obj_arg textLeft, b_lean_obj_arg textRight, float value, float minValue, float maxValue, lean_obj_arg world) {
    GuiProgressBar(
        lean_raylib_Rectangle_fromRepr(bounds),
        lean_string_cstr(textLeft),
        lean_string_cstr(textRight),
        &value,
        minValue,
        maxValue
    );
    return lean_io_result_mk_ok(lean_box_float32(value));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiStatusBar(b_lean_obj_arg bounds, b_lean_obj_arg text, lean_obj_arg world) {
    GuiStatusBar(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiDummyRec(b_lean_obj_arg bounds, b_lean_obj_arg text, lean_obj_arg world) {
    GuiDummyRec(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiGrid(b_lean_obj_arg bounds, b_lean_obj_arg text, float spacing, uint32_t subdivs, lean_obj_arg mouseCell, lean_obj_arg world) {
    Vector2 mouseCell_ = lean_raylib_Vector2_fromRepr(mouseCell);
    GuiGrid(
        lean_raylib_Rectangle_fromRepr(bounds),
        lean_string_cstr(text),
        spacing,
        subdivs,
        &mouseCell_
    );
    if (lean_is_exclusive(mouseCell)) {
        lean_dec_ref(mouseCell);
        mouseCell = lean_raylib_Vector2_box(mouseCell_);
    }
    else {
        lean_raylib_Vector2_set(mouseCell, mouseCell_);
    }
    return lean_io_result_mk_ok(mouseCell);
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiListView(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t scrollIndex, uint32_t active, lean_obj_arg world) {
    int scrollIndex_ = scrollIndex;
    int active_ = active;
    GuiListView(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &scrollIndex_, &active_);
    return lean_io_result_mk_ok(lean_mk_tuple2(lean_box_uint32(scrollIndex_), lean_box_uint32(active_)));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiListViewEx(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t scrollIndex, uint32_t active, uint32_t focus, lean_obj_arg world) {
    size_t count = lean_array_size(text);
    const char** text_ = malloc(count * sizeof(const char*));
    for (size_t i = 0; i < count; ++i) {
        text_[i] = lean_string_cstr(lean_array_get_core(text, i));
    }
    int scrollIndex_ = scrollIndex;
    int active_ = active;
    int focus_ = focus;
    GuiListViewEx(lean_raylib_Rectangle_fromRepr(bounds), text_, count, &scrollIndex_, &active_, &focus_);
    free(text_);
    return lean_io_result_mk_ok(lean_mk_tuple3(lean_box(scrollIndex_), lean_box_uint32(active_), lean_box_uint32(focus_)));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiMessageBox(b_lean_obj_arg bounds, b_lean_obj_arg title, b_lean_obj_arg message, b_lean_obj_arg buttons, lean_obj_arg world) {
    int btn = GuiMessageBox(
        lean_raylib_Rectangle_fromRepr(bounds),
        lean_string_cstr(title),
        lean_string_cstr(message),
        lean_string_cstr(buttons)
    );
    return lean_io_result_mk_ok(btn < 0 ? lean_mk_option_none() : lean_mk_option_some(lean_box_uint32(btn)));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiTextInputBox(b_lean_obj_arg bounds, b_lean_obj_arg title, b_lean_obj_arg message, b_lean_obj_arg buttons, b_lean_obj_arg text, uint32_t textMaxSize, uint8_t secretViewActive, lean_obj_arg world) {
    char* text_ = malloc(textMaxSize + 1);
    strncpy(text_, lean_string_cstr(text), textMaxSize);
    text_[textMaxSize] = '\0';
    bool secretViewActive_ = secretViewActive;
    int btn = GuiTextInputBox(
        lean_raylib_Rectangle_fromRepr(bounds),
        lean_string_cstr(title),
        lean_string_cstr(message),
        lean_string_cstr(buttons),
        text_,
        textMaxSize,
        &secretViewActive_
    );
    lean_object* btn_opt = btn < 0 ? lean_mk_option_none() : lean_mk_option_some(lean_box_uint32(btn));
    return lean_io_result_mk_ok(lean_mk_tuple3(btn_opt, lean_mk_string(text_), lean_box(secretViewActive_)));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiColorPicker(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t color, lean_obj_arg world) {
    Color color_ = lean_raylib_Color_fromRepr(color);
    GuiColorPicker(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &color_);
    return lean_io_result_mk_ok(lean_raylib_Color_box(color_));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiColorPanel(b_lean_obj_arg bounds, b_lean_obj_arg text, uint32_t color, lean_obj_arg world) {
    Color color_ = lean_raylib_Color_fromRepr(color);
    GuiColorPanel(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &color_);
    return lean_io_result_mk_ok(lean_raylib_Color_box(color_));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiColorBarAlpha(b_lean_obj_arg bounds, b_lean_obj_arg text, float alpha, lean_obj_arg world) {
    GuiColorBarAlpha(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &alpha);
    return lean_io_result_mk_ok(lean_box_float32(alpha));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiColorBarHue(b_lean_obj_arg bounds, b_lean_obj_arg text, float value, lean_obj_arg world) {
    GuiColorBarHue(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &value);
    return lean_io_result_mk_ok(lean_box_float32(value));
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiColorPickerHSV(b_lean_obj_arg bounds, b_lean_obj_arg text, lean_obj_arg colorHsv, lean_obj_arg world) {
    Vector3 colorHsv_ = lean_raylib_Vector3_fromRepr(colorHsv);
    GuiColorPanelHSV(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &colorHsv_);
    if (lean_is_exclusive(colorHsv)) {
        lean_dec_ref(colorHsv);
        colorHsv = lean_raylib_Vector3_box(colorHsv_);
    }
    else {
        lean_raylib_Vector3_set(colorHsv, colorHsv_);
    }
    return lean_io_result_mk_ok(colorHsv);
}

LEAN_EXPORT lean_obj_res lean_raygui__GuiColorPanelHSV(b_lean_obj_arg bounds, b_lean_obj_arg text, lean_obj_arg colorHsv, lean_obj_arg world) {
    Vector3 colorHsv_ = lean_raylib_Vector3_fromRepr(colorHsv);
    GuiColorPanelHSV(lean_raylib_Rectangle_fromRepr(bounds), lean_string_cstr(text), &colorHsv_);
    if (lean_is_exclusive(colorHsv)) {
        lean_dec_ref(colorHsv);
        colorHsv = lean_raylib_Vector3_box(colorHsv_);
    }
    else {
        lean_raylib_Vector3_set(colorHsv, colorHsv_);
    }
    return lean_io_result_mk_ok(colorHsv);
}
